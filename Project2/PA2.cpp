/*
 * Course: CS218-1
 * Project: Project 2
 * Purpose: to decide the best FIVE-card poker hand out of SEVEN cards according to poker hand ranking
 *          the "hard-coded" testing cases are created for the purpose of testing your definition of PokerHand class
 *
 */
#include <iostream>
#include <vector>
#include "pokerhand.h"
#include "deck.h"

using namespace std;

// avoid magic numbers
const int TOTALCARDS = 7;  // each player gets TOTALCARDS=7 cards
const int HANDS = 5;       // each player plays HANDS=5 cards in hand
const int PLAYERCARDS = 2; // each player gets 2 cards

// decide the best five cards out of seven cards
// best means the highest ranking of five-card poker hand defined in the poker game
// pass in a vector of seven cards
// (const call by reference: safe for the arugment and no copy is made for efficiency)
// return the best PokerHand object which represents the best five-card poker hand
PokerHand best_FIVE_out_of_SEVEN(const vector<Card>& cards);

int main()
{
    string in;
    do {
        Deck cardDeck;
        cardDeck.createDeck();
        cardDeck.shuffleDeck();

        Card yourHand[PLAYERCARDS]; // you and comp get 2 cards
        Card compHand[PLAYERCARDS];
        compHand[0] = cardDeck.deal_a_card(); // deal cards back and forth to you and computer
        yourHand[0] = cardDeck.deal_a_card();
        compHand[1] = cardDeck.deal_a_card();
        yourHand[1] = cardDeck.deal_a_card();

        Card shared[HANDS]; // set 5 cards to share
        shared[0] = cardDeck.deal_a_card();
        shared[1] = cardDeck.deal_a_card();
        shared[2] = cardDeck.deal_a_card();
        shared[3] = cardDeck.deal_a_card();
        shared[4] = cardDeck.deal_a_card();

        cout << "The cards in your hand are:" << endl; // print your cards
        cout << "    " << yourHand[0] << endl;
        cout << "       " << yourHand[1] << endl << endl;

        cout << "The FIVE cards on the deck to share are:" << endl; // print shared cards
        cout << "\t********************" << endl;
        cout << "\t*       " << shared[0] << "       *" << endl;
        cout << "\t*       " << shared[1] << "       *" << endl;
        cout << "\t*       " << shared[2] << "       *" << endl;
        cout << "\t*       " << shared[3] << "       *" << endl;
        cout << "\t*       " << shared[4] << "       *" << endl;
        cout << "\t********************" << endl;

        cout << "The cards in computer's hand are:" << endl; // print comp cards
        cout << "    " << compHand[0] << endl;
        cout << "       " << compHand[1] << endl << endl;

        cout << "Player 1: You" << endl; // your 7 are your 2 and the 5 shared
        vector<Card> seven = {yourHand[0], yourHand[1], shared[0], shared[1], shared[2], shared[3], shared[4]};
        PokerHand yourBest = best_FIVE_out_of_SEVEN(seven); // get best hand

        cout << "Player 2: Computer" << endl; // comp 7 are comp 2 and the 5 shared
        seven[0] = compHand[0];
        seven[1] = compHand[1];
        PokerHand compBest = best_FIVE_out_of_SEVEN(seven); // get best hand

        cout << endl;
        int winner = yourBest.compareHand(compBest);
        if (winner > 0) { // positive means you win
            cout << "Congratulations, you win the game!" << endl;
        }
        else if (winner < 0) { // negative means comp wins
            cout << "Sorry, the computer wins the game!" << endl;
        }
        else { // 0 means tie
            cout << "It is a tie game!" << endl;
        }
        cout << endl << "Do you want to play the poker game again (Press \"q\" or \"Q\" to quit the program) ";

        getline(cin, in);
    } while (in != "q" && in != "Q"); // end on q or Q

    cout << "Thank you for playing CS218 Poker Game, have a great DAY!" << endl;
    return 0;
}

PokerHand best_FIVE_out_of_SEVEN(const vector<Card>& cards)
{

    PokerHand bestH;
    PokerHand cardsH;

    // check if the parameter is valid
    if (cards.size() != TOTALCARDS)
    {
        cout << "Invalid Cards, we need SEVEN cards!" << endl;
        return cardsH; // return a PokerHand object by default constructor
    }

    // Consider all possible ways of dropping two cards
    // from all seven cards
    // i is the index of the first card dropped
    // and j is the index of the second card dropped.
    // There are 21 different ways to pick 5 cards out of 7
    for (int i=0; i < TOTALCARDS; i++)
    {
        for (int j=i+1; j < TOTALCARDS; j++)
        {
            Card pick[HANDS];
            int index = 0;

            // Iterate over all seven cards and assign them to the pick[] array
            // exclude cards with index numbers of #i and #j.
            for (int k=0 ; k < TOTALCARDS ; k++)
            {
                if (k == i || k == j)
                    continue;
                pick[index] = cards[k];
                index++;
            }

            // create a PokerHand with pick[]
            cardsH.setPokerHand(pick, HANDS);

            // Check to see if current pick is better than
            // the best you have seen so far
            if (bestH.compareHand(cardsH) < 0)
            {
                bestH = cardsH ;
            }
        }
    }

    // Now bestH holds the best poker hand among all 21 poker hands
    cout << "*** Best five-card hand ***" << endl;
    bestH.print();
    cout << endl << endl;
    return bestH;
}
