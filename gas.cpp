//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Homework E2.10

#include <iostream>
using namespace std;

int main ()
{
    double gallons; //define a double of gallons since gallons can be decimal
    cout << "Enter the of gallons of in the tank: ";
    cin >> gallons; //take in user defined number of gallons

    double fueleff;  //create another double for the fuel efficiency which can also be a decimal
    cout << "Enter the fuel efficiency in miles per gallon: ";
    cin >> fueleff; //take in fuel efficiency defined by user

    double price; //etc
    cout << "Enter the price of gas per gallon: ";
    cin >> price;

    double costPer100Miles; //create a new double variable to calculate the cost based on fuel efficiency and price
    costPer100Miles = 100.0 / fueleff * price;  //equation to find cose

    double distance; //create new decimal variable to calculate distance based on fuel efficiency and gallons
    distance = fueleff * gallons;

    cout << "Cost per 100 miles: $" << costPer100Miles << endl; //output new calculation
    cout << "Total Distance Driven: " << distance << " miles" << endl;

    return 0;
}