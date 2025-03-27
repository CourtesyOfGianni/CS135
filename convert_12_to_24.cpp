//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Project 1B

#include <iostream>
#include <string>
using namespace std;

int main() {
    string time12;  // To hold the 12-hour format time
    cout << "Enter time in 12-hour format (hh:mm AM/PM): ";
    getline(cin, time12);  // Get the full input as a string

    // Find the position of the colon (:) in the time string
    int colonPos = time12.find(':');

    // Extract the hour and minute part as separate strings
    string hourStr = time12.substr(0, colonPos);        // Part before the colon start from 0 end at colon
    string minuteStr = time12.substr(colonPos + 1, 2);  // Two characters after the colon for minutes start at pos after colon then end after 2 positions to right
    string ampm = time12.substr(time12.size() - 2);     // The last two characters for AM or PM take size of the string then subtract by 2 to find if am or pm was entered

    // Convert the hour and minute strings to integers
    int hour = stoi(hourStr);  //stoi is a func to convert string to integer
    int minute = stoi(minuteStr);

    // check if input is invalid
     if (hour < 1 || hour > 12 || minute < 0 || minute > 59) {
        cout << "Invalid time. Please enter a time between 01:00 and 12:59: " << endl;
    } else {
        if (ampm != "AM" && ampm != "PM") {
            cout << "Invalid time. Please enter AM or PM: " << endl;
        } else {
            if (ampm == "AM") {  // Convert to 24-hour format based on AM or PM
                if (hour == 12) {
                    hour = 0;  // 12 AM is midnight (00:00)
                }
            } else if (ampm == "PM") {
                if (hour != 12) {
                    hour += 12;  // Add 12 to convert PM times, except for 12 PM
                }
            }

            // Output the time in 24-hour format
            cout << "24-hour notation: ";
            if (hour < 10) cout << "0";  // Add a leading zero for single-digit hours
            cout << hour << ":";
            if (minute < 10) cout << "0";  // Add a leading zero for single-digit minutes
            cout << minute << endl;
        }
    }

    return 0;
}