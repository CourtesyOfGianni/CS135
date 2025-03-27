//Gianni Russell
//CSCI 135
//Prof Tong Yi
// Lab 03 part A

#include <iostream> 
#include <fstream> //to read files
#include <cstdlib>  //for exit function
#include <climits> //limits of integral for max function and fin.ignore
using namespace std;

int main(){
    string userdate;   //declare date entered by user
    cout << "Enter a date: ";
    cin >> userdate; // document userdate

    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {    //if file cannot be read
        cerr << "File cannot be opened for reading." << endl;
        exit(1);  // exit if failed to open file
    }

    //removing column headers
    string junk; // new string variable
    getline(fin, junk); //reads entire line. cin can only read 1 word at a time cannot handle multi word input

    string date; // declaring date to read from file
    double eastSt, eastEl, westSt, westEl;   //double for decimal of data for each storage point of that date

    while (fin >> date >> eastSt >> eastEl >> westSt >> westEl) {  // this loop reads the file line by line, and extracts 5 values on each iteration

        fin.ignore(INT_MAX, '\n'); // ignore other record of data (junk data)

        if (date == userdate) {     //if conditional  statement is true 
            cout << "East basin storage: " << eastSt << " billion gallons" << endl; //print out the data
        }

    }
    fin.close();

}