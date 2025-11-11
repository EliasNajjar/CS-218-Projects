/*
 *Course: CS218-1
 *Project: Project 1
 *Purpose: take user input for the expected average for a class and curve scores
 */

#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision
#include <string>
#include <cmath>        // std::abs
#include "Gradebook.h"

using namespace std;

int main()
{
    Gradebook CS218gradebook_original;

    double grade;
    while (true)
    {
        cout << "Please enter a score for CS218 (type 'Q' or 'q' to quit):" << endl;
        cin >> grade;
        if (cin.fail()) { // if non-number input
            cin.clear();
            string input;
            cin >> input;
            if (input == "Q" || input == "q") { // if input is Q or q, move on
                break;
            }
            else { // input is not number and not Q or q, so continue
                cout << "Invalid input, please try again..." << endl;
            }
        }
        else { // input is a number
            if (grade < MIN_SCORE || grade > MAX_SCORE) { // out of range
                cout << "The score is not in the correct range, please try again..." << endl;
            }
            else {
                FinalGrade next(grade);
                CS218gradebook_original.insert(next);
            }
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (CS218gradebook_original.getSize() == 0) { // if gradebook is empty, end program
        cout << "The gradebook is Empty!" << endl << "Thank you for using CS218 Grade Curve Calculator." << endl;
        return 0;
    }

    // Implement a Grade Curve Calculator:
    // Display the original average score
    // Then based on each expected average, decide
    //         if adjustment is needed (expected average is close enough to the original average or not);
    //            Display the curved gradebook, the number of scores in the
    //            gradebook, the maximum score and its letter grade, the
    //            minimum score and its letter grade and the actual average
    // Note that Since any score cannot be larger than MAX_SCORE,
    // the "Actual Average" can be less than or equal to "Expected Average"
    cout << fixed << setprecision(SIGDIGITS);

    double expectedAvg;
    while (true)
    {
        cout << endl << endl;
        cout << "The original average score is: " << CS218gradebook_original.getAverage() << endl;
        cout << "Please enter your expected average score to curve (type 'Q' or 'q' to quit):" << endl;
        cin >> expectedAvg;
        if (cin.fail()) {
            cin.clear();
            string input;
            cin >> input;
            if (input == "Q" || input == "q") {
                break;
            }
            else {
                cout << "Invalid input, please try again..." << endl;
            }
        }
        else { // valid input for expectedAvg
	    // check if the expected average is close enough to the original average
	    double diff = expectedAvg - CS218gradebook_original.getAverage();
	    const double EPSILON = 1.0e-2;
	    if (abs(diff) < EPSILON) // if expectedAvg is very close to the original average, no change needed
	        cout << "The scores are perfect, no need for the grading curve!" << endl;
            else // expectedAvg not close enough to the original average
	    {
	        // check if the expected average is in the correct range: (original average,100]
	        if (diff < MIN_SCORE || expectedAvg > MAX_SCORE)
	        {
                    cout << "The expected average is not in the correct range, please try again..." << endl;
                }
	        else  // valid expected average, adjust scores accordingly
	        {
	            Gradebook CS218gradebook_curved = CS218gradebook_original; // copy original to curve
	            CS218gradebook_curved.incrementScore(diff); // increment each score by difference between expectedAvg and original average

                    cout << "The original gradebook for CS218:" << endl;
                    CS218gradebook_original.print();
                    cout << "The number of scores is:\t" << CS218gradebook_original.getSize() << endl;
                    cout << "The maximum score is:\t";
                    CS218gradebook_original.getMax().print();
                    cout << "The minimum score is:\t";
                    CS218gradebook_original.getMin().print();
                    cout << "The original average score is:\t" << CS218gradebook_original.getAverage() << endl << endl << endl;

                    cout << "The expected average score is:\t" << expectedAvg << endl;
                    cout << "The curved gradebook for CS218: " << endl;
                    CS218gradebook_curved.print();
                    cout << "The number of scores is:\t" << CS218gradebook_curved.getSize() << endl;
                    cout << "The maximum score is:\t";
                    CS218gradebook_curved.getMax().print();
                    cout << "The minimum score is:\t";
                    CS218gradebook_curved.getMin().print();
                    cout << "The actual average score is:\t" << CS218gradebook_curved.getAverage() << endl;
                }
            }
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Thank you for using CS218 Grade Curve Calculator." << endl;
    return 0;
}

