//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Lab 06 Part D

#include <iostream>
#include <string>
using namespace std;

string decryptCaesar(string ciphertext, int rshift); //decrypt caesar
string decryptVigenere(string ciphertext, string keyword); //decrypt vigenere

// A helper function to shift one character by rshift
char shiftChar(char c, int rshift);

// Caesar cipher encryption
string encryptCaesar(string plaintext, int rshift);

string encryptVigenere(string plaintext, string keyword);

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
int main(){
    string plaintext;
    string keyword;
    string encryption;
    int rshift;

    cout << "Enter plaintext: ";
    getline(cin, plaintext);

    cout << "= Caesar =" << endl;
    cout << "Enter shift  : ";
    cin >> rshift;
    encryption = encryptCaesar(plaintext, rshift);
    cout << "Ciphertext  : " << encryption << endl;
    cout << "Decrypted  : " << decryptCaesar(encryption, rshift) << endl;
    

    cout << "= Vigenere =" << endl;
    cout << "Enter keyword  : ";
    cin >> keyword;
    encryption = encryptVigenere(plaintext, keyword);
    cout << "Ciphertext  : " << encryption << endl;
    cout << "Decrypted  : " << decryptVigenere(encryption, keyword) << endl;
}
string decryptCaesar(string ciphertext, int rshift) {
    string decrypted = ""; 
    for (int i = 0; i < ciphertext.length(); i++){
        char curr = ciphertext[i];
        if(isupper(curr)) {
            curr = 'A' + (curr - 'A' - rshift + 26 ) % 26;  // subtracting to decrypt instead of encrypt
        } else if(islower(curr)){
            curr = 'a'  + (curr - 'a' - rshift + 26 ) % 26;
        }
        decrypted += curr;
    }
    return decrypted;
}

string decryptVigenere(string ciphertext, string keyword) {
    string decrypted = "";
    int num = 0;
    int key;
    char curr;

    for(int i = 0; i < ciphertext.length(); i++) {
        curr = ciphertext[i];
        if(isupper(curr)) {
            key = keyword[num] - 'a';   //subtracting  ASCII value of a from the character in keyword instead of adding it
            num = (num + 1)  % keyword.length();
            curr = 'A' + (curr - 'A' - key + 26) % 26;  // subtracting key to decrypt instead of adding key to encrypt
        } 
        else if(islower(curr)) {
            key = keyword[num] - 'a';
            num = (num + 1) % keyword.length();
            curr = 'a' + (curr - 'a' - key + 26) % 26;
        }
        decrypted += curr;
    }
    return decrypted;
}

