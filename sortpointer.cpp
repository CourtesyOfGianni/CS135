//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Homework E7.1
//Write a function that recieves two pointers and sorts the values to which they point

#include <iostream>
using namespace std;

void sort2(double* p, double* q) {
    // Check if swapping is necessary
    if (*p > *q) {
        // Swap values without using std::swap
        double temp = *p;
        *p = *q;
        *q = temp;
    }
}

int main() {
    // Example usage
    double x = 5.7;
    double y = 3.2;

    // Before sorting
    cout << "Before sorting: x = " << x << ", y = " << y << endl;

    // Call the sort2 function
    sort2(&x, &y);

    // After sorting
    cout << "After sorting: x = " << x << ", y = " << y << endl;

    return 0;
}
