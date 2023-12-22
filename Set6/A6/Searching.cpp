#include "Searching.h"
#include <SFML/Graphics.hpp>
#include "Position.h"
#include <iostream>

using namespace sf;
using namespace std;

Position Searching::doBFS(sf::RenderWindow& window, bool** checkedArray, char** theMaze, sf::RectangleShape** arrOfRects, int mazeR, int mazeC, Position startingLocation) {
    positionsToCheck.push(startingLocation);
    bool isStart = true;
    checkedArray[startingLocation.r][startingLocation.c] = true;

    while (!positionsToCheck.empty()) {  // While it's not empty
        Position currPos = positionsToCheck.front();
        if(isStart == false) {
            arrOfRects[currPos.r][currPos.c].setFillColor(Color::Magenta);
        }

        isStart = false;
        positionsToCheck.pop();
        if (theMaze[currPos.r][currPos.c] == 'E') {
            arrOfRects[currPos.r][currPos.c].setFillColor(Color::Red);


             while(!positionsToCheck.empty()) {
                arrOfRects[positionsToCheck.front().r][positionsToCheck.front().c].setFillColor(Color::Blue);
                positionsToCheck.pop();
            }

        
            for (int i = 0; i < mazeR; i++) {
                for (int j = 0; j < mazeC; j++) {
                    window.draw(arrOfRects[i][j]);
                }
            }
            window.display();


            return currPos;
        }
        else {
            // need to check if exists AND unvisited
            if(currPos.r+1 < mazeR && theMaze[currPos.r+1][currPos.c] != '#' && checkedArray[currPos.r+1][currPos.c] == false ) {  // R up by 1 C kept constant
                positionsToCheck.push(Position(currPos.r + 1, currPos.c));
                checkedArray[currPos.r+1][currPos.c] = true;

            }

            if (currPos.r-1 >= 0 && theMaze[currPos.r-1][currPos.c] != '#' && checkedArray[currPos.r-1][currPos.c] == false ) {  // R down by 1 and C kept constant
                positionsToCheck.push(Position(currPos.r - 1, currPos.c));
                checkedArray[currPos.r-1][currPos.c] = true;

            }
            
            if (currPos.c+1 < mazeC && theMaze[currPos.r][currPos.c+1] != '#' && checkedArray[currPos.r][currPos.c+1] == false ) { // C up by 1 R kept constant
                positionsToCheck.push(Position(currPos.r, currPos.c + 1));
                checkedArray[currPos.r][currPos.c+1] = true;

            }
            if(currPos.c-1 >= 0 && theMaze[currPos.r][currPos.c-1] != '#' && checkedArray[currPos.r][currPos.c-1] == false ) {  // C down by 1 and R kept constant
                positionsToCheck.push(Position(currPos.r, currPos.c - 1));
                checkedArray[currPos.r][currPos.c-1] = true;
            }

 
            
            for (int i = 0; i < mazeR; i++) {
                for (int j = 0; j < mazeC; j++) {
                    window.draw(arrOfRects[i][j]);
                }
            }
            
        }

        sf::sleep( sf::milliseconds(50) );
        window.display();  // Display the window after drawing the entire maze
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }
    Position nothing(-1,-1);
    return nothing;
}





Position Searching::doDFS(sf::RenderWindow& window, bool** checkedArray, char** theMaze, sf::RectangleShape** arrOfRects, int mazeR, int mazeC, Position startingLocation) {
    positionsToCheckStack.push(startingLocation);
    bool isStart = true;
    checkedArray[startingLocation.r][startingLocation.c] = true;

    while (!positionsToCheckStack.empty()) {  // While it's not empty
        Position currPos = positionsToCheckStack.top();

        if(isStart == false) {
            arrOfRects[currPos.r][currPos.c].setFillColor(Color::Magenta);
        }
        isStart = false;
        
        positionsToCheckStack.pop();


        if (theMaze[currPos.r][currPos.c] == 'E') {
            arrOfRects[currPos.r][currPos.c].setFillColor(Color::Red);
            while(!positionsToCheckStack.empty()) {
                arrOfRects[positionsToCheckStack.top().r][positionsToCheckStack.top().c].setFillColor(Color::Blue);
                positionsToCheckStack.pop();
            }
            for (int i = 0; i < mazeR; i++) {
                for (int j = 0; j < mazeC; j++) {
                    window.draw(arrOfRects[i][j]);
                }
            }
            window.display();


            return currPos;
        }
        else {
            // need to check if exists AND unvisited

            /*
            if(currPos.r+1 < mazeR && theMaze[currPos.r+1][currPos.c] != '#' && checkedArray[currPos.r+1][currPos.c] == false ) {  // R up by 1 C kept constant
                positionsToCheckStack.push(Position(currPos.r + 1, currPos.c));
                checkedArray[currPos.r+1][currPos.c] = true;
            }

            if (currPos.r-1 >= 0 && theMaze[currPos.r-1][currPos.c] != '#' && checkedArray[currPos.r-1][currPos.c] == false ) {  // R down by 1 and C kept constant
                positionsToCheckStack.push(Position(currPos.r - 1, currPos.c));
                checkedArray[currPos.r-1][currPos.c] = true;
            }
           
            if (currPos.c+1 < mazeC && theMaze[currPos.r][currPos.c+1] != '#' && checkedArray[currPos.r][currPos.c+1] == false ) { // C up by 1 R kept constant
                positionsToCheckStack.push(Position(currPos.r, currPos.c + 1));
                checkedArray[currPos.r][currPos.c+1] = true;

            }

            if(currPos.c-1 >= 0 && theMaze[currPos.r][currPos.c-1] != '#' && checkedArray[currPos.r][currPos.c-1] == false ) {  // C down by 1 and R kept constant
                positionsToCheckStack.push(Position(currPos.r, currPos.c - 1));
                checkedArray[currPos.r][currPos.c-1] = true;
            }
            */

            if (currPos.c+1 < mazeC && theMaze[currPos.r][currPos.c+1] != '#' && checkedArray[currPos.r][currPos.c+1] == false ) { // C up by 1 R kept constant
                positionsToCheckStack.push(Position(currPos.r, currPos.c + 1));
                checkedArray[currPos.r][currPos.c+1] = true;
            }

            if (currPos.r-1 >= 0 && theMaze[currPos.r-1][currPos.c] != '#' && checkedArray[currPos.r-1][currPos.c] == false ) {  // R down by 1 and C kept constant
                positionsToCheckStack.push(Position(currPos.r - 1, currPos.c));
                checkedArray[currPos.r-1][currPos.c] = true;
            }


            if(currPos.c-1 >= 0 && theMaze[currPos.r][currPos.c-1] != '#' && checkedArray[currPos.r][currPos.c-1] == false ) {  // C down by 1 and R kept constant
                positionsToCheckStack.push(Position(currPos.r, currPos.c - 1));
                checkedArray[currPos.r][currPos.c-1] = true;
            }




            if (currPos.r+1 < mazeR && theMaze[currPos.r+1][currPos.c] != '#' && checkedArray[currPos.r+1][currPos.c] == false ) {  // R up by 1 C kept constant
                positionsToCheckStack.push(Position(currPos.r + 1, currPos.c));
                checkedArray[currPos.r+1][currPos.c] = true;
            }

            
            for (int i = 0; i < mazeR; i++) {
                for (int j = 0; j < mazeC; j++) {
                    window.draw(arrOfRects[i][j]);
                }
            }
            
        }

        


        sf::sleep( sf::milliseconds(50) );
        window.display();  // Display the window after drawing the entire maze
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }


    
    Position nothing(-1,-1);
    return nothing;
}