//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Lab 03 part B
//finding min and max of east storage in file

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits> //using min max func
#include <string>
using namespace std;

int main(){
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

    double min = INT_MAX;  //initialize at +2bil(bits in int) the first number will always be lower than this
    double max = INT_MIN;  //sets the initial to -2bil (bits that can be stored in int) the first number will also be greater so that will be new max

    
    while (fin >> date >> eastSt >> eastEl >> westSt >> westEl) {  // this loop reads the file line by line, and extracts 5 values on each iteration

        fin.ignore(INT_MAX, '\n'); // ignore other record of data (junk data)
        //go through file and compare numbers to find new min and max until no other is found
        if (eastSt < min) {   //check if east storage is less than minimum if it is use it as the new minimum
            min = eastSt;
        }
        if (eastSt > max) {   //get new max from east storage if it is greater
            max = eastSt;
        }

        }
         fin.close();

         cout << "Minimum storage in East basin: " << min << endl;
         cout << "Maximum storage in East basin:  " << max << endl;   //state new max and min
}

