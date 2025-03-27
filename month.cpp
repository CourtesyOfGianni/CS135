//Gianni Russell
//January 30, 2024
//gianni.russell07@myhunter.cuny.edu

#include <iostream>
using namespace std;

int main() {
    int year, month;
    cout << "Enter a year: ";
    cin >> year;
    cout << "Enter a month (1-12): ";
    cin >> month;

    if (month <=7) {
    cout << "31 days" << endl;
    } else if (month >7 && <=12) {
    cout << "30 days" << endl;
    }
    return 0;
}