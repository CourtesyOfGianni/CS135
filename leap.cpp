
//Gianni Russell
//Jan 29, 2024
//gianni.russell07@myhunter.cuny.edu

#include <iostream>
using namespace std;


int main()  {
    int year;
    cout << "Enter a year: ";
    cin >> year;

    if (year % 4 != 0) {
        cout << "common year" << endl;
    } else if (year % 100 != 0) {
        cout << "leap year" << endl;
    } if (year % 400 != 0) {
        cout << "common year" << endl;
    } else {
        cout << "leap year";
}
    return 0;
}