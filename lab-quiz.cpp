#include <iostream>
#include <string>
using namespace std;

string remove(const string& str, char target) {
    string result;
    for(char c : str){
        if  (c != target ){
            result += c;
        } 
    }
    return result;
}

int main() {   // defined string in problem
    string str1 = "hello, hey";
    string str2 = "hello, hey";
    char target1 = 'h';
    char target2 = 'b';

    string newStr1 = remove(str1, target1);
    string newStr2 = remove(str2, target2);

    cout << "Original string: " << str1 << endl;
    cout << "New string: " << newStr1 << endl;
    cout << "Original string 2: " << str2 << endl;
    cout << "New string 2: "  << newStr2 << endl;

    return 0;
}

int main(){  //user inputted string
    string str1;
    cout << "Enter first string: ";
    getline(cin, str);
    char target;
    cout << "Enter character to be removed: " ;
    cin >> target;

    string newStr = remove(str, target);
    cout << "New string: " << newStr << endl;

    return 0;
}