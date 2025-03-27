
//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Lab 10

#include <iostream>
#include <string>
using namespace std;

class Time { 
public:
    int h;
    int m;
};

int minutesSinceMidnight(Time time) { //calculate time since midnight
    return (time.h * 60 + time.m); //Time object as input and return the number of minutes from 0:00AM until the time represented by the object. 
}

int minutesUntil(Time earlier, Time later){ //compute distance between earlier and later time
    int earlierm = minutesSinceMidnight(earlier); //take two Time objects as input: earlier and later, and return the number of minutes separating the two times
   int laterm = minutesSinceMidnight(later);
    if (earlierm <= laterm) {
        return laterm - earlierm;
    } else {
        return -((earlierm - laterm) % (24 * 60)); // Correcting for the earlier time being after the later time
    }
}

Time addMinutes(Time time0, int min){
     Time result;
    result.h = time0.h + (min / 60); // Add hours
    result.m = time0.m + (min % 60); // Add minutes

    // Adjust hours and minutes if necessary
    if (result.m >= 60) {
        result.h += 1;
        result.m -= 60;
    }

    return result;
}

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Movie { 
public: 
    string title;
    Genre genre;     
    int duration;    
};

class TimeSlot { 
public: 
    Movie movie;
    Time startTime;
    Time endTime;  // New member to represent the ending time
};

void printMovie(Movie mv){
    string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)" << endl;
}
void printTimeSlot(TimeSlot ts) {
    // Calculate the ending time by adding the duration to the start time
    int endMinutes = ts.startTime.h * 60 + ts.startTime.m + ts.movie.duration;
    int endHours = endMinutes / 60;
    int endMinutesRemainder = endMinutes % 60;

    cout << ts.movie.title << " ";
    switch (ts.movie.genre) {
        case ACTION   : cout << "ACTION"; break;
        case COMEDY   : cout << "COMEDY"; break;
        case DRAMA    : cout << "DRAMA";  break;
        case ROMANCE  : cout << "ROMANCE"; break;
        case THRILLER : cout << "THRILLER"; break;
    }
    cout << " (" << ts.movie.duration << " min) [starts at " << ts.startTime.h << ":" << ts.startTime.m;
    cout << ", ends by " << endHours << ":" << endMinutesRemainder << "]" << endl;
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie) {
    TimeSlot nextSlot;
    nextSlot.movie = nextMovie;

    // Calculate the end time of the current movie
    int endMinutes = ts.startTime.h * 60 + ts.startTime.m + ts.movie.duration;

    // Calculate the start time of the next movie
    nextSlot.startTime.h = endMinutes / 60;
    nextSlot.startTime.m = endMinutes % 60;

    return nextSlot;
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2) {
    // Calculate the end times of the time slots
    int endMinutes1 = ts1.startTime.h * 60 + ts1.startTime.m + ts1.movie.duration;
    int endMinutes2 = ts2.startTime.h * 60 + ts2.startTime.m + ts2.movie.duration;

    // Check if ts1 ends before ts2 starts or if ts2 ends before ts1 starts
    if (endMinutes1 <= ts2.startTime.h * 60 + ts2.startTime.m || 
        endMinutes2 <= ts1.startTime.h * 60 + ts1.startTime.m) {
        return false; // No overlap
    } else {
        return true; // Overlap
    }
}

int main (){ //main function for user inputted times
    Time earlierTime;
    Time laterTime; 
    cout << "Enter the earlier time: ";
    cin >> earlierTime.h >> earlierTime.m;
    cout << "Enter the later time: ";
    cin >> laterTime.h >> laterTime.m;
    int minutesUntilResult = minutesUntil(earlierTime, laterTime);
    cout << "The number of minutes between the two times is: " << minutesUntilResult << endl;
    return 0;
//Task B
    Time time0;
    int min;
    
    cout << "Enter the time (hours minutes): ";
    cin >> time0.h >> time0.m;
    cout << "Enter the number of minutes to add: ";
    cin >> min;

    Time result = addMinutes(time0, min);

    cout << "The new time is: " << result.h << ":" << result.m << endl;
//task C
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};
    TimeSlot morning = {movie1, {9, 15}};
    TimeSlot daytime = {movie2, {12, 15}};
    TimeSlot evening = {movie2, {16, 45}};
    cout << "Time Slots:" << endl;
    printTimeSlot(morning);
    printTimeSlot(daytime);
    printTimeSlot(evening);
    return 0;
//Task D

    TimeSlot nextSlot = scheduleAfter(morning, movie2);

    cout << "Next Time Slot:" << endl;
    printTimeSlot(nextSlot);

    return 0;

//Task E
    if (timeOverlap(morning, daytime)) {
        cout << "Time slots overlap." << endl;
    } else {
        cout << "Time slots do not overlap." << endl;
    }

    return 0;
}