//Gianni Russell
//CSCI 135
//Prof. Tong Yi
// LAb 05 task A

#include <iostream>
using namespace std;

bool isDivisibleBy(int n, int d){ //task A
    if(d == 0){  //cant divide 0
        return false;
    }
    if(n % d == 0) { //n is divisible by d
        return true;
    } else {
        return false;
    }
}

bool isPrime(int n){ //Task B
    if (n < 2){   //prime numbers are greater than or equal to 2
        return false;
    }
    for(int i = 2; i < n; i++) {    //prime number only if it is not disvisible evenly from 2 to n-1
        if (isDivisibleBy(n,i)) {
            return false;
        }    //function call ends
    }
    return true;    //number has to be prime if it reached this point
}   //done checking numbers from 2 to last n-1

//Task C
int nextPrime(int n) { //returns the smallest prime greater than n
    int i = n+1;  //start at the integer after n
    
    while(!(isPrime(i))) {      //loop stops when i is prim
        i++;   //if i is not prime, i goes to next int
    }
    return i;
}
//Task D
int countPrimes(int a, int b){ //returns the number of prime numbers in the interval a <= x <= b
    int numPrimes = 0; //initialize counter to 0

    for(int i = a; i <= b; i++){
        if(isPrime(i)){
            numPrimes++;
        }
    }
    return numPrimes;
} //gone through all numbers in range from a to b


//Task E
bool isTwinPrime(int n) { //a prime number n is called a twin prime if either n-2 or n+2 or both of them is also a prim
    if(!isPrime(n)) {
        return false; //if n is not prime then it cant be a twin prime
    }

    if(isPrime(n-2) || isPrime(n+2)) {  //n is prime check if twin prim 
        return true;
    } else {  //not twin prime
        return  false;
    }
}

//Task F
int nextTwinPrime(int n) { //returns the smallest twin prime greater than n
    int i = n+1; //start one above n

    while(!(isTwinPrime(i))) { //loop stops when i is twin prime
        i++;  //if i is not twin prime, i goes to next int
    }
    return i;
}

//Task G
int largestTwinPrime(int a, int b) {
    for(int i = b; i  >= a ; i-- ) { 
        if(isTwinPrime(i)) {   //check if i is a prime
            return i;
        }
    } //checked entire range
    return -1;    //found no twin primes
}
//main function
int main() {
    cout << isDivisibleBy(15, 3) << endl; //true
    cout << isDivisibleBy(11, 3) << endl; //false

    if(isPrime(15) == 0){
        cout << "Not Prime" << endl;
    } else {
        cout << "Prime" << endl;
    }
    return 0;

    cout << countPrimes(3,17) << endl;

    cout << isTwinPrime(23) << endl; //0
    cout << isTwinPrime(17) << endl;  //1
    cout << isTwinPrime(31) << endl;  //0
    cout << isTwinPrime(8) << endl;  //0 false

    cout << nextTwinPrime(11) << endl; //13
    cout << nextTwinPrime(29) << endl;  //31
    cout << nextTwinPrime(18) << endl;   //19
  
}