//Gianni Russell
//CSCI 135
//Project 1B
//Prof. Tong Yi

#include <iostream>
#include <string>

//create an array of strings that hold questions,
//another array that holds the correct answers
//itterate through the array and output questions
//take in answers
//check if answers match the correct answers print out the value.
//calculate percentage correct
//If percentage is at least 90%, print “excellent”, otherwise, if percentage is at least 80%, print “good”,
//otherwise, if percentage is at least 60%, print “pass”, otherwise, print “please ask help ASAP”.
int main(){
    std::string texts[] = { //questions array
        "Given char arr[] = {'A', 'B', 'C'}, what is arr[1]?",
        "Given string arr[] = {\"Hello\", \"Hi\", \"Hey\"}, what is arr[2]?",
        "Given two double variables a and b, find out the return of a^b, that is, raised to the power of b. Hint: use pow function.",
        "Suppose n is properly declared and initialized as an integer. Write a statement to throw away the least significant digit from n. For example, if n is 12, after the statement, n changes to be 1.",
        "Assume that n is properly declared and initialized. Write a statement to declare lastDigit as an integer and initialize it to be the least significant digit of integer n. Suppose n is 123, after the statement, lastDigit is 3.",
        "What is the output?\n#include <iostream>\nusing namespace std;\n\nint main() {\n int count = 0;\n for (int i = -6; i < 2; i += 3)\n count++;\n\n cout << count << endl;\n return 0;\n}",
        "Write a condition to represent that char variable ch is none of the following: ’a’, ’b’, or ’c’."
    };
    int size1 = sizeof(texts) / sizeof(texts[0]); //find size of question array to itterate through it
    std::string answers[] = { //answers array
        "'B'",
        "\"Hey\"",
        "pow(a, b)",
        "n /= 10;",
        "int lastDigit = n % 10;",
        "3",
        "(ch != 'a' && ch != 'b' && ch != 'c')"
    
    };
    int size2 = sizeof(answers) / sizeof(answers[0]); //same for answers array
    std::string userinput; //define user inuput
    int score = 0; //define score to check how much user got correct, initialize to 1
    for(int i = 0; i < size1; i++){ //itterate through question array to output each question
        std::cout << "Question " << (i + 1) << ": " << texts[i] << std::endl;
        std::cout << "Enter your answer: ";
        std::getline(std::cin, userinput); //take in userinput for each question
        if (userinput == answers[i]) {//comparison to check is user answer = to answer to cquestion
            std::cout << userinput << std::endl;
            std::cout << "true" << std::endl;
            score++; //increase correct answer score to calculate final percentage later.
        } else {
            std::cout << userinput << std::endl;
            std::cout << "false" << std::endl;
        }
    }
    double percentage = (score * 100.0) / size2;
    std::cout << "number of correct problems: " << score << std::endl;
    std::cout << "percentage of correct: " << percentage << "%" << std::endl;
    if (percentage >= 90){
        std::cout << "Excellent" << std::endl;
    } else if (percentage >=80 && percentage < 90){
        std::cout << "Good" << std::endl;
    } else if (percentage >= 60 && percentage < 80){
        std::cout << "pass" << std::endl;
    } else {
        std::cout << "Please ask help ASAP" << std::endl;
    }
    return 0;
}