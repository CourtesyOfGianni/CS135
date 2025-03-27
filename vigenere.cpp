//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Lab 06 Part C

#include <iostream>
#include <string>
using namespace std;

string encryptVigenere(string plaintext, string keyword);

int main(){
    string text, key;

    cout << "Enter plaintext: ";
    cin >> text;
    cout << "Enter keyword: ";
    cin >> key;

    cout << "Ciphertext: " << encryptVigenere(text, key) << endl;

}

string encryptVigenere(string plaintext, string keyword) {
    string encryption = "";
    char curr; //initial character to be encrypted
    int num = 0; // go through letters in keyword
    int newPos; // amt to get shifted
    int key;   //key 0-25
    
    for(int i = 0; i < plaintext.length(); i++){  // go through each character in the text will be unchanged if non-alpha
        curr = plaintext[i];
        if(isupper(curr)) { //uppercase text
            key = keyword[num] - 'a'; // shift distance based off keyword convert key char to 0-25
            num = (num + 1) % keyword.length(); // next letter in keyword
            newPos = (curr - 'A' + key) % 26; // get new shifted position
            curr = 'A' + newPos; // determined from positions from 'A', 0-25
        } else if(islower(curr)) { // lowercase text
            key = keyword[num] - 'a';
            num = (num + 1) % keyword.length();
            newPos = (curr - 'a' + key) % 26;
            curr = 'a' + newPos;
        }
        encryption += curr;
    }
    return encryption;
}