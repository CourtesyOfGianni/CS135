//Gianni Rusell
//Prof Tong Yi
//CSCI 135
//Project 3 Task C


#include "Road.hpp"
#include <iostream>
#include <vector>
using namespace std;

Road::Road(){
    blocks.assign(70, ' '); // Assign blocks with a default length of 70 and a space character for each element
}

Road::Road(int length){
    if(length < 0){ //if length in non positive
        length = 70; //change it to 70
    }
    blocks.assign(length, ' '); // assign blocks with length char, each element is a space
}

void Road::mark(int index, char ch){
    if (index >= 0 && index < blocks.size()-1) { //checks that the index is valid
        blocks[index] = ch; //sets element at the index to the character
    }
}

void Road::display() const{
    for (char block : blocks){ //itterate through each element and print them in a line
        cout << block;
    }
    cout << endl; //print a new line after printing
}

int Road::length() const{
    return blocks.size(); //returns the number of elements in vector
}