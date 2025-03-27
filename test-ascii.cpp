//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Lab 06 Part A

#include <iostream>
#include <string>
using namespace std;

int main(){
    string text;
    cout << "Input: ";
    getline(cin, text); // input string if using just cin it would stop on whitespace. getline gets the whole string

    for(int i = 0; i < text.length(); i++) { // goes through each char of the string from the start to the end
        cout << text[i] << " " << (int)text[i] << endl;  //(int)c prints the char as a number (ASCII code)
    }

}
