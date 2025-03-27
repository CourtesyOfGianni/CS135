//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//HW E6.18

//Write a function that appends one vector from another. 
//For example, if a is 1, 4, 9, 16 
//and b is 9, 7, 4, 9, 11
//then append returns the vector 1, 4, 9, 16, 9, 7, 4, 9, 11
#include <iostream>
#include <vector>
using namespace std;

vector<int> append(const vector<int>& a, const vector<int>& b);

// Function to append one vector to another
vector<int> append(const vector<int>& a, const vector<int>& b) {
    // Create a new vector to hold the appended elements
    vector<int> result = a;

    // Iterate over the second vector and append each element to the first vector
    for (int num : b) {
        result.push_back(num);
    }

    // Return the modified vector
    return result;
}

int main() {
    // Example input vectors
    vector<int> v1 = {1, 4, 9, 16};
    vector<int> v2 = {9, 7, 4, 9, 11};

    // Call the append function and store the result
    vector<int> result = append(v1, v2);

    // Output the result
    cout << "Resulting vector after appending: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}