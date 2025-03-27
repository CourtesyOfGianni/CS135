//Gianni Russell
//CSCI 135
//Prof Tong Yee
//Project 1 Part C

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Open the CSV file
    ifstream fin("problems.csv");
    if (fin.fail()) {
        cerr << "Error opening file. Exiting program." << endl;
        return 1;
    }

    // Initialize variables for calculating correctness percentage
    int numQuestions = 0;
    int numCorrect = 0;
    string txt;
    string ans;

    while (getline(fin, txt, ',') && getline(fin, ans)) {
        // Display the problem
        cout << "Question " << numQuestions + 1 << ": " << txt << " = ";

        // Get reply from users (assuming reply is a double number)
        double user_reply;
        cin >> user_reply;

        // Compare reply with ans (convert string ans to a double number)
        if (user_reply == stod(ans)) {
            cout << "true" << endl;
            numCorrect++;
        } else {
            cout << "false" << endl;
        }

        // Update counters
        numQuestions++;
    }

    // Close the CSV file
    fin.close();

    // Calculate and print correctness percentage
    double percentage = static_cast<double>(numCorrect) / numQuestions * 100;
    cout << "Percent: " << percentage << "%" << endl;

    // Print letter grade based on percentage
    if (percentage >= 90) {
        cout << "Letter Grade: A" << endl;
    } else if (percentage >= 80) {
        cout << "Letter Grade: B" << endl;
    } else if (percentage >= 70) {
        cout << "Letter Grade: C" << endl;
    } else if (percentage >= 60) {
        cout << "Letter Grade: D" << endl;
    } else {
        cout << "Letter Grade: F" << endl;
    }

    return 0;
}