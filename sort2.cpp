//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Homework 5.14 Sort 2 
//Write a function void sort 2(int&a, int&b) that swaps the values
//of a and b if a is greater than b, otherwise leave a and b unchanged

#include <iostream>
using namespace std;

void sort2(int& a, int& b) {
    if  (a > b) {
        swap(a, b);
    } 
}