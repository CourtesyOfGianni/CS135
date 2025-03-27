//Gianni Russell
//CSCI 135
//Tong Yi
//Homework E1.7

//This program enters 3 differnet names and prints them on a seperate line

#include <iostream>
#include <string>
using namespace std;

int main() {
    string name1;  //define first name for user to input
    cout << "Enter first name: " << endl;
    cin >> name1; //take in first name defined by user
    string name2; //define 2nd name
    cout << "Enter second name: " << endl;
    cin >>  name2; // take in 2nd name defined by user
    string name3; //etc
    cout << "Enter third name: " << endl;
    cin >> name3;

    cout << name1 << endl << name2 << endl << name3 << endl; //use endl to endline and move onto next line when outputting the other names
    return 0;
 

}