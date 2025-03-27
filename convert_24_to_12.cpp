//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Project 1A

#include <iostream>
#include <string>
using namespace std;

int main() {
    string time24;
    cout << "Enter time (hh:mm) in 24-hour notation (for example, 12:56) "; //user input for time in 24hour
    cin >> time24;

    int semicolonIndex = time24.find(':'); //search for the semi colon that seperates hour and minute
    int hour = stoi(time24.substr(0, semicolonIndex)); //convert hour from string to integer starting from index 0 until the semicolon
    int minute = stoi(time24.substr(semicolonIndex + 1));  //convert minute from string to int starting from semicolon index + 1 pos after

    if (hour < 0 || hour > 23 || minute < 0 || minute > 60) { //conditions to check input to convert
        cout << "Invalid time. Please enter a time between 00:00 and 23: " << endl;
    } else {
        string minuteStr = (minute < 10) ? "0" + to_string(minute) : to_string(minute);
        if (hour == 0) {
            cout << time24 << " in 12-hour notation is 12:" << minuteStr << " AM" << endl;
        } else if (hour < 12) {
            cout << time24 << " in 12-hour notation is " << hour << ":" << minuteStr << " AM" << endl;
        } else if (hour == 12) {
            cout << time24 << " in 12-hour notation is 12:" << minuteStr << " PM" << endl;
        } else {
            cout << time24 << " in 12-hour notation is " << hour - 12 << ":" << minuteStr << " PM" << endl;
        }
    }
    return 0;
}