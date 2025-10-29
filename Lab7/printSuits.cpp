/*
 * Course: CS216-1
 * Project: testing part for Lab9 and Project 2
 * Purpose: to demonstrate how to display suits of cards
 *          using Unicode
 */

#include <iostream>

using namespace std;

// define the unicode for four suits
// and it is for display purpose
const char SPADE[] = "\e[0;30;47m\xe2\x99\xa0\e[0;37;40m";
const char CLUB[] = "\e[0;30;47m\xe2\x99\xa3\e[0;37;40m";
const char HEART[] = "\e[0;31;47m\xe2\x99\xa5\e[0;37;40m";
const char DIAMOND[] = "\e[0;31;47m\xe2\x99\xa6\e[0;37;40m";

int main()
{
    cout << "Display four suits in one row: " << endl;
    cout << SPADE << "\t" << CLUB << "\t" << HEART << "\t" << DIAMOND << endl;

    cout << "Display four sutis in different rows: " << endl;
    cout << SPADE << endl;
    cout << "\t" << CLUB << endl;
    cout << "\t\t" << HEART << endl;
    cout << "\t\t\t" << DIAMOND << endl;
    
    return 0;
}

