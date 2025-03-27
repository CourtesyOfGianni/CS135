//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Homework E3.5

#include <iostream>
using namespace std;

int main()
{
    int num1; //initialize 3 numbers to get with user input
    int num2;
    int num3;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Enter third number: ";
    cin >> num3;


    if ((num1 < num2) && (num1 < num3) && (num2 < num3)) //all the logic conditionals to check
    {
        cout << "Increasing" << endl; //check order to see if nums are increasing left to right (up to down)
    }
    else if ((num3 < num2) && (num3 < num1) && (num2 < num1))
    {
        cout << "Decreasing" << endl; //check if they are increasing from right to left/decreasing (increasing down to up)
    }
    else
    {
        cout << "Neither" << endl; //if neither conditions are met
    }

    return 0;

}