#include <iostream>
#include <string>
using namespace std;

class Date {
public: 
    int day;
    int month;
    int year; 

};
//define a function
//takes a pointer to a date object as input then returns a formatted string
//function takes the month, day, and year from the date object and puts it into a string pattern mmm day, year
// mmm is a 3 letter abbreviation of the month name
//d is day, and year is year
//use to_string function to convert integers into strings

void string formatDate(Date* input) {
    string month_abbr[] = {"0", "Jan", "Feb", "Mar","Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}; 
    string formatted_date = month_abbr[input->month] + " " + to_string(input->day) + ", " + to_string(input->year);
    return formatted_date;
}

int main(){
    date.year = 2023;
    date.month = 1;
    date.day = 2;
    string formatted_date = formatDate(&date);
    cout << "Formatted date is : " << formatted_date << endl;
    return 0;

}