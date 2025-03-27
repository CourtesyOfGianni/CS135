
//Gianni Russell
//CSCI 135
//Prof Tong Yee
//Lab 2 Part A

#include <iostream>
using namespace std;

int main() {
    int integer; //intialize integer
    cout << "Enter an integer in the range of 0 to 100: ";
    cin >> integer; //take in integer from console

    while(integer <= 0 || integer >= 100) {             //condition for integer out of range
        cout << "Invalid input. Please re-enter a number between 0 and 100: ";       //keep trying output until valid integer
        cin >> integer;                             //take integer when in range
    }

    cout << "Number squared is: " << integer*integer << endl;              //doubled integer for squared
      
}