//Gianni Russell
//CSCI 135
//Prof. Tong Yi
// LAb 05 task B

#include <iostream>
using namespace std;

bool isPrime(int n){
    if (n < 2){   //prime numbers are greater than or equal to 2
        return false;
    }
    for(int i = 2; i < n; i++) {    //prime number only if it is not disvisible evenly from 2 to n-1
        if (isDivisibleBy(n,i)){
            return false;
        }    //function call ends
    }
    return true;    //number has to be prime if it reached this point
}   //done checking numbers from 2 to last n-1

if(isPrime(15) == 0){
    cout << "Not Prime" << endl;
} else {
    cout << "Prime" << endl;

}
   
