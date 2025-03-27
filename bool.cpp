//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Homework E6.8
//Write a function that checks whether two arrays have the same elements in the same order

#include <iostream>
using namespace std;

bool equals(const int a[], int a_size , int b[], int b_size) { //declaring function
    if(a_size  != b_size) {  //if the size is not equal
        return false;
    } 
    for  (int i = 0 ; i < a_size ; i++) {
        if(a[i] != b[i]){  //if the elements are not equal
            return false;
        }
    }
    return true; ///otherwise return true
}

int main(){
    int a_size, b_size;  //declaring variables for size of array

    cout << "Enter the size of array a: "; //user input for the size of array a
    cin >> a_size;

    int a[a_size];
    cout << "Enter the elements of array a: ";  //user input  for the elements of array a
    for (int i = 0; i < a_size; i++) {  //itterate through each element
        cin >> a[i];
    }

    cout << "Enter the size of array b: ";  //same for b
    cin >> b_size;

    int b[b_size];
    cout << "Enter the elements of array b: ";
    for (int i = 0; i < b_size; i++) {
        cin >> b[i];
    }


    if (equals(a, a_size, b, b_size)) {  //final conditional to determine if true or not
        cout << "the arrays are equal." << endl;
    } else {
        cout << "They are not equal" << endl;
    }
    return 0;

}