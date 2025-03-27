/*
Author: Matthew Mastov
Course: CSCI-135
Instructor: Tong Yi.
Assignment: PROJECT 3
Gonna cry :,)
*/

#include "SortGame.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // For rand()
#include <ctime>   // For seeding rand()

using namespace std;

SortGame::SortGame() : SortGame(2, 4, 1) {
}

void SortGame::randomize() {
    vector<int> flatArray;


    for (int i = 0; i < numDiffElms; i++) {
        flatArray.insert(flatArray.end(), bins[i].begin(), bins[i].end());
    }

    
    int currLastIdx = flatArray.size() - 1;
    while (currLastIdx > 0) {
        int k = rand() % (currLastIdx + 1);
        swap(flatArray[k], flatArray[currLastIdx]);
        currLastIdx--;
    }

    
    int index = 0;
    for (int i = 0; i < numDiffElms; i++) {
        for (int j = 0; j < capacity; j++) {
            bins[i][j] = flatArray[index++];
        }
    }
}

SortGame::SortGame(int numDiffElms, int capacity, int numEmptyBins) {
    if (numDiffElms < 2)
       numDiffElms = 2;
    
    if (capacity < 1)
       capacity = 1;
       
    if (numEmptyBins < 1) 
       numEmptyBins = 1;
       
    this->numDiffElms = numDiffElms;
    this->capacity = capacity;
    this->numEmptyBins = numEmptyBins;
    
    for (int i = 0; i < numDiffElms; i++) {
        vector<int> row(capacity, i+1);
        bins.push_back(row);
    }
    
    for (int i = 0; i < numEmptyBins; i++) {
        vector<int> emptyRow;
        
        bins.push_back(emptyRow);
    }
}

SortGame::SortGame(vector<vector<int>> binData, int numEmptyBins)
  : SortGame(binData.size(), binData[0].size(), numEmptyBins) {
      
  bins = binData;
  
  for (int i = 0; i < numEmptyBins; i++) {
      vector<int> emptyRow;
      bins.push_back(emptyRow);
  }
  
}

bool SortGame::move(vector<vector<int>>& shapesInBins, int& numFinishedBins) {
    cout << "Enter move out and move in bins (-1 -1 to stop): ";

    int moveOut, moveIn;
    cin >> moveOut >> moveIn;

    if (moveOut == -1 && moveIn == -1)
        return false;

    if (moveOut < 1 || moveOut > bins.size() || moveIn < 1 || moveIn > bins.size()) {
        cout << "wrong bin number" << endl;
        return true;
    }

    moveOut--;
    moveIn--;

    if (bins[moveOut].empty()) {
        cout << "move out bin is empty" << endl;
        return true;
    }

    int binTop = bins[moveOut].back();

    if (!bins[moveIn].empty() && bins[moveIn].back() != binTop) {
        cout << "not match" << endl;
        return true;
    }

    int consec = 0;
    for (int i = bins[moveOut].size() - 1; i >= 0; i--) {
        if (bins[moveOut][i] == binTop)
            consec++;
        else
            break;
    }

    int emptySlots = capacity - bins[moveIn].size();
    if (consec > emptySlots) {
        cout << "The move in bin has no sufficient slots." << endl;
        return true;
    }

    // Move elements from moveOut to moveIn
    vector<int> temp;
    for (int i = 0; i < consec; i++) {
        temp.push_back(bins[moveOut].back());
        bins[moveOut].pop_back();
    }
    bins[moveIn].insert(bins[moveIn].end(), temp.begin(), temp.end());

    // Update the shapesInBins parameter to match the current state of bins
    shapesInBins = bins;

    // Check if the destination bin is now "complete"
    if (bins[moveIn].size() == capacity) {
        bool isFinished = true;
        for (int i = 1; i < capacity; i++) {
            if (bins[moveIn][i] != bins[moveIn][0]) {
                isFinished = false;
                break;
            }
        }
        if (isFinished)
            numFinishedBins++;
    }

    // Display the updated bins
    display();

    return true;
}



void SortGame::display() const {
    string shapes[] = {
       "\u2b24", //circle
       "\u2b1f", //pentagon
       "\u25fc", //medium square, can add color
       "\u272f", //star, can add color
       "\u2665", //heart
       "\u25b2", //triangle
    };
    int shapes_size = sizeof(shapes) / sizeof(shapes[0]);
 
    vector<string> colorShapeMap(numDiffElms);
    int colorCode = 31;
    //"\033[31m", a const char*, represents red text color
    //"\033[32m" represents green text color
    for (int i = 0; i < numDiffElms; i++) {
        colorShapeMap[i] = "\033[" + to_string(colorCode) + "m" + shapes[i % shapes_size] + "\033[0m";
        //restore to \033[0m, black color, after displaying a colored shape
        colorCode++;
    }


    //int i = 0; //ith bin, the first bin
    //for (int j = bins[i].size() -1; j >= 0; j--)
    for (int j = capacity -1; j >= 0; j--) {
        for (int i = 0; i < bins.size(); i++) {
            //remove the end of line endl,
            //since we do not print an endl after print the data of a bin.
            if (j < bins[i].size())
                cout << "|  " << colorShapeMap[bins[i][j]-1] << " |";
            else
                cout << "|    |";

            //print gap distance between bins, no spaces after the last bin.
            if (i < bins.size() -1)
               cout << "    ";
        }
        
        //add a new line after printing the jth item of all bins 
        cout << endl;
    }
    
    // Print the "+----+" separators for the bins
    for (int i = 0; i < bins.size(); i++) 
    {
        cout << "+----+"; // Separator for each bin
        if (i < bins.size() - 1)
            cout << "    "; // Space between the separators
    }
    cout << endl;
    
    // Print bin numbers
    for (int i = 0; i < bins.size(); i++) {
        cout << "Bin" << (i + 1) << "  "; // Print bin number, starting from 1
        if (i < bins.size() - 1)
            cout << "    "; // Space between bin numbers
    }
    cout << endl;

}
