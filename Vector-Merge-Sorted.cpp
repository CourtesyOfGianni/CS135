//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//HW E6.20

//Write a function that merges 2 sorted vectors, producing a new sorted vector. 
//Keep and index into each vector indicating how much of it has been  processed so far.  
//Each time append the smallest  unprocessed element from either vector, then advance the index

//Ex: a: 1, 4, 9, 16  b: 4, 7, 9, 9, 11
//merge returns: 1 4 4 7 9 9 9 11 16

#include <iostream>
#include <vector>
using namespace std;

vector<int> merge_sorted(vector<int> a, vector<int> b) {
    vector<int> merged; // Result vector to hold the merged elements
    int indexA = 0, indexB = 0; // Indices to keep track of processed elements in vectors a and b

    // Iterate over both vectors until either indexA or indexB reaches the end of its respective vector
    while (indexA < a.size() && indexB < b.size()) {
        // Compare the elements at indexA in vector a and indexB in vector b
        if (a[indexA] <= b[indexB]) {
            merged.push_back(a[indexA]); // Append the smaller element to the result vector
            indexA++; // Move to the next element in vector a
        } else {
            merged.push_back(b[indexB]); // Append the smaller element to the result vector
            indexB++; // Move to the next element in vector b
        }
    }

    // Append the remaining elements of vector a (if any)
    while (indexA < a.size()) {
        merged.push_back(a[indexA]);
        indexA++;
    }

    // Append the remaining elements of vector b (if any)
    while (indexB < b.size()) {
        merged.push_back(b[indexB]);
        indexB++;
    }

    return merged; // Return the merged result vector
}


int main() {
    // Example input vectors
    vector<int> v1 = {1, 4, 9, 16};
    vector<int> v2 = {4, 7, 9, 9, 11};

    // Call the merge function 
    vector<int> result = merge_sorted(v1, v2);

    // Output the result
    cout << "Resulting vector after merging: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}