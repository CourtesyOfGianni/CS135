//Gianni Russell
//CSCI 135
//Prof Tong Yi
//Lab 12 Task D

#include <iostream>
#include <vector>
using namespace std;

vector<int> sumPairWise(vector<int> &v1, vector<int> &v2) { 
    vector<int> sum;
    if (v1.size() > v2.size()) { //v1 is bigger sum is initialized to bigger vector
        sum = v1;
        for(int i = 0; i < v2.size(); i++){ //add elements of smaller vector to sum
            sum[i] += v2[i]; 
        }
    } else { //v2 is bigger
        sum = v2;
        for(int i = 0; i < v1.size(); i++){
            sum[i] += v1[i];
        }
    }
    return sum; 
}   

void printVector (const vector<int>& v) {  //print the bigger vector
    for (int i = 0; i <v.size(); i++) {
        cout << v[i]<< " ";
    }
}