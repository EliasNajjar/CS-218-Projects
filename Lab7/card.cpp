/* File: card.cpp
g++ card.cpp SortedLinkedList.cpp Lab7P1.cpp -o Lab7P1 * Course: CS218-1
 * Project: Lab 7 (as part of Project 2)
 * Purpose: implementation of the Card class
 *
 */

#include "card.h"

// Default constructor.
// We allow uninitialized Cards to be created.
// This allows arrays of Cards.
// Uninitialized cards should have Invalid for its suit
// and 0 for its points.
Card::Card() {
    suit = cSuits::Invalid;
    point = 0;
}

// Alternate constructor
// Create a Card with specified suit and points.
Card::Card(cSuits s, cPoints p) {
    suit = s;
    point = p;
}

// access the card point value
Card::cPoints Card::getPoint() const {
    return point;
}

// access the card suit value
Card::cSuits Card::getSuit() const {
    return suit;
}

// compare with another Card object passed in as parameter: other
// if the object your are working on has lower point than other, return 1;
// if the object your are working on has higher point than other, return -1;
// otherwise, return 0
int Card::pointLessThan(Card other) const {
    if (point < other.point) {
        return -1;
    }
    else if (point > other.point) {
        return 1;
    }
    else {
        return 0;
    }
}

// Display a description of the Card object to standard output.
// The output should look like:
//   the sign of suit, followed by the point, then followed by the sign of suit again
void Card::print() const {
    const char* printSuit;
    if (suit == cSuits::Spade) {
        printSuit = SPADE;
    }
    else if (suit == cSuits::Club) {
        printSuit = CLUB;
    }
    else if (suit == cSuits::Heart) {
        printSuit = HEART;
    }
    else {
        printSuit = DIAMOND;
    }

    if (point == 14) {
        cout << printSuit << " A" << printSuit;
    }
    else if (point == 13) {
        cout << printSuit << " K" << printSuit;
    }
    else if (point == 12) {
        cout << printSuit << " Q" << printSuit;
    }
    else if (point == 11) {
        cout << printSuit << " J" << printSuit;
    }
    else if (point == 10) {
        cout << printSuit << 10 << printSuit;
    }
    else {
        cout << printSuit << " " << point << printSuit;
    }
}
