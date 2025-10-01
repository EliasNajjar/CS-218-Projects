/* 
 * File:   FinalGrade.h
 * Course: CS218-1
 * Project: Lab5 (as first part of Project1)
 * Purpose: provide the declaration of the class named FinalGrade
 *         
 *****PLEASE DO NOT CHANG THIS FILE***** 
 *
 */

#ifndef FINALGRADE_H
#define FINALGRADE_H

using namespace std;

// define the valid score range [MIN_SCORE, MAX_SCORE]
const double MIN_SCORE = 0;
const double MAX_SCORE = 100;

const int SIGDIGITS = 2; // set up the significant digits after the decimal point
const int WIDTH = 6;  // set up the width for output format

class FinalGrade
{
    public:
        // default constructor
        FinalGrade();

        // constructor: set the initial value to the private data member score 
        // to pass-in parameter in_score
        FinalGrade(double in_score);

        // set the private data member: score
        // to pass-in parameter in_score
        void setScore(double in_score);

        // return the value of the data member: score
        double getScore() const;

        // return the corresponding letter grade from score
        // based on the grading policy in CS218 syllabus
        char decideLetterGrade() const;

        // print the score and letter grade in the format: (for example)
        // Score: 88.00        Letter Grade: B
        void print() const;

    private:
        double score;  // it represents the final score of a student
};

#endif /* FINALGRADE_H */

