#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
   ifstream fin("scores.tsv");
    if (fin.fail()) {    //if file cannot be read
        cerr << "File cannot be opened for reading." << endl;
        exit(1);  // exit if failed to open file
    }
    string header;
    fin >> header;
    cout << "header: " << header;

    getline(fin, header);
    string name;
    int score1, score2, score3;

    while (fin >> name >> score1 >> score2 >> score3) {
        double average = (score1 + score2 + score3) / 3.0;
        cout << name << "," << average << endl;
    }

    fin.close();



    return 0;
}