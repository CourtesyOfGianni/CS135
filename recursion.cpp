//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Lab 13 Task A

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

//Task A    
void printRange(int left, int right) {
    if (left > right) { //base case when we want to stop printing numbers  once we reach left > right stop 
        return;
    } //if not at base case keep printing numbers 

    cout << left << " ";
    printRange(left + 1, right); //recursive call to printRange use +1 so there is not an infinite loop of printing the first left
}

//Task B
int sumRange(int left, int right){ 
    if (left > right) { //if range is empty, sum is 0 return 0
        return 0; //base case, stop adding 
    }
    return left + sumRange(left + 1, right); //recursive call to sumRange
}

//Task C
int sumArray(int *arr, int size){
    if (size == 0) { //base case, stop adding
        return 0; //return 0 if size is 0
    }
    int idx = size-1; // index of element
    int element = arr[idx];
    return element + sumArray(arr, size-1);

}

//Task D
bool isAlphanumeric(string s){
    if (s.length() == 0) {
        return true;
    } 
    return isalnum(s[0]) && isAlphanumeric(s.substr(1));
}

//Task E
bool nestedParens(string s){
  if (s.length() == 0) {
        return true; // ""
    }
    if (s.length() == 1) {
        return false; //cant have a length of 1
    }
    if (s[0] == '(' && s[s.length()-1] == ')') { // checks if first and last strings are parentheses
        return nestedParens(s.substr(1, s.length()-2)); //reccursive call remove first and last characters of original string to check remaining part
    }
    return false;
}


//Task F
bool divisible(int *prices, int size, int target = -1, int currentIndex = 0) {
    // Calculate the total sum recursively if it's the first call
    if (target == -1) {
        if (size == 0) return false; // No elements to sum
        // Calculate the sum recursively
        int sum = prices[0] + (size > 1 ? divisible(prices + 1, size - 1, 0, 0) : 0);
        // If the sum is odd, it's not possible to partition it into two equal subsets
        if (sum % 2 != 0) {
            return false;
        }
        target = sum / 2; // Set target to half of the total sum
    }

    // If we found a subset with the target sum
    if (target == 0) {
        return true;
    }
    // If we reach the end of the array or target becomes negative
    if (currentIndex >= size || target < 0) {
        return false;
    }
    
    // Include the current price in the subset
    if (divisible(prices, size, target - prices[currentIndex], currentIndex + 1)) {
        return true;
    }
    
    // Exclude the current price and move to the next
    return divisible(prices, size, target, currentIndex + 1);
}

int main(){
    //Task A
    printRange(-2, 10); 

    //Task B
    int x = sumRange(1, 3);
    cout << x << endl;   // 6

     //Task C
     int size = 10;
    int *arr = new int[size]; // allocate array dynamically
    arr[0] = 12;
    arr[1] = 17;
    arr[2] = -5;
    arr[3] = 3;
    arr[4] = 7;
    arr[5] = -15;
    arr[6] = 27;
    arr[7] = 5;
    arr[8] = 13;
    arr[9] = -21;

    int sum1 = sumArray(arr, size); // Add all elements
    cout << "Sum is " << sum1 << endl;  // Sum is 43
    
    int sum2 = sumArray(arr, 5); // Add up first five elements
    cout << "Sum is " << sum2 << endl;  // Sum is 34

    delete[] arr;         // deallocate it
}