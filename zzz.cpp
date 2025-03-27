#include <iostream>
#include <string>
using namespace std;

class Date {
public:
    int month;
    int day;
    int year;
};

string formatDate(Date* input) {
    string month_abbr[] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    
    string formatted_date = month_abbr[input->month] + " " + to_string(input->day) + ". " + to_string(input->year);
    return formatted_date;
}

int main() {
    Date date;
    date.month = 1;
    date.day = 2;
    date.year = 2023;

    string formatted_date = formatDate(&date);
    cout << formatted_date << endl;

    return 0;
}