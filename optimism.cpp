//Gianni Russell
//CSCI 135
//Prof Tong Yi
//Lab 12 Task B

#include <iostream>
#include <vector>
using namespace std;

vector<int> goodVibes(vector<int> v){ //const cannot change
    vector<int> positive;
    for (int i = 0; i < v.size(); i++){ //iterate through vector v
        if(v[i] > 0){
            positive.push_back(v[i]); //add positive values to result vector
        }
    }
    return positive;
}

int main() {
    vector<int> v{1,2,-1,3,4,-1,6};

    v = goodVibes(v); //returns [1,2,3,4,6]

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}