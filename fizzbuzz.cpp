#include <iostream>

int main(){
    int n;
    std::string answer[100];
    std::cout << "Enter an integer: ";
    std::cin >> n;

    if (n % 3 == 0 && n % 5 == 0){
        answer[3] = "FizzBuzz";
    } else if (n % 3 == 0 && n % 5 != 0){
        answer[2] = "Fizz";
    } else if (n % 3 != 0 && n % 5 == 0){
        answer[1] = "Buzz";
    } else {
        answer[0] = n;
    }
    int answersize = sizeof(answer) / sizeof(answer[0]);
    for (int i = 0; i < answersize; i++){
        std::cout << answer[i] << std::endl;
    }
}