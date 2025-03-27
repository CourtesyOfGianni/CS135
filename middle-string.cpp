//Gianni Russell
//Prof. Tong Yi
//CSCI 135
//Homework E5.6
//write a function string middle (string str) that returns a string containing the middle character in str if the length is odd, 
//or 2 middle characters if the length is even . For example, middle("middle") returns "odd"

#include <iostream>
#include <string>
using namespace std;

string middle(string str) {
    int length = str.length();

    if (length == 0) {
        return "";  // Empty string has no middle character(s)
    }

    int middleIndex = length / 2;

    if (length % 2 == 1) {
        // If the length is odd, return the middle character
        return string(1, str[middleIndex]);
    } else {
        // If the length is even, return 2 middle characters
        return str.substr(middleIndex - 1, 2);
    }
}