
// Gianni Russell
// CSCI 135
// Prof. Tong Yi
// Project 1D

#include <iostream>
#include <fstream> // ifstream, ofstream
#include <string>
using namespace std;

void hours_minutes_in_24h(string str, int& hours, int& minutes); // references to change hours and minutes
int duration(string str);

void hours_minutes_in_24h(string str, int& hours, int& minutes) {
    // Find the position of the space before AM/PM
    size_t spacePos = str.find(' '); // Locate the space character
    string time = str.substr(0, spacePos); // Get the time part
    string period = str.substr(spacePos + 1); // Get AM/PM part

    // Find the position of the colon
    size_t colonPos = time.find(':');
    string hourStr = time.substr(0, colonPos); // Get the hour part
    string minuteStr = time.substr(colonPos + 1); // Get the minute part

    // Convert hour and minute strings to integers
    int h = stoi(hourStr); // Convert hour to int
    int m = stoi(minuteStr); // Convert minute to int

    // Convert to 24-hour format
    if (period == "pm" && h != 12) {
        h += 12; // Convert PM hours to 24-hour format
    } else if (period == "am" && h == 12) {
        h = 0; // Midnight case
    }

    // Assign the results to the reference parameters
    hours = h;
    minutes = m;
}

// Function to calculate duration in minutes between two times
int duration(string str) {
    // Find the position of the hyphen to split the start and end times
    size_t hyphenPos = str.find('-');
    string startTime = str.substr(0, hyphenPos); // Extract start time
    string endTime = str.substr(hyphenPos + 1); // Extract end time

    int startHours, startMinutes;
    int endHours, endMinutes;

    // Convert start and end times to 24-hour format
    hours_minutes_in_24h(startTime, startHours, startMinutes);
    hours_minutes_in_24h(endTime, endHours, endMinutes);

    // Calculate total minutes for start and end times
    int startTotalMinutes = startHours * 60 + startMinutes;
    int endTotalMinutes = endHours * 60 + endMinutes;

    // Calculate duration in minutes
    int durationMinutes = endTotalMinutes - startTotalMinutes;

    return durationMinutes; // Return the duration
}

int main() {
    string filename;
    cout << "Enter the file name: ";
    cin >> filename;

    string priority;
    cout << "Enter the priority: ";
    cin >> priority;

    ifstream fin(filename);
    if (!fin) {
        cout << "Error opening file!" << endl;
        return 1; // Exit if the file cannot be opened
    }

    // Skip the first line (headers)
    string line;
    getline(fin, line);

    int total_duration = 0; // Total duration in minutes

    while (getline(fin, line)) {
        string time, activity, prio;
        
        // Assuming CSV format: time,activity,priority
        int first_comma = line.find(',');
        time = line.substr(0, first_comma);
        
        int second_comma = line.find(',', first_comma + 1);
        activity = line.substr(first_comma + 1, second_comma - first_comma - 1);
        
        prio = line.substr(second_comma + 1);

        // Check if the priority matches
        if (prio == priority) {
            int dur = duration(time); // Get duration in minutes
            total_duration += dur; // Add to total duration
            cout << time << "," << activity << "," << prio << " "
                 << dur / 60 << " hours and " << dur % 60 << " minutes" << endl;
        }
    }

    fin.close();

    // Print total duration
    cout << "total duration: " << total_duration / 60 << " hours and " << total_duration % 60 << " minutes" << endl;

    return 0;
}
