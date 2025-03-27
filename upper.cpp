//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Lab 04 part E
#include <iostream>
using namespace std;

int main(){
    int slength;
    cout << "Input side length: ";
    cin >> slength;
    cout << endl; //make sure  there is a line break before the output



    for (int i = 0; i < slength; i++){ //print shape h number of times switch row to i
        for (int j = 0; j < i; j++ ){  //print spaces instead of stars now   //remove = from lower triangle only less than i
                cout << " ";
            }
            for (int j = i; j < slength; j++){
                cout << "*";   //stars
            }
            cout << "\n";
    }
    return 0;
}
            
//Row (i)	Spaces Printed (j < i)	Asterisks Printed (j = i to slength-1)	Output
//0	0 spaces	5 asterisks (*****)	*****
//1	1 space	    4 asterisks (****)	****
//2	2 spaces	3 asterisks (***)	***
//3	3 spaces	2 asterisks (**)	**
//4	4 spaces	1 asterisk (*)	    *