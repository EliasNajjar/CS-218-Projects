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

// define the operator "<" for Card class
// C1 < C2 if the point of C1 is less than the point of C2
bool operator<(Card C1, Card C2) {
    return C1.point < C2.point;
}

// define the operator "<<" for Card class
// directly send the Card object to the cout, in the following format:
//   the sign of suit, followed by the point, then followed by the sign of suit again
ostream& operator<<(ostream& out, const Card& C) {
    const char* printSuit;
    if (C.suit == Card::cSuits::Spade) {
        printSuit = SPADE;
    }
    else if (C.suit == Card::cSuits::Club) {
        printSuit = CLUB;
    }
    else if (C.suit == Card::cSuits::Heart) {
        printSuit = HEART;
    }
    else {
        printSuit = DIAMOND;
    }

    if (C.point == 14) {
        out << printSuit << " A" << printSuit;
    }
    else if (C.point == 13) {
        out << printSuit << " K" << printSuit;
    }
    else if (C.point == 12) {
        out << printSuit << " Q" << printSuit;
    }
    else if (C.point == 11) {
        out << printSuit << " J" << printSuit;
    }
    else if (C.point == 10) {
        out << printSuit << 10 << printSuit;
    }
    else {
        out << printSuit << " " << C.point << printSuit;
    }

    return out;
}

// define a static function to compare two Card objects
bool Card::HigherBefore(const Card& C1, const Card& C2) {
    return C2 < C1;
}
