//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Lab 07 Task B

//Using code from task A, also count the number of open and closed { } and keep track
//of how many blocks is currently open at the beggining of each line 
//subtract one to fix problem of closing curly brace being indented one too far
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string removeLeadingSpace(string line); //function to remove indentation in bad code
int countChar (string line, char c); // count the number of open and curly braces on a given line 

int countChar (string line, char c) { // takes in line and char and count the number of times c appears in line
    int count = 0; // start at 0

    for(int i = 0; i < line.length(); i++) { // go through line using loop 
        if (line[i] == c) { // if index in the line is equal to the char given as an input parameter, increase count by 1
            
            count++;

        }
    }
    return count;
}


string removeLeadingSpace(string line) {
    int i = 0; //get index of first non indented character start at beginning of string
    
    while (isspace(line[i])) { //while it is a space, move on to next character
    
      i++;

    }   //loop ends when line[i] is not a space
    
    return line.substr(i); //return the line starting at first non space character

}

void printLine(string line, int indent) {  // helper function to print line with appropriate number of tabs
    for(int i = 0; i < indent; i++){
        cout << "\t";
    }
    cout << line << endl;
}

int main(){ //go through each line in file, and call the function above for each line
    string line;

    int openblocks = 0; // open blcoks at the beginning of each line to determine number of tabs printed

    while(getline(cin,line)) {  //read file line by line
        line = removeLeadingSpace(line);  //remove inital spaces in line and reassign value 

        if (line[0] == '}') { // if line starts with closing bracket
            printLine(line, openblocks -1); // print with one less tab
        } else {
            printLine (line, openblocks);
        }
    
        openblocks += countChar(line, '{') - countChar(line, '}'); //indentation level given by this. 1, and 0 
    }

    return 0;

}

