//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Lab 04 part G
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
    //i / 3: This divides the current row index i by 3 to group rows into blocks.

    //Rows 0, 1, 2 → Block 0
    //Rows 3, 4, 5 → Block 1
    //Rows 6, 7, 8 → Block 2, and so on.

    //j / 3: Similarly, this groups columns into blocks of 3.

    //Columns 0, 1, 2 → Block 0
    //Columns 3, 4, 5 → Block 1
    //Columns 6, 7, 8 → Block 2, and so on.
    for (int i = 0; i < h; i++) { //print shape h number of times switch row to i
        for (int j = 0; j < w; j++ ) {   //print character number of times inputted per row switch col to j
            if((j / 3) % 2 == (i / 3) % 2) { //dividing column and row index by 3 before the check if they are even or odd
                cout << "*"; //If both are even (like block 0,0) or both are odd (like block 1,1), it prints *.
                //If one is even and the other is odd, it prints a space.
            }else {    //both are not even
                cout << " ";    //print space
            }
            
        } 
        cout << endl;      
    } 
    return 0;
}

//Row \ Col	0	1	2	3	4	5	6	7	8
//0	*	*	*				*	*	*
//1	*	*	*				*	*	*
//2	*	*	*				*	*	*
//3				*	*	*			
//4				*	*	*			
//5				*	*	*			
//6	*	*	*				*	*	*
//7	*	*	*				*	*	*
//8	*	*	*				*	*	*