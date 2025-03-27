//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Lab 04 part C
#include <iostream>
using namespace std;

int main(){
    int size;
    cout << "Input size: ";
    cin >> size;
    int last = size - 1;  //'last' stores the last index in the row/column (since indexing starts at 0)
    cout << endl; //make sure  there is a line break before the output
  //first column index at 0
  //last column index at size - 1
  //Left-to-right diagonal (\): Happens when i == j.
  //Example: (0,0), (1,1), (2,2), etc.
  //Right-to-left diagonal (/): Happens when j == last - i.
  //Example: (0,4), (1,3), (2,2), etc.

    for (int i = 0; i < size; i++) { //print shape h number of times switch row to i
        for (int j = 0; j < size; j++ ) {   //if current row i = curr column j print * if col j = last index-curr row i print * otherwise print space this prints diagnoal line
            if(i == j || j == last-i) {   //if row and col are equal or if current col is equal to last row index minus current row index 1,1 2,2, 3,3, etc. //or creates other diagonal line for ccross
                cout << "*";
            }
            else {    
                cout << " ";    //print space
            }
            
        } 
        cout << endl;       //finish printing shape
    } 
    return 0;

}