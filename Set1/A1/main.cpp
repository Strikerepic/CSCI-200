/* CSCI 200: Assignment 1: A1 - Rock Paper Scissor Throw Down!
 *
 * Author: Christian Brennan 
 * 
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 * 
 *
 * XXXXXXXX (MORE_COMPLETE_DESCRIPTION_HERE)
 */


// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.
#include <ctime>
#include <cmath>
#include <cstdlib>

// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

// Define any constants below this comment.

//Rock---->-1
//Paper---->2
//scissors->3
//lizard--->4
// Spock--->5

// Must have a function named "main", which is the starting point of a C++ program.
int main() {
    srand(time(0)); // Seed the random number generator
    rand();

    char playAgain = 'y';
    int playerWin = 0;
    int computerWin = 0;
    int tie = 0;
    

    while (playAgain == 'y' || playAgain == 'Y') {
        cout << "Welcome one and all to a round of Rock, Paper, Scissors, Lizard, Spock! (Enter P, R, S, L, or Sp)" << endl;
        cout << "Player one: ";
        
        string userIn;
        cin >> userIn;
        int userThrow = 0;

        if (userIn == "R" || userIn == "r") {
            userThrow = 1;
            cout << "Player choose rock";
        } else if (userIn == "P" || userIn == "p") {
            userThrow = 2;
            cout << "Player choose paper";
        } else if (userIn == "S" || userIn == "s") {
            userThrow = 3;
            cout << "Player choose scissors";
        } else if (userIn == "L" || userIn == "l") {
            userThrow = 4;
            cout << "Player choose lizard";
        } else {
            userThrow = 5;
            cout << "Player choose spock";
        }
        cout << endl;

        int computer = rand() % 5; // Use 0, 1, 2 for rock, paper, scissors

        if (computer == 0) {
            cout << "Computer choose rock";
        } else if (computer == 1) {
            cout << "Computer choose paper";
        } else if (computer == 2) {
            cout << "Computer choose scissors";
        } else if (computer == 3) {
            cout << "Computer choose lizard";
        } else {
            cout << "Computer choose spock";
        }

        cout << endl;

        switch (userThrow) {
            case 1:
                switch (computer) {  //Player always has rock
                    case 0:
                        cout << "Player and Computer both threw rock. It's a Tie!";
                        tie++;
                        break;
                    case 1:
                        cout << "Paper beats rock. Computer wins.";
                        computerWin++;
                        break;
                    case 2:
                        cout << "Rock beats scissors. Player wins.";
                        playerWin++;
                        break;
                    case 3:
                        cout << "Rock beats lizard. Player wins";
                        playerWin++;
                        break;
                    case 4:
                        cout << "Spock beats rock. Computer wins";
                        computerWin++;
                        break;
                }
            break;
            case 2:
                switch (computer) {  //Player always has Paper
                    case 0:
                        cout << "paper beats rock. Player wins.";
                        playerWin++;
                        break;
                    case 1:
                        cout << "Player and Computer both threw paper. It's a Tie!";
                        tie++;
                        break;
                    case 2:
                        cout << "Scissors beats paper. Computer Wins.";
                        computerWin++;
                        break;
                    case 3:
                        cout << "Lizard beats paper. Computer wins";
                        computerWin++;
                        break;
                    case 4:
                        cout << "Paper beats spock. Player wins.";
                        playerWin++;
                        break;
                }
            break;
            case 3:
                switch (computer) { //Player always has Scissors
                    case 0:
                        cout << "Rock beats scissors. Computer wins.";
                        computerWin++;
                        break;
                    case 1:
                        cout << "Scissors beats paper. Player wins.";
                        playerWin++;
                        break;
                    case 2:
                        cout << "Player and Computer both threw scissors. It's a Tie!";
                        tie++;
                        break;
                    case 3:
                        cout << "Scissors beats lizard. Player wins.";
                        playerWin++;
                        break;
                    case 4:
                        cout << "Spock beats scissors. Computer wins.";
                        computerWin++;
                        break;
                }
            break;
            case 4:
                switch(computer) { //Player always has Lizard
                    case 0:
                        cout << "Rock beats lizard. Computer wins.";
                        computerWin++;
                        break;
                    case 1:
                        cout << "Lizard beats paper. Player wins.";
                        playerWin++;
                        break;
                    case 2:
                        cout << "Scissors beats lizard. Computer wins.";
                        computerWin++;
                        break;
                    case 3:
                        cout << "Player and Computer both threw lizard. It's a Tie!";
                        tie++;
                        break;
                    case 4:
                        cout << "Lizard beats spock. player wins.";
                        playerWin++;
                        break;
                }
            break;
            case 5:
                switch(computer) { //Player always has Spock
                    case 0:
                        cout << "Spock beats rock. Player wins.";
                        playerWin++;
                        break;
                    case 1:
                        cout << "Paper beats spock. Computer wins.";
                        computerWin++;
                        break;
                    case 2:
                        cout << "Spock beats scissors. Player wins.";
                        playerWin++;
                        break;
                    case 3:
                        cout << "Lizard beats spock. Computer wins.";
                        computerWin++;
                        break;
                    case 4:
                        cout << "Player and Computer both threw spock. It's a Tie!";
                        tie++;
                        break;
                }
            break;
        }

        cout << endl << "Play again? (Y/N)";
        cin >> playAgain;
    }

    cout << "You won: " << playerWin << " game(s)." << "The computer won: " << computerWin << " game(s) and " << tie << " game(s) were tied." << endl << endl;

    cout << "Cheese is just a loaf of milk. Goodbye.";

    return 0;
}