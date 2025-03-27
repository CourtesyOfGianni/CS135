//Gianni Russell
//CSCI 135
//Project 1A
//Prof. Tong Yi

#include <iostream>
#include <string>
using namespace std;



int main(){
    string question;
    string answer;

    string firstquestion = "What is -1 + 5/3 ?";
    string firstanswer = "0";

    string useranswer;
    cout << firstquestion << endl;
    cout << "Your Answer: ";
    getline(cin, useranswer); //cin only works for first space character, cannot take multi answers
    //getline takes entire line no matter spaces


    cout << boolalpha << (useranswer == firstanswer) << endl;

    string useranswer2;
    string secondquestion = "Assume that n is properly declared and initialized. Write a condition to represent that n does NOT satisify 0 < n < 100.";
    string secondanswer = "(n <= 0 || n >= 100)";

    cout << secondquestion << endl;
    cout << "Your Answer: ";
    getline(cin, useranswer2);
    cout << boolalpha << (useranswer2 == secondanswer); 
    return 0;
    
}