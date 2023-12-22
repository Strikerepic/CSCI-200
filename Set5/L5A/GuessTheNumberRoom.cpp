#include "GuessTheNumberRoom.h"

#include <cstdlib>
#include <iostream>
using namespace std;

GuessTheNumberRoom::GuessTheNumberRoom() {
    cout << "GuessTheNumberRoom() called" << endl;
    mRoomName = "Guess The Number Room";

    _secretNumber = rand() % 20 + 1;
}

GuessTheNumberRoom::~GuessTheNumberRoom() {
    cout << "~GuessTheNumberRoom() called" << endl;
}

bool GuessTheNumberRoom::escapeTheRoom() {
    int numGuesses = 0;
    int guessNum = 0;
    while ( numGuesses < 5)
    {
        cout << "Guess Num: ";
        cin >> guessNum;
        numGuesses++;
        if(guessNum < _secretNumber) {
            cout << "You're Too Low!" << endl;
        } else if (guessNum > _secretNumber) {
            cout << "You're Too High" << endl;
        } else if (guessNum == _secretNumber) {
            cout << "You Got it!!!" << endl << endl;
            return true;
        }
    }
    cout << "bad guesser, the door opened because the room felt bad for you :) Your now in another room " << endl;
    return false;
    

}