//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Lab 03 part C 
//compare 2 dates entered by user
//check each day in the interval and report which basin had higher elevation on that day 
//by printing “East” or “West”, or print “Equal” if both basins are at the same level.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
using namespace std;

int main(){
    string userdate1;
    cout << "Enter starting dat: ";
    cin >> userdate1;
    string userdate2;
    cout << "Enter ending date: ";
    cin >> userdate2;

    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {    //if file cannot be read
        cerr << "File cannot be opened for reading." << endl;
        exit(1);  // exit if failed to open file
    }

    //removing column headers
    string junk; // new string variable
    getline(fin, junk); //read one line from the file

    string date; // declaring date to read from file
    double eastSt, eastEl, westSt, westEl;   //double for decimal of data

    while (fin >> date >> eastSt >> eastEl >> westSt >> westEl) {  // this loop reads the file line by line, and extracts 5 values on each iteration

        fin.ignore(INT_MAX, '\n'); // ignore other record of data (junk data)

        if (date >=  userdate1 && date <= userdate2) {
            cout << date <<" ";

            //check elevation
            if (eastEl > westEl) {    //if east elevation is higher than west
                cout << "East" << endl;
            } else if (eastEl < westEl) {    //if west elevation is higher than east
                cout << "West" << endl;
            } else if (eastEl = westEl){    //if they are equal
                cout << "Equal" << endl;
            }
        }

    }
    fin.close();

}
