//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Lab 04 part B
//checkerboard
#include <iostream>
using namespace std;

int main(){ //same inputs different shape
    int w,h;
    cout << "Input width: ";
    cin >> w;
    cout << "Input height: ";
    cin >> h;
    cout << endl;
    cout << "Shape: " << endl;
    

//even row * * * * * *  row and col are both even  
//odd row   * * * * *   row and col are both odd
    for (int i = 0; i < h; i++) { //print shape h number of times switch row to i
        for (int j = 0; j < w; j++ ) {   //print character number of times inputted per row switch col to j
            if(j % 2 == i % 2) { //if row and col are equal to each other. If they are not divisible by 2, both are odd, otherwise if they are, they are even
                cout << "*";
            }
            else {    //both are not even
                cout << " ";    //print space
            }
            
        } 
        cout << endl;      
    } 
    return 0;

}