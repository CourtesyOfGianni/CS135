//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Project 1C

#include <iostream>
#include <string>

using namespace std;



int main() {
    string startTime, endTime;

    // Input start and end times
    cout << "Enter start time (HH:MM): ";
    cin >> startTime;
    cout << "Enter end time (HH:MM): ";
    cin >> endTime;

    // Extract hours and minutes from start and end times
    int startHour = stoi(startTime.substr(0, 2)); //start at pos 0 then end at pos 2 for HH
    int startMinute = stoi(startTime.substr(3, 2)); //start at pos 3 end +2 pos after :MM
    int endHour = stoi(endTime.substr(0, 2)); //same for end time
    int endMinute = stoi(endTime.substr(3, 2));

    // Check for invalid input
    if (startHour > endHour || (startMinute > endMinute)) {
        cout << "invalid input" << endl;
        return -1;
    }

    if (startHour == endHour){
        if (startMinute < endMinute){
            int startTotalMinutes = startHour * 60 + startMinute; // Total minutes from midnight for start time
            int endTotalMinutes = endHour * 60 + endMinute;       // Total minutes from midnight for end time
            int durationMinutes = endTotalMinutes - startTotalMinutes; // Duration in minutes
    }

    // Approach 1: Calculate duration
    int startTotalMinutes = startHour * 60 + startMinute; // Total minutes from midnight for start time
    int endTotalMinutes = endHour * 60 + endMinute;       // Total minutes from midnight for end time
    int durationMinutes = endTotalMinutes - startTotalMinutes; // Duration in minutes

    // Calculate hours and remaining minutes
    int durationHours = durationMinutes / 60;           // Whole hours
    int durationRemainingMinutes = durationMinutes % 60; // Remaining minutes

    // Output the result
    cout << "Duration is " << durationHours << " hours and " << durationRemainingMinutes << " minutes." << endl;

    return 0;
}

