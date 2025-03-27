//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Homework E8.1
//Write a program that carries out the following tasks:
//open a file with the name hello.txt, store message "Hello World!" in the file,
//close the file, open the same file again, 
//read the message into a string variable and print it
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    std::ofstream file("hello.txt"); // open file for writing
    if (!file) {
        std::cerr << "Unable to open file for writing" << std::endl;
        return 1;
    }
    file << "Hello, World!"; // write message to file
    file.close(); // close file

    std::ifstream file2("hello.txt"); // open file for reading
    if (!file2) {
        std::cerr << "Unable to open file for reading" << std::endl;
        return 1;
    }
    std::string message;
    std::getline(file2, message); // read message from file
    std::cout << message << std::endl; // print message
    file2.close(); // close file

    return 0;
}