#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Define the Question struct as specified
struct Question {
    string text;      // question text
    string answer;
    string explanation;
    string version;
    string type;
    string label;
};

// Function to read questions from a file and add them to the array
void read_file(string fileName, Question ques[], int capacity, int& size) {
    // Open the file
    ifstream inFile(fileName);
    
    // Check if file opened successfully
    if (!inFile.is_open()) {
        cout << "Error: Could not open file " << fileName << endl;
        return;
    }
    
    // Read file line by line
    string line;
    Question currentQuestion;
    string currentField = "";
    
    while (getline(inFile, line)) {
        // Check if line contains a new question
        if (line.find("question:") == 0) {
            // If we already have a question stored, add it to the array
            if (!currentQuestion.text.empty() && size < capacity) {
                ques[size] = currentQuestion;
                size++;
                
                // Reset current question
                currentQuestion = Question();
            }
            
            // Store new question text (remove the "question: " prefix)
            currentQuestion.text = line.substr(line.find(":") + 2);
            currentField = "text";
        }
        // Check for other fields
        else if (line.find("answer:") == 0) {
            currentQuestion.answer = line.substr(line.find(":") + 2);
            currentField = "answer";
        }
        else if (line.find("explanation:") == 0) {
            currentQuestion.explanation = line.substr(line.find(":") + 2);
            currentField = "explanation";
        }
        else if (line.find("type:") == 0) {
            currentQuestion.type = line.substr(line.find(":") + 2);
            currentField = "type";
        }
        else if (line.find("version:") == 0) {
            currentQuestion.version = line.substr(line.find(":") + 2);
            currentField = "version";
        }
        else if (line.find("label:") == 0) {
            currentQuestion.label = line.substr(line.find(":") + 2);
            currentField = "label";
        }
        // If line is not empty and we're in the middle of a field, append to current field
        else if (!line.empty() && currentField != "") {
            if (currentField == "text") {
                currentQuestion.text += " " + line;
            }
            else if (currentField == "answer") {
                currentQuestion.answer += " " + line;
            }
            else if (currentField == "explanation") {
                currentQuestion.explanation += " " + line;
            }
            else if (currentField == "type") {
                currentQuestion.type += " " + line;
            }
            else if (currentField == "version") {
                currentQuestion.version += " " + line;
            }
            else if (currentField == "label") {
                currentQuestion.label += " " + line;
            }
        }
    }
    
    // Don't forget to add the last question if we have one
    if (!currentQuestion.text.empty() && size < capacity) {
        ques[size] = currentQuestion;
        size++;
    }
    
    // Close the file
    inFile.close();
}

// Function to display all questions in the array
void display(Question ques[], int size) {
    for (int i = 0; i < size; i++) {
        cout << i + 1 << endl; // start labeling from 1
        
        // display question text of the ith question
        cout << "question: " << ques[i].text << endl;
        
        // display answer of the ith question
        cout << "answer: " << ques[i].answer << endl;
        
        // display explanation of the ith question
        cout << "explanation: " << ques[i].explanation << endl;
        cout << "type: " << ques[i].type << endl;
        cout << "version: " << ques[i].version << endl;
        cout << "label: " << ques[i].label << endl;
        cout << endl;
    }
}

int main() {
    const int CAPACITY = 1000;
    Question ques[CAPACITY]; // question array
    
    int size = 0;
    
    // Call read_file for "cs135_midterm_f24_v1.txt"
    read_file("cs135_midterm_f24_v1.txt", ques, CAPACITY, size);
    
    // Call read_file for "cs135_midterm_f24_v2.txt"
    read_file("cs135_midterm_f24_v2.txt", ques, CAPACITY, size);
    
    // Call read_file for "cs135_midterm_s24_v1.txt"
    read_file("cs135_midterm_s24_v1.txt", ques, CAPACITY, size);
    
    // Call display function on array ques
    display(ques, size);
    
    return 0;
}