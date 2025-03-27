//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Lab 02 Part C

#include <iostream>
using namespace std;

//an array is a container of the same data stored sequentially can be accessed by an index
int main() {
    int myData[10];        // create array of 10 integers
    for (int i = 0; i < 10; i++) {    //itterate through each element in array starting from 0 to number of data in array
        myData[i] = 1; //change all elements in array to 1
    }

    int ind, v; //make new element for user input (ind) as to not confuse with index i in above loop
    do {
        for (int i = 0; i < 10; i++) {  // go through each elemment in the array and print them
            cout << myData[i] << " "; //use i to print the individual element denoted by the index(i)
        }
        cout << endl; //endline

        cout << "Enter index: ";
        cin >> ind;
        cout << "Enter value: ";
        cin >> v;                      // ask user input for cell index i and its new value v

        if (ind >= 0 && ind <= 9) {    // check if index is within range before using it the array holds 10 ints, but the indexes are 0-9
            myData[ind] = v;           // if index is within range update asked cell
        } else {
            cout << "Index out of range." << endl;
        }
    } while (ind >= 0 && ind <= 9); //if index was good repeat
}