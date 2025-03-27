//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Project 2 Task A

//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Project 2 Task A

#include "Board.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <iomanip>
using namespace std;

Board::Board() {
    numRows = 3;
    numCols = 3;

    panel = new int*[numRows];
    for (int row = 0; row < numRows; row++) {
         panel[row] = new int[numCols];

}

      for (int row = 0; row < numRows; row++) {

         for (int col = 0; col < numCols; col++)
              //panel[row][col] = value; //ok
               panel[row][col] = row * numCols + col + 1;  //also ok, no need to use value
              //reason: for element panel[row][col],
              //(1) the element of panel whose row index is row and column index is col,
              //    number of rows in panel before element panel[row][col] is row.
              //    For example, if row is 2, then there are two rows before panel[row][col],
              //    since row starts from 0.
              //(2) Each row has numCols elments, 
              //    so there are row * numCols elements in those rows. 
              //(3) At (row)th row, there are col elements before panel[row][col].
              //    For example, if row is 2 and col is 1 in a panel where numCols is 3, 
              //    there are row * numCols + col = 2 * 3 + 1 elements before element panel[row][col].
              //(4) Since element panel[0][0] is initialized to be 1,
              //    the label of panel[row][col] should be row * numCols + col + 1.
      }
}
void printSeparateLine(int numCols) {
    cout << "+";
    for (int col = 0; col < numCols; col++) {
        cout << "-----+";  // Print separator for each column
    }

    cout << endl;
}

//define Board(int, int)
Board::Board(int m, int n) {
    if (m >= 2 && n >= 2){
        numRows = m;
        numCols = n;
        panel = new int*[numRows];
        for (int row = 0; row < numRows; row++) {
            panel[row] = new int[numCols];
            for (int col = 0; col < numCols; col++) {
                panel[row][col] = row * numCols + col + 1; // Initialize elements
            }
        }
    } else {
        // Handle the case where m or n is less than 2
        numRows = 3;
        numCols = 3;
        panel = new int*[numRows];
        for (int row = 0; row < numRows; row++) {
            panel[row] = new int[numCols];
            for (int col = 0; col < numCols; col++) {
                panel[row][col] = row * numCols + col + 1; // Initialize elements
            }
        }
}
}

Board::Board(int** arr, int m, int n) {
    this->numRows = m;
    this->numCols = n;

    panel = new int*[this->numRows];
    for (int row = 0; row < this->numRows; row++) {
        panel[row] = new int[this->numCols];
        for (int col = 0; col < this->numCols; col++) {
            panel[row][col] = arr[row][col];
        }
    }
}

Board::~Board() {
    for (int row = 0; row < numRows; row++) {
        delete[] panel[row];
    }
    delete[] panel;
    panel = nullptr; // Avoid dangling pointer
}

void Board::randomize() {
    int size = numRows * numCols;
    int* temp = new int[size];

    for (int i = 0; i < size; i++){
        temp[i] = i + 1;
    }
    int currLastIdx = size - 1;

    while(currLastIdx > 0){
        int randomIdx = rand() % (currLastIdx + 1);
        swap(temp[randomIdx], temp[currLastIdx]); 
        --currLastIdx;
    }
    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < numCols; j++){
            panel[i][j] = temp[i * numCols + j];
        }
    }
}

void Board::display() const {
    auto printLine = [this]() {
        std::cout << "+";
        for (int i = 0; i < numCols; ++i) {
            std::cout << "-----+";
        }
        std::cout << "\n";
    };

    printLine();
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            std::cout << "|";
            if (panel[i][j] == numRows * numCols) {
                std::cout << "     ";
            } else {
                std::cout << std::setw(3) << panel[i][j] << "  ";
            }
        }
        std::cout << "|\n";
        printLine();
    }
}


bool Board::valueCorrect(int row, int col) const {
    int expectedValue = row * numCols + col + 1;

    // If the current value is the empty space (numRows * numCols), it should not be counted as correct
    if (panel[row][col] == numRows * numCols) {
        return false;
    }

    // Otherwise, check if the current value matches the expected value
    return panel[row][col] == expectedValue;
}


void Board::getInfo() {
    emptyCellRow = -1;
    emptyCellCol = -1;
    numCorrect = 0;
    int correctValue = 1;

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            if (panel[i][j] == numRows * numCols) {
                emptyCellRow = i;
                emptyCellCol = j;
            } else if (panel[i][j] == correctValue) {
                numCorrect++;
            }
            correctValue++;
        }
    }
}

