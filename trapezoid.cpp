//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Lab 04 part F
#include <iostream>
using namespace std;

int main(){
    int w,h;
    cout << "Input width: ";
    cin >> w;
    cout << "Input height: ";
    cin >> h;
    cout << endl;

    if(w % 2 == 0 && h > w/2) { //If the width is even and the height is greater than half the width, the shape is impossible.
        cout << "Impossible shape!"; 
    }
    else if(w % 2 != 0 && h > (w/2 +1)){ //If the width is odd and the height is greater than (w/2 + 1), the shape is impossible.
        cout << "Impossible shape!";
    }else {
        int spaces = 0; //Starts with no spaces for the first row, then increases by 1 for each subsequent row to shift the stars to the right.
        int stars = w; //Starts with the full width of stars and decreases by 2 in each row (1 star from each side).
        for(int i = 0; i < h; i++){   //loop for height

            for(int s = 0; s < spaces; s++){ // loop for spaces
            cout << " "; 
            }
            for(int j = 0; j < stars; j++){  //loop for stars
            cout << "*";
            }
            cout << endl;  //end line

            stars = stars - 2; //take a star off of each side for trapezoid shape

            spaces++; //increase spacees to indent stars
        }
    }
}
//Row (i)	Spaces (spaces)	Stars (stars)	Output
//0	0	7	*******
//1	1	5	*****
//2	2	3	***
//3	3	1	*