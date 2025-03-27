//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Project 1 task D

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;

double calculateAnswer(const string& leftPart, const string& operation, double rightPart) {
    if (operation == "+") {
        return strtod(leftPart.c_str(), nullptr) + rightPart;
    } else if (operation == "-") {
        return strtod(leftPart.c_str(), nullptr) - rightPart;
    } else if (operation == "*") {
        return strtod(leftPart.c_str(), nullptr) * rightPart;
    } else if (operation == "/") {
        return strtod(leftPart.c_str(), nullptr) / rightPart;
    }
    // If the operation is not supported, return 0 (for error handling)
    return 0;
}

int main() {
    // Initialize correctAnswers to count the number of correct responses
    int correctAnswers = 0;

    // Declare variables for parsing the CSV file
    string line, leftPart, operation;
    double rightPart;
    vector<pair<string, double>> data;

    // Generate a random seed based on system time for random question selection
    srand(time(nullptr));

    // Attempt to open the "problems.csv" file
    ifstream inFile("problems.csv");
    if (!inFile.is_open()) {
        cerr << "Error: Unable to open problems.csv" << endl;
        return 1;
    }

    // Read data from the file if it is successfully opened
    while (getline(inFile, line)) {
        istringstream ss(line);
        getline(ss, leftPart, ',');
        getline(ss, operation, ',');
        ss >> rightPart;
        double numericValue;
        stringstream(leftPart) >> numericValue;
        data.emplace_back(leftPart, rightPart);
    }
    inFile.close();

    // Determine the total number of questions initially available
    int totalQuestions = data.size();

    // Loop until there are no more questions in data
    while (!data.empty()) {
        // Select a random question from data
        int randIndex = rand() % data.size();

        // Prompt the user with the selected question and read their input
        cout << data[randIndex].first << " ";
        cout << data[randIndex].second << ", ";
        double userInput;
        cin >> userInput;

        // Check if the user's input is approximately equal to the correct answer
        double correctAnswer = calculateAnswer(data[randIndex].first, data[randIndex].second);
        if (abs(userInput - correctAnswer) < 0.001) {
            cout << "True" << endl;
            correctAnswers++;
        } else {
            cout << "False" << endl;
        }

        // Remove the answered question from consideration
        pair<string, double> temp = data.back();
        data[randIndex] = temp;
        data.pop_back();

        // Check if at least 60% of the answers are correct; if so, stop the quiz
        if (static_cast<double>(correctAnswers) / totalQuestions >= 0.6) {
            cout << "Quiz completed!" << endl;
            break;
        }
    }

    // Print the final percentage of correct answers
    cout << "Final percentage of correct answers: "
              << (static_cast<double>(correctAnswers) / totalQuestions) * 100 << "%";

    
    return 0;
}