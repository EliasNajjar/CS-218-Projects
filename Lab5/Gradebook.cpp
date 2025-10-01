/*
 * File:   Gradebook.cpp
 * Course: CS218-1
 * Project: Lab5 (as first part of Project1)
 * Purpose: provide the implementation of the member functions of the class named Gradebook
 */

#include <iostream>
#include "Gradebook.h"

using namespace std;

// default constructor
Gradebook::Gradebook() {
    scores = {};
}

// return the size of the  current vector: scores,
// which represents current gradebook
int Gradebook::getSize() const {
    return scores.size();
}

// insert a FinalGrade object, newFG,
// into the end of the current gradebook
void Gradebook::insert(FinalGrade newFG) {
    scores.push_back(newFG);
}

// return a FinalGrade object,
// which holds the maximum score in the current gradebook
FinalGrade Gradebook::getMax() const {
    int maxIndex = 0;
    double maxValue = scores[0].getScore();
    for (int i = 1;i < scores.size();i++) {
        if (scores[i].getScore() > maxValue) { // if current score is greater than previous max score
            maxIndex = i;
            maxValue = scores[i].getScore();
        }
    }
    return scores[maxIndex];
}

// return a FinalGrade object,
// which holds the minimum score in the current gradebook
FinalGrade Gradebook::getMin() const {
    int minIndex = 0;
    double minValue = scores[0].getScore();
    for (int i = 1;i < scores.size();i++) {
        if (scores[i].getScore() < minValue) { // if current score is less than previous min
            minIndex = i;
            minValue = scores[i].getScore();
        }
    }
    return scores[minIndex];
}

// return the average score among all scores in the current gradebook
double Gradebook::getAverage() const {
    double sum = 0;
    int maxIndex = 0;
    for (int i = 0;i < scores.size();i++) {
        sum += scores[i].getScore(); // add all the scores
    }
    return sum / scores.size(); // return sum / number of scores
}

// For each FinalGrade object in the current gradebook,
// its score will be increased by the given value
// If the score reaches MAX_SCORE, it does not go beyond
void Gradebook::incrementScore(double value) {
    for (int i = 0;i < scores.size();i++) {
        double newScore = scores[i].getScore() + value; // what the new score would be
        if (newScore > MAX_SCORE) { // if it's greater than the max
            scores[i].setScore(MAX_SCORE); // set to the max
        }
        else {
            scores[i].setScore(newScore);
        }
    }
}

// print the FinalGrade objects in the current gradebook
void Gradebook::print() const {
    for (int i = 0;i < scores.size();i++) {
        scores[i].print();
    }
}
