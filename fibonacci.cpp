//Gianni Russell
//CSCI 1135
//Prof. Tong Yi
//Lab 2 Part D

#include <iostream>
using namespace std;

int main(){
    int fib[60];                //make an array
    fib[0] = 0;                 //first two terms are given
    fib[1] = 1;

    for(int i = 2; i < 60; i++){ //itterate through array starting at 2 because 0 and 1 already defined
        fib[i] = fib[i-1] + fib[i-2];               //all the following terms can be computed with this
    }

    for(int i = 0; i < 60; i++){                       //print the terms in the array
        cout << fib[i] << endl;
    }
}