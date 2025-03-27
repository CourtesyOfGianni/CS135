#include <iostream>
using namespace std;

int main(){
    int x;
    cout << "Enter the first integer: ";
    cin >> x;

    int y;
    cout << "Enter the second integer: ";
    cin >> y;

    if (x > y){
        cout << "The first integer is greater.";
    } else if (y > x){
        cout << "The first integer is not greater.";
    }
    return 0;
}