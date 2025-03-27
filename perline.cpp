//Gianni Russell
//CSCI 135
//Prof Tong Yi
//Homework E4.8

#include <iostream>
using namespace std;
#include <string> //use string library

int main() {
    string userin; 
    cout << "Enter a word: ";
    cin >> userin;  //userinput for string

    for (int i = 0; i < userin.length (); i++) //itterate through the length of the string inputted using function included in library
    {
        cout << userin[i] << endl; //print each of the characters (indexes) 1 per line
    }
    return 0;
}