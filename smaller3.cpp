//Gianni Russell
//CSCI 135
//Prof Tong Yi
//Lab 1B

#include <iostream>
using namespace std;

int main(){
    int x1,x2,x3; //define integers
    
    cout << "Enter first number: " ; //ask user for input 1, 2, 3
    cin >> x1;
    cout << "Enter second number: ";
    cin >> x2;
    cout << "Enter third number: ";
    cin >> x3;

    if (x1 < x3 && x1 < x2){ //logic stattement if x1 is the smallest compared to x2 and x3
        cout << "The smallest number is: " << x1 << endl;
    }
    else if (x2 < x3 && x2 < x1){ // if x2 is smallest compares to x1 and x3
        cout << "The smallest number is: " << x2 << endl;
    } 
    else { //otherwise if no othher conditions meet x3 is smallest
        cout << "The smallest number is: " << x3 << endl;
    }

}
