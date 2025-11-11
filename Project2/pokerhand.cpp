#include "pokerhand.h"

// Default constructor.
// We allow a blank PokerHand to be created.
// However, the default constructor should make sure
// that hand_rank is (Rank::hRanks::NoRank, 0).
PokerHand::PokerHand() {
    hand_rank.kind = Rank::hRanks::NoRank;
}

// It should store the HANDS cards given as parameters in the cards[] array. if size is not HANDS,
// display "Invalid number of cards!"
// It should also immediately evaluate the hand, determine
// its rank: ranking kind and the card value
void PokerHand::setPokerHand(Card in_hand[], int size) {
    if (size != HANDS) {
        cout << "Invalid number of cards!" << endl;
        return;
    }

    for (int i = 0;i < HANDS;i++) {
        cards[i] = in_hand[i]; // add cards to array
    }
    sort();

    // the correct rank will set the value of hand_rank and return true
    if (isStraightFlush()) {}
    else if (isFourOfAKind()) {}
    else if (isFullHouse()) {}
    else if (isFlush()) {}
    else if (isStraight()) {}
    else if (isThreeOfAKind()) {}
    else if (isPair()) {}
    else if (isHighCard()) {}
}

// Compare this hand versus otherHand according
// to the rules of poker.
// Returns a negative number (< 0)
// if this hand loses to the otherHand.
// Returns a positive number (> 0)
// if this hand beats the otherHand.
// Returns zero if it's a tie.
//
// An invalid hand loses to any hand. If both hands
// are invalid, the result is undefined (could be
// negative, zero or positive).
//
int PokerHand::compareHand(const PokerHand &otherHand) const {
    if (hand_rank.kind == Rank::hRanks::NoRank) { // invalid rank, other is greater
        return -1;
    }
    else if (otherHand.hand_rank.kind == Rank::hRanks::NoRank) {
        return 1;
    }

    if (hand_rank.kind > otherHand.hand_rank.kind) { // this rank is greater
        return 1;
    }
    else if (hand_rank.kind < otherHand.hand_rank.kind) {
        return -1;
    }

    if (hand_rank.point > otherHand.hand_rank.point) { // ranks are equal, check points
        return 1;
    }
    else if (hand_rank.point < otherHand.hand_rank.point) {
        return -1;
    }
    return 0; // tie
}


// Prints out the five cards and its rank to standard output.
// It should look like:
// Five cards:
// one card per line
// then followed by "Its rank is: rank"
void PokerHand::print() const {
    for (int i = 0;i < HANDS - 1;i++) { // print every card with tab except last
        cout << cards[i] << "\t";
    }
    cout << cards[HANDS-1] << endl << "Its rank is: "; // print last card, endl, then rank
    hand_rank.print();
}

// Return the rank of this hand
Rank PokerHand::getRank() const {
    return hand_rank;
}

// The following "isXXXX()" functions shoudl all:
// 1. Assume that the hand is already sorted;
// 2. If true, store the rank in hand_rank;
// 3. use the rank if hand_rank is available.

// Returns true if the hand is a StraightFlush
//              and set the hand_rank (StraightFlush, highest point of the sequential five cards)
// otherwise returns false
bool PokerHand::isStraightFlush() {
    if (isAllOneSuit() && isSequence()) { // straight flush if straight and flush
        hand_rank.kind = Rank::hRanks::StraightFlush;
        hand_rank.point = cards[0].point;
        return true;
    }
    return false;
}

// Returns true if the hand is a Four of a Kind
//              and set the hand_rank (FourOfAKind, highest point of the same four cards)
// otherwise returns false
bool PokerHand::isFourOfAKind() {
    if (cards[0].point == cards[1].point && cards[0].point == cards[2].point && cards[0].point == cards[3].point || cards[1].point == cards[2].point && cards[1].point == cards[3].point && cards[1].point == cards[4].point) { // 2 ways for 4 of a kind with 5 cards
        hand_rank.kind = Rank::hRanks::FourOfAKind;
        hand_rank.point = cards[1].point;
        return true;
    }
    return false;
}

