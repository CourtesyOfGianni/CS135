//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Lab 03 part D
//ask user to input 2 dates, one should be earlier than other
//then report the West basin elevation for all days in the interval in the reverse chronological order 
//(from the later date to the earlier).
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
using namespace std;

int main(){
    string userdate1;
    cout << "Enter earlier date: ";
    cin >> userdate1;
    string userdate2;
    cout << "Enter later date: ";
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

    string dates[400];   //array to store values within user range
    double elevations[400];
    int size = 0;  //set intial array values to 0

    while (fin >> date >> eastSt >> eastEl >> westSt >> westEl) {  // this loop reads the file line by line, and extracts 5 values on each iteration

        fin.ignore(INT_MAX, '\n'); // ignore other record of data (junk data)

        if (date >= userdate1 && date <= userdate2) {  //check if within data range
            dates[size] = date;   //values for array
            elevations[size] = westEl;
            size++;
       }

    }
    fin.close();

    //print in reverse order
    for (int i = size-1; i >= 0; i--)
        cout << dates[i] << " " << elevations[i] << endl;
}
