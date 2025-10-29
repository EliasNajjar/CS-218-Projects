/* File: deck.cpp
 * Course: CS218-1
 * Project: Lab 7 Part 2 (as part of Project 2)
 * Purpose: implementation of the Deck class
 *
 */
#include "deck.h"

// create a standard 52-card deck
void Deck::createDeck() {
    for (int s= (int)Card::cSuits::Spade; s < (int)Card::cSuits::Spade+SUITS; s++)
    {
        for (Card::cPoints val = CARD_START; val < CARD_START+POINTS; val++)
        {
            Card::cSuits suit = static_cast<Card::cSuits>(s);
            Card newcard(suit, val);
            deck.push_back(newcard);
        }
    }
}

// shuffle the cards in 52-card deck
void Deck::shuffleDeck() {
    srand(time(0));
    Card temp;  // for swapping
    for (int i = deck.size()-1; i>= 1; i--)
    {
        int j = rand() % (i+1);
        temp = deck[j];
        deck[j] = deck[i];
        deck[i] = temp;
    }
}

// return a card from the tail of the deck
Card Deck::deal_a_card() {
    Card tail = deck.back();
    deck.pop_back();
    return tail;
}
