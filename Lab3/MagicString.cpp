/* 
 * File:   MagicString.cpp
 * Purpose: provide the definition of the MagicString class
 *
 * Author: Elias Najjar
 *
 */
#include <iostream>
#include <stack>
#include "MagicString.h"

// initialize str with ini_str passing as a parameter
MagicString::MagicString(string ini_str)
{
    str = ini_str;
}

// return the current value of the private data member: str
string MagicString::getString() const
{
    return str;
}

// set the value of str to the passed in parameter input_str
void MagicString::setString(string input_str)
{
    str = input_str;
}

// return a reverse string
// using a loop to implement
// Note that the private data member named str, has not been changed
string MagicString::rev_loop() const
{
    string res;
    for (int i = str.length() - 1;i >= 0;i--) // for each letter end to beginning
    {
        res += str[i];
    }
    return res;
}

// return a reverse string
// using recursion to implement
// Note that the private data member named str, has not been changed
string MagicString::rev_recursion() const
{
    if (str.length() <= 1) // reverse if more than 1 char
    {
        return str;
    }
    MagicString next(str.substr(1)); // create object with smaller part
    return next.rev_recursion() + str[0]; // the rest reversed + the start
}

// return a reverse string
// using a stack to implement
// Note that the private data member named str, has not been changed
string MagicString::rev_stack() const
{
    stack<char> rev;
    for (char i : str) // push each char onto stack
    {
        rev.push(i);
    }
    string res;
    while (!rev.empty()) // while stack is not empty
    {
        res += rev.top(); // add top of stack to res
        rev.pop(); // remove top of stack
    }
    return res;
}

// return true if str is a palindrome
// otherwise return false
// A palindrome is defined as a sequence of characters which reads the same backward as forward
// calling member function to  implement
// Note that the private data member named str, has not been changed
bool MagicString::isPalindrome() const
{
    return str == rev_loop();
}
        
// return true if str is a palindrome
// otherwise return false
// A palindrome is defined as a sequence of characters which reads the same backward as forward
// using recursion to implement
// Note that the private data member named str, has not been changed
bool MagicString::isPalindrome_recursion() const
{
    if (str.length() <= 1) // base case, 1 or 0 chars is a palindrome
    {
        return true;
    }
    MagicString middle(str.substr(1,str.length()-2)); // set middle magicstring
    return str[0] == str[str.length()-1] && middle.isPalindrome_recursion(); // if the first equals the last and the middle is a palindrome
}
        
// displays str followed by a new line marker
// to the standard output
void MagicString::print() const
{
    cout << str << endl;
}