// Returns true if the hand is a Full House
//              and set the hand_rank (FullHouse, highest point of the same three cards)
// otherwise returns false
bool PokerHand::isFullHouse() {
    if (cards[0].point == cards[1].point && cards[0].point == cards[2].point && cards[3].point == cards[4].point || cards[0].point == cards[1].point && cards[2].point == cards[3].point && cards[2].point == cards[4].point) { // 2 ways for full house, 3 then 2 or 2 then 3
        hand_rank.kind = Rank::hRanks::FullHouse;
        hand_rank.point = cards[2].point;
        return true;
    }
    return false;
}

// Returns true if the hand is a Flush
//              and set the hand_rank (Flush, highest point of the five cards)
// otherwise returns false
bool PokerHand::isFlush() {
    if (isAllOneSuit()) {
        hand_rank.kind = Rank::hRanks::Flush;
        hand_rank.point = cards[0].point;
        return true;
    }
    return false;
}

// Returns true if the hand is a Straight
//              and set the hand_rank (Straight, highest point of the sequential five cards)
// otherwise returns false
bool PokerHand::isStraight() {
    if (isSequence()) {
        hand_rank.kind = Rank::hRanks::Straight;
        hand_rank.point = cards[0].point;
        return true;
    }
    return false;
}

// Returns true if the hand is a Three of a Kind
//              and set the hand_rank (ThreeOfAKind, highest point of the same three cards)
// otherwise returns false
bool PokerHand::isThreeOfAKind() {
    if (cards[0].point == cards[1].point && cards[0].point == cards[2].point || cards[1].point == cards[2].point && cards[1].point == cards[3].point || cards[2].point == cards[3].point && cards[2].point == cards[4].point) { // 3 ways for 3 of a kind
        hand_rank.kind = Rank::hRanks::ThreeOfAKind;
        hand_rank.point = cards[2].point;
        return true;
    }
    return false;
}

// Returns true if the hand is a Pair (we consider either one pair or two pairs is a Pair)
//              and set the hand_rank (Pair, highest point of any pair)
// otherwise returns false
bool PokerHand::isPair() {
    for (int i = 0;i < HANDS - 1;i++) { // iterate through each pair to see if they have the same point
        if (cards[i].point == cards[i+1].point) {
            hand_rank.kind = Rank::hRanks::Pair;
            hand_rank.point = cards[i].point;
            return true;
        }
    }
    return false;
}

// Returns true if the hand is a High Card
//              and set the hand_rank (High Card, highest point of the five cards)
// otherwise returns false
bool PokerHand::isHighCard() { // a hand will be high card if it is none of the other hands
    hand_rank.kind = Rank::hRanks::HighCard;
    hand_rank.point = cards[0].point;
    return true;
}

// to help sort the HANDS=5 cards in decreasing order by card points
void PokerHand::sort() { // selection sort
    for (int i = 1;i < HANDS;i++) { // iterate through cards
        int j = i;
        while (j > 0 && cards[j-1].point < cards[j].point) { // swap if greater, moving left
            Card temp = cards[j];
            cards[j] = cards[j-1];
            cards[j-1] = temp;
            j--;
        }
    }
}

// to help decide if HANDS=5 cards are all of one suit
// return true if they are
// otherwise return false
bool PokerHand::isAllOneSuit() const {
    Card::cSuits firstSuit = cards[0].suit; // get first card suit
    for (int i = 0;i < HANDS;i++) {
        if (cards[i].suit != firstSuit) { // if any suit is different
            return false;
        }
    }
    return true;
}

// to help decide if HANDS=5 cards are in a continuous sequence
// return true if they are
// otherwise return false
bool PokerHand::isSequence() const {
    Card::cPoints firstPoint = cards[0].point; // get first point
    for (int i = 1;i < HANDS;i++) {
        if (cards[i].point + i != firstPoint) { // if any point breaks the sequence
            return false;
        }
    }
    return true;
}
