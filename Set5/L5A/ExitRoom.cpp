#include "ExitRoom.h"

#include <iostream>
using namespace std;

ExitRoom::ExitRoom() {
    cout << "ExitRoom() called" << endl;
    mRoomName = "The exit room";
}

ExitRoom::~ExitRoom() {
    cout << "~ExitRoom() called" << endl;
}


bool ExitRoom::escapeTheRoom() {
    cout << "You found the exit!" << endl;
    return true;
}