void Board::slideLeft() {
//if no right-side neighbor to the empty cell,
//slideLeft operation is ineligible,
//return to the caller, no further action is needed.
    if (emptyCellCol == numCols -1)
        return;

//now empty cell is not at the rightmost column,
//it has a right-side neighbor.
//Find out the row and column for the right-side neighbor.
    int rightNbRow = emptyCellRow;
    int rightNbCol = emptyCellCol + 1;
//in case emptyCellCol == numCols -1,
//then emptyCellCol + 1 returns numCols,
//an invalid column index.

//if the neighbor was in good placement before swapping,
//then after swapping, the correct placement was lost,
//so numCorrect is decreased by 1.
    if (valueCorrect(rightNbRow, rightNbCol))
        numCorrect--;

    swap(panel[emptyCellRow][emptyCellCol], panel[rightNbRow][rightNbCol]);

//after swapping the values of the neighbor and the empty cell,
//but before we updating the row and column information for the empty cell,
//if the value in the original empty cell is correct,
//numCorrect is increased by 1.
    if (valueCorrect(emptyCellRow, emptyCellCol))
        numCorrect++;

//update column information of the new empty cell
    emptyCellCol = rightNbCol;
//No need to update emptyCellRow,
//since it is not changed in slideLeft operation

//do not forget to call display method to show he effect of sliding
    display();
}



void Board::slideUp() {
    // Check if the empty cell is already on the last row (no downstair neighbor).
    if (emptyCellRow == numRows - 1)
        return; // No need to slide up, return early.

    // The empty cell has a downstair neighbor.
    int downNeighborRow = emptyCellRow + 1;
    int downNeighborCol = emptyCellCol;

    // If the downstair neighbor was in the correct position before, we need to decrease numCorrect.
    if (valueCorrect(downNeighborRow, downNeighborCol))
        numCorrect--;

    // Swap the empty cell with its downstair neighbor.
    swap(panel[emptyCellRow][emptyCellCol], panel[downNeighborRow][downNeighborCol]);

    // After the swap, check if the new element in the empty cell is correct, increase numCorrect if it is.
    if (valueCorrect(emptyCellRow, emptyCellCol))
        numCorrect++;

    // Update the empty cell's position.
    emptyCellRow = downNeighborRow;

    // Call display to update the board's state visually.
    display();
}

void Board::slideDown() {
    // Check if the empty cell is already at the top row (no upstair neighbor).
    if (emptyCellRow == 0)
        return; // No need to slide down, return early.

    // The empty cell has an upstair neighbor.
    int upNeighborRow = emptyCellRow - 1;
    int upNeighborCol = emptyCellCol;

    // If the upstair neighbor was in the correct position before, we need to decrease numCorrect.
    if (valueCorrect(upNeighborRow, upNeighborCol))
        numCorrect--;

    // Swap the empty cell with its upstair neighbor.
    swap(panel[emptyCellRow][emptyCellCol], panel[upNeighborRow][upNeighborCol]);

    // After the swap, check if the new element in the empty cell is correct, increase numCorrect if it is.
    if (valueCorrect(emptyCellRow, emptyCellCol))
        numCorrect++;

    // Update the empty cell's position.
    emptyCellRow = upNeighborRow;

    // Call display to update the board's state visually.
    display();
}

void Board::slideRight() {
    // If no left-side neighbor to the empty cell,
    // slideRight operation is ineligible, return to the caller.
    if (emptyCellCol == 0)
        return;

    // Now empty cell is not at the leftmost column,
    // it has a left-side neighbor.
    int leftNbRow = emptyCellRow;
    int leftNbCol = emptyCellCol - 1;

    // Check if the left-side neighbor was in correct placement before swapping
    if (valueCorrect(leftNbRow, leftNbCol))
        numCorrect--;

    // Swap the empty cell with its left-side neighbor
    swap(panel[leftNbRow][leftNbCol], panel[emptyCellRow][emptyCellCol]);

    // After swapping, check if the value at the old empty cell position is correct
    if (valueCorrect(emptyCellRow, emptyCellCol))
        numCorrect++;

    // Update the empty cell's column after the swap
    emptyCellCol = leftNbCol;

    // Display the result
    display();
}


void Board::play() {
    display(); // Display the initial board
    int move = 0;

    while (true) {
        char ch = getchar(); // Get user input

        // Stop the game if 'S' or 's' is pressed
        if (ch == 'S' || ch == 's') {
            break;
        }

        // Check for arrow key input (ESC sequence)
        if (ch == '\033') {  // If the first character is ESC
            getchar(); // Skip the '[' character
            ch = getchar(); // Get the arrow key character

            switch (ch) {
                case 'A':  // Arrow up
                    move++;
                    std::cout << "\nMove " << std::setw(4) << move << ": ";
                    std::cout << "Slide UP." << std::endl;
                    slideUp(); // Call slideUp method
                    break;

                case 'B':  // Arrow down
                    move++;
                    std::cout << "\nMove " << std::setw(4) << move << ": ";
                    std::cout << "Slide DOWN." << std::endl;
                    slideDown(); // Call slideDown method
                    break;

                case 'C':  // Arrow right
                    move++;
                    std::cout << "\nMove " << std::setw(4) << move << ": ";
                    std::cout << "Slide RIGHT." << std::endl;
                    slideRight(); // Call slideRight method
                    break;

                case 'D':  // Arrow left
                    move++;
                    std::cout << "\nMove " << std::setw(4) << move << ": ";
                    std::cout << "Slide LEFT." << std::endl;
                    slideLeft(); // Call slideLeft method
                    break;

                default:
                    break;
            }
        }
    }

    // After the game ends, display the total number of moves
    cout << "\nCongratulations. Total number of moves is " << move << "." << std::endl;
}