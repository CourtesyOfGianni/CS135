//Gianni Russell
//CSCI 135
//Tong Yi
// Homework 3.1

// This program gets a user input and tells whether it is positive, zero, or negative


#include <iostream>
using namespace std;

int main() {
    int integer; //initialize integer
    cout << "Please enter an integer: ";
    cin >> integer; //get user input

    if (integer == 0) { //if input is a zero
        cout << "The number you entered is zero.";
    } else if (integer < 0){  //negative is less than 0
        cout << "The number is negative";
    } else if (integer > 0){   //greater than 0
        cout << "The number you entered is positive";
    }
    return 0;
}



    