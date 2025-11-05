/* File: rank.cpp
 * Course: CS218-1
 * Project: Lab 8 (as part of Project 2)
 * Purpose: the implementation of member functions for the Rank class.
 *
 */
#include <iostream>
#include <sstream>
#include <iomanip>
#include "rank.h"

using namespace std;

// Default constructor.
Rank::Rank()
{
    kind = hRanks::NoRank;
    point = 0;
}

// Alternate constructor.
// Create a Rank object with specified ranking name and points.
Rank::Rank(hRanks r, rPoints p)
{
    kind = r;
    point = p;
}

// access the hand ranking kind
Rank::hRanks Rank::getKind() const
{
    return kind;
}

// access the card point value of the corresponding ranking kind
Rank::rPoints Rank::getPoint() const
{
    return point;
}

// Display a description of the hand-ranking category to standard output.
// The output should look like:
//   FourOfAKind( 4)
//   FullHouse(10)
//   Flush( A)
//   ...
void Rank::print() const
{
    const int POINTMIN = 2;
    const int POINTMAX = 14;
    const int POINTLETTER = 10;
    if (point < POINTMIN || point > POINTMAX)
    {
        cout << "Invalid card value!" << endl;
        return;
    }

    string printPoint;
    if (point == 14) {
        printPoint = " A";
    }
    else if (point == 13) {
        printPoint = " K";
    }
    else if (point == 12) {
        printPoint = " Q";
    }
    else if (point == 11) {
        printPoint = " J";
    }
    else if (point == 10) {
        printPoint = "10";
    }
    else {
        printPoint = " ";
        printPoint += '0' + point;
    }
    // your code starts here...
    cout << RANK_NAMES[static_cast<int>(kind)] << "(" << printPoint << ")" << endl;
}

