//Gianni Russell
//CSCi 135
//Prof. Tong Yi
//HW 7.18
//define a structure triangle 
//contains three point members 
//write a function that computes the perimeter of a triangle 
//write a program that reads the coordinates of the points, calls your function  and displays the result
#include <iostream>
#include <cmath>
using namespace std;

// Define a structure Triangle that contains three Point members
struct Point {
    double x, y;
};

struct Triangle {
    Point points[3];
};

// Write a function that computes the perimeter of a Triangle
double perimeter(Triangle t) {
    double side1 = sqrt(pow(t.points[1].x - t.points[0].x, 2) + pow(t.points[1].y - t.points[0].y, 2));
    double side2 = sqrt(pow(t.points[2].x - t.points[1].x, 2) + pow(t.points[2].y - t.points[1].y, 2));
    double side3 = sqrt(pow(t.points[0].x - t.points[2].x, 2) + pow(t.points[0].y - t.points[2].y, 2));
    return side1 + side2 + side3;
}

// Write a program that reads the coordinates of the points, calls your function, and displays the result
int main() {
    Triangle t;

    cout << "Enter coordinates for 3 points (x y): ";
    for (int i = 0; i < 3; i++) {
        cin >> t.points[i].x >> t.points[i].y;
    }

    double p = perimeter(t);
    cout << "Perimeter of the triangle: " << p << endl;

    return 0;
}