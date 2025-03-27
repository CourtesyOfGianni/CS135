#include <iostream>
using namespace std;

int main(){
    int w,h;
    cout << "Input width: ";
    cin >> w;
    cout << "Input height: ";
    cin >> h;
    cout << endl;
    cout << "Shape: " << endl;


        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (i % 2 == 0) {
                    cout << "*";
                } else {
                    cout << "#";
                }
            }
            cout << "\n";
        }
    return 0;
}