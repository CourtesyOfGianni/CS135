//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Project 1 task D

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <random>
using namespace std;

int correctAnswers = 0;

int main(){
    // Open the CSV file
    ifstream fin("problems.csv");
    if (fin.fail()) {
        cerr << "Error opening file. Exiting program." << endl;
        return 1;
    }
    while(fin.is_open()) {
    string line, leftPart;
    double rightPart;

    vector<pair<string, double>> data;

    random_device rd;
    mt19937 gen(rd());
    }

    while (getline(fin, line)) {
        stringstream ss(line);
        getline(ss, leftPart, ',');
        ss >> rightPart;
        data.push_back(make_pair(leftPart, rightPart));
    }

    for(const auto& pair ; data) {
        cout << pair.first << ": " << pair.second << endl;
    }
    fin.close();

    int problemNum = 0;
    return 0;
}