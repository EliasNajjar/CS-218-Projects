/*
 * Course: CS218-1
 * Project: Lab 2
 * Purpose: practice how to run unix command from C++ program
 *          system() is used to invoke an operating command from a C++ program
 *          demo cowsay command using three different cow files
 * Author: Elias Najjar
 */

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream inputFile("cowFiles.txt");

    if (!inputFile)
    {
        cout << "File failure" << endl;
        return 0;
    }

    string cow;
    int count = 0;
    while (getline(inputFile,cow))
    {
        // each time use a different cow file for cowsay command to use
        string command_str = "cowsay -f /usr/share/cowsay/cows/";
        command_str = command_str + cow;
        command_str = command_str + " Hello, CS218 Students!";
        const char* command = command_str.c_str();
        system(command);
        count++;
    }

    inputFile.close();
    cout << "There are " << count << " cow Files stored in my VM" << endl;
    return 0;
}



