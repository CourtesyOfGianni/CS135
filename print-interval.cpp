//Gianni Russell
//CSCI 135
//Prof. Tong Yee
//Lab 2 Part B

#include <iostream>
using namespace std;

int main() { //main function
    int L, U;
    cout << "Please enter two integers for the limits of interval: ";      //input 2 integers to represent lower limit of interval L and upper limit of interval U
    cin >> L >> U;                   //documents input
    
    for(int i = L; i < U; i++) {         // the body of the loop will get executed for all values of i starting at L and ending at the largest integer less than U seperated by spaces
    if (i == U-1) {                    //if condition true
        cout << i;
    } else { //if conditon not tue
        cout << i << "+";
    }          
    //done printing values in range
    cout << endl;
}
}