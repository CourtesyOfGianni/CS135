#include <iostream>
using namespace std;
class StreetAddress{
public: 
int house_number;
string  street_name;
};

class Employee {
public: 
    string name;
    StreetAddress* office;
};

void  print_address(StreetAddress address) {
    cout <<  address.house_number << " " << address.street_name << endl;

}

void print_employee(Employee e){
    cout << e.name << "\'s Office Address is : ";
    print_address(*(e.office));

    
}
