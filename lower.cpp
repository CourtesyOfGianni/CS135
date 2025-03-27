//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Lab 04 part D
#include <iostream>
using namespace std;

int main(){
    int slength;
    cout << "Input side length: ";
    cin >> slength;
    cout << endl; //make sure  there is a line break before the output



    for (int i = 0; i < slength; i++) { //print shape h number of times switch row to i
        for (int j = 0; j <= i; j++ ) {   //print character number of times inputted per row switch col to j repeats more times as the row gets bigger j<= i so that it will not print a box
            {   //asterisk increases with each row inputted
                cout << "*";
            }
            
        } 
        cout << endl;       //finish printing shape
    } 
    return 0;

}

//Row (i)	Inner Loop (j) Runs	Asterisks Printed
//0	j = 0	*
//1	j = 0, 1	**
//2	j = 0, 1, 2	***
//3	j = 0, 1, 2, 3	****