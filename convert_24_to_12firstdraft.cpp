//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Project 1A

#include <iostream>
#include <string>
using namespace std;

int main(){
    string time24;
    cout << "Enter time (hh:mm) in 24-hour notation (for example, 12:56) ";
    cin >> time24;


    int semicolonindex = time24.find(':');

    string time12 = time24.substr(0,semicolonindex);
    cout << time24 << " in 12-hour notation is { } " << time12 <<endl;
    return 0;
}