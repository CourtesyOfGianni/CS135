#include <iostream>
using namespace std;

int main() {
    string color;
    cout << "Enter color: ";
    cin >> color;

    if (color = "red"){
        cout << "Color is red, stop";
    } else if (color = "green"){
        cout << "Color is green, go";
    } else if (color = "yellow"){
        cout << "Color is yellow, caution";
    } else {
        cout << "color is not on traffic light." << endl;
    }
    
}