/* CSCI 200: Lab 5A - Escape Room
 *
 * Author: Christian Brennan
 *
 * Description:
 *    Uses Runtime polymorphism to have a vector of room objects and is also an intro
 *    to inheritance
 * 
 *    Help reviced: Google, Stackoverflow, W3schools
 * 
 */



#include "GuessTheNumberRoom.h"
#include "ExitRoom.h"

#include <cstdlib>
#include <iostream>
#include <ctime>


using namespace std;

ARoom* go_to_next_room() {
    int randRoomChoice = rand() % 10; // a 10% chance to get directly out
    switch(randRoomChoice) {
    case 7:     return new ExitRoom();
    default:    return new GuessTheNumberRoom();
    }
}

int main() {
    srand( time(0) );
    rand();

    ARoom* currentRoom;

    do {    
        currentRoom = go_to_next_room();
        cout << "Welcome to the " << currentRoom->getRoomName() << endl;
    } while( !currentRoom->escapeTheRoom() );

    cout << "You made it out!" << endl;

    return 0;
}