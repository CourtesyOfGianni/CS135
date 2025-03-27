//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Lab 06 Part B
//Caesar Cipher is a right shift is +5
#include <iostream>
#include <string>
using namespace std;

// A helper function to shift one character by rshift
char shiftChar(char c, int rshift);

// Caesar cipher encryption
string encryptCaesar(string plaintext, int rshift);

int main(){
    string text;
    int shift;
    cout << "Enter plaintext: " << endl;
    getline(cin, text);
    cout << "Enter shift: " << endl;
    cin >> shift;

    cout << encryptCaesar(text, shift) << endl;
}

char shiftChar(char c, int rshift) { // A function to shift one character by rshift
    int shiftedChar;
    char newChar;
    if(isupper(c)) { //c-'A' is value from 0-25 
        newChar = (c -'A' + rshift) % 26 + 'A';
        return newChar;

    } else if (islower(c)) { //char is lowercase 97 is a
        shiftedChar = ( c - 'a' + rshift ) % 26 + 'a';
        return shiftedChar;
    } else { //char is non - alphabetical  so just return the same char
        return c;
    }
}

string encryptCaesar(string plaintext, int rshift) {  // Caesar cipher encryption
    string encryption = "";
    for(int i = 0; i < plaintext.length(); i++){ //itterating through each char in plaintext, and applying shiftChar
        encryption += shiftChar(plaintext[i], rshift);
    }

    return encryption; //new encrypted text
}