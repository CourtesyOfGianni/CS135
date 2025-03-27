//Gianni Russell
//CSCI 135
//Prof Tong Yi
//Lab 12 Task C

#include <iostream>
#include <vector>
using namespace std;

void gogeta(vector<int> &goku, vector<int> &vegeta){ //not const mosifying values
    for(int i = 0; i < vegeta.size(); i++){ //go through 2nd vector
        goku.push_back(vegeta[i]); //append 2nd elements to 1st vector
    }
    vegeta.clear(); //clear vector to make the 2nd empty
}

int main(){
    vector<int> v1{1,2,3};
    vector<int> v2{4,5};

    gogeta(v1, v2); //v1 has all elements now in order of v1 v2 and v2 is empty
    
    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] <<  " "; //print out each element in v1
    }
    cout << endl;
}