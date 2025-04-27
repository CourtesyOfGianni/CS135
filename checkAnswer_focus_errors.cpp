#include <string>
#include <sstream>
#include <vector>
#include <algorithm> // for swap()

using namespace std;

// Helper to split string by delimiter
vector<string> extract_type(const string& type_str) {
    vector<string> types;
    stringstream ss(type_str);
    string item;
    while (getline(ss, item, ';')) {
        // Remove leading space
        if (!item.empty() && item[0] == ' ') item = item.substr(1);
        types.push_back(item);
    }
    return types;
}

// Returns true if any item in type_to_focus exists in curr_type
bool type_related(string type_to_focus, string curr_type) {
    vector<string> focus_items = extract_type(type_to_focus);
    for (const string& item : focus_items) {
        if (curr_type.find(item) != string::npos) {
            return true;
        }
    }
    return false;
}

struct Question {
    string type;
    // Assume other fields like text, answer etc. exist but are ignored here
};

void reorder(Question ques[], int size, int idx) {
    string focus_type = ques[idx].type;

    // Step i: find first question after idx that is NOT related
    int first_unrelated = -1;
    for (int i = idx + 1; i < size; ++i) {
        if (!type_related(focus_type, ques[i].type)) {
            first_unrelated = i;
            break;
        }
    }
    if (first_unrelated == -1) return; // all remaining are related

    // Step ii: find last question (from end) that IS related
    int last_related = -1;
    for (int i = size - 1; i > idx; --i) {
        if (type_related(focus_type, ques[i].type)) {
            last_related = i;
            break;
        }
    }
    if (last_related == -1 || last_related <= first_unrelated) return;

    // Step iii: swap first unrelated with last related
    swap(ques[first_unrelated], ques[last_related]);

    // Step iv & v: move remaining related questions closer
    for (int i = idx + 1; i < size - 1; ++i) {
        if (!type_related(focus_type, ques[i].type)) {
            for (int j = i + 1; j < size; ++j) {
                if (type_related(focus_type, ques[j].type)) {
                    swap(ques[i], ques[j]);
                    break;
                }
            }
        }
    }
}