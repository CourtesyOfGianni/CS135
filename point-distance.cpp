//Gianni Russell
//CSCi 135
//Prof. Tong Yi
//HW 7.16
//Define a structurePoint
//A point has an x and y coordinate 
//write a function double distance that computes the distance from point a to b
//write a program that reads the coordinates of the poitns, calls your function, and displays the result
#include <iostream>
#include <cmath>
using namespace std;

struct Point { 
    double x;
    double y;
};
double distance(Point a, Point b) { // double function
    double dx = b.x - a.x;
    double dy = b.y - a.y;
    return sqrt(dx * dx + dy * dy);
}

int main(){  //main functon to display result anf call function
    Point a, b; //define points

    cout << "Enter x coordinate of point a: ";
    cin >> a.x;
    cout << "Enter y coordinate of point a: ";
    cin >> a.y;

    cout << "Enter x coordinate of point b: ";
    cin >> b.x;
    cout << "Enter y coordinate of point b: ";
    cin >> b.y;

    double dist = distance (a, b);

    cout << "The distance between the 2 points are :" << dist << endl;

    return 0;
}