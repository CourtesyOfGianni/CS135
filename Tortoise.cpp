//Gianni Russell
//CSCI 135
//Prof. Tong Yi
//Project 3 Task B


#include <vector>
#include <iostream>
#include <string>
#include "Tortoise.hpp"
using namespace std;

Tortoise::Tortoise() {
    patterns = {3, 3, 3, 3, 3, -6, -6, 1, 1, 1}; // keep this order
    position = 0;
}
Tortoise::Tortoise(int* arr, int size, int position){
    for (int i = 0; i < size; i++) {
        patterns.push_back(arr[i]);
    }
    this->position = position;
}
Tortoise::Tortoise(std::vector<int> patterns, int position){
    this->patterns = patterns;
    this->position = position; 
}
void Tortoise::move() {
    int index = rand() % patterns.size();
    int stepsToMove = patterns[index];

    position += stepsToMove;
}
int Tortoise::getPosition() const {
    return position;
}
void Tortoise::setPosition(int position){
    this->position = position;
}