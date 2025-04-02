#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Question {
    string text; //question text
    string answer;
    string explanation;
    string version;
    string type;
    string label;
};

void read_file(string fileName, Question ques[], int capacity, int& size){
    ifstream file(fileName);
    //error opening
    if (!file.is_open()) {

        cout << "Couldn't open file!" << endl;


    }
    while (file.is_open()){
        if (size != capacity){
             // Read question data from the file (pseudo-code)
            std::getline(file, ques[size].text);
            std::getline(file, ques[size].answer);
            std::getline(file, ques[size].explanation);
            std::getline(file, ques[size].version);
            std::getline(file, ques[size].type);
            std::getline(file, ques[size].label);
            size++;  // Increase the count after adding the question
        }
    }
}


void display(Question ques[], int size) {
    for (int i = 0; i < size; i++) {
    cout << i + 1 << endl; //start labeling from 1
    
    //display question text of the ith question
    cout << "question: " << ques[i].text << endl;
    
    //display answer of the ith question
    cout << "answer: " << ques[i].answer << endl;
    
    //display explanation of the ith question
    cout << "explanation: " << ques[i].explanation << endl;
    cout << "type: " << ques[i].type << endl;
    cout << "version: " << ques[i].version << endl;
    cout << "label: " << ques[i].label << endl;
    cout << endl;
    }
}

