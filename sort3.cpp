//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Homework 5.15 sort 3
//Write a function sort3(int&a, int&b, int&c) 
//that swaps its three arguments to arrange them in sorted order

#include <iostream>
using namespace std;

void sort3(int& a, int& b, int& c) {
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
}

