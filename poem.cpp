//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Lab 09 Task D
//fix memory leak
//When you use new, you're allocating memory on the heap (which persists until you free it).
//If you don’t call delete, that memory stays reserved forever, even if you're done using it.

#include <iostream>
using namespace std;

string * createAPoemDynamically() {
    string *p = new string; 
    *p = "Roses are red, violets are blue";
    return p;
}

int main() {
    while(true) {
        string *p;
        p = createAPoemDynamically();

        // assume that the poem p is not needed at this point
        delete p;  
    }
}