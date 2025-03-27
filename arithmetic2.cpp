//Gianni Russell
//CSCI 135
//Prof Tong Yee
//Project 1 Part B

#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {    // Ask user for number of questions
    int num_questions;
    while (true) {        std::cout << " the total number of questions to: ";
       ::cin >> numquestions;
        if (num_questions > 0) {
            break;
 } else {
            std::cout << "The number of questions cannot be zero or negative. Re-enter: ";
        }
    }
    std::cout << "You have " << num_questions << " questions to answer. " << std::endl;

    // Initialize variables for calculating correctness percentage
    int correct_answers = 0;

    // Generate and ask questions
    for (int i = 0; i < num_questions; i++) {
        // Define operators array
        char operators[] = {'+', '-', '*', '/', '%'};

        // Select operator randomly
        int operator_index = rand() % 5;
        char operator_selected = operators[operator_index];

        // Generate first operand as a single-digit integer
        int operand1 = rand() % 10;

        // Generate second operand based on operator
        int operand2;
        if (operator_selected == '/' || operator_selected == '%') {
            // Generate non-zero single-digit integer for division and remainder
            operand2 = rand() % 9 + 1;
        } else {
            // Generate single-digit integer for addition and subtraction
            operand2 = rand() % 10;
        }

        // Perform operation on operands based on operator
        int result;
        switch (operator_selected) {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            case '%':
                result = operand1 % operand2;
                break;
        }   

        // Prompt user with problem and receive reply
        std::cout << operand1 << " " << operator_selected << " " << operand2 << " = ";
        int user_reply;
        std::cin >> user_reply;

        // Check if reply is correct and print result
        if (user_reply == result) {
            std::cout << "true" << std::endl;
            correct_answers++;
        } else {
            std::cout << "false" << std::endl;
        }
    }

    // Calculate and print correctness percentage
    double percentage = static_cast<double>(correct_answers) / num_questions * 100;
    std::cout << "Correctness percentage: " << percentage << "%" << std::endl;

    // Print letter grade based on percentage
    if (percentage >= 90) {
        std::cout << "Grade: A" << std::endl;
    } else if (percentage >= 80) {
        std::cout << "Grade: B" << std::endl;
    } else if (percentage >= 70) {
        std::cout << "Grade: C" << std::endl;
    } else if (percentage >= 60) {
        std::cout << "Grade: D" << std::endl;
    } else {
        std::cout << "Grade: F" << std::endl;
    }

    return 0;
}