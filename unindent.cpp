//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Lab 07 Task A

//Read bad code in a program and output a fixed version of the code

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string removeLeadingSpace(string line); //function to remove indentation in bad code

string removeLeadingSpace(string line) {
    int i = 0; //get index of first non indented character start at beginning of string
    while (isspace(line[i])) { //while it is a space, move on to next character
        i++;
    }   //loop ends when line[i] is not a space
    return line.substr(i); //return the line starting at first non space character

}

int main(){ //go through each line in file, and call the function above for each line
    string line;
    while(getline(cin,line)) {
        cout << removeLeadingSpace(line) << endl; //print out the line with leading spaces removed
    }
}