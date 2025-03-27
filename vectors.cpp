//Gianni Russell
//CSCI 135
//Prof Tong Yi
//Lab 12 Task A

#include <iostream>
#include <vector>
using namespace std;

vector<int> makeVector(int n){ //vector with size n
    vector<int> newVector;

    for (int i = 0; i < n; i++){ // range 0 to n-1 last element 
        newVector.push_back(i);  //want values to the the same as index so use i
    }
    return newVector; //return result
}

