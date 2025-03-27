//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Lab 1A

#include <iostream>
using namespace std;


int main() {        
    int x1, x2;     //define user inputs
    cout << "Enter a number: ";     //ask user for first input
    cin >> x1;                //take in first input from user
    cout << "Enter second number: ";   //ask annd take in 2nd input from user 
    cin >>  x2;

    if (x1 < x2) {            //condiitional statement
        cout << x1 << endl;   //if first input is smaller   
    } else {                                
        cout << x2 << endl; //if second input is smaller
    }
return 0;  
}
