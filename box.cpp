//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Lab 04 part A
//box
#include <iostream>
using namespace std;

int main(){
    int w,h; //initialize width and height of box
    cout << "Input width: ";
    cin >> w; //with entered by user
    cout << "Input height: ";
    cin >> h; //height entered by user
    cout << endl; //endline as to not take in anything else
    cout << "Shape: " << endl;
//use nested loop for rows and columns (height and width)
   for (int row = 0; row < h; row++) { //print shape h number of times (entered by user)
        for (int col = 0; col < w; col++ ) {   //print character number of times inputted per row
            cout << "*";   //character that makes up shape
        } 
        cout << "\n";      //move down a line after each row is printed
    } //done with shape
}