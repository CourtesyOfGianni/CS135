#ifndef SortGame_H
#define SortGame_H

#include <vector>
#include <string>
class SortGame {
public:
    SortGame(); //2 bins, capacity 4 (each bin has at most 4 elements), 1 empty bin 
    SortGame(int numDiffElms, int capacity, int emptyBins);

    //Normally in a header file (ended by .hpp in C++),
    //we do not use standard namespace by adding 
    //using namespace std;
    //Reason: the header might be included in other files,
    //which may not like to use standard namespace.

    //WARNING: if not use -std=c++11 option to compile (that is, c++11 or higher), 
    //then we cannot use >> as in the last two symbols of the following statement,
    //std::vector<std::vector<int>>, 
    //need to use std::vector<std::vector<int> >
    SortGame(std::vector<std::vector<int>> binData, int emptyBins);

    void randomize();
    void display() const;

    //WARNING: a vector is passed by value by default.
    //To change the parameter passed as a vector, must add & after the parameter. 
    bool move(std::vector<std::vector<int>>& shapesInBins, int& numBinsFinished);
    
    void play();
    
//private:
    std::vector<std::vector<int>> bins;
    int numDiffElms;
    int numEmptyBins;
    int capacity;
};
#endif
