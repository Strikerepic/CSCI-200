#ifndef SEARCHING_H
#define SEARCHING_H

#include "Position.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics.hpp>
#include <queue> 
#include <stack>

class Searching
{
public:
    Position doBFS(sf::RenderWindow& window, bool** checkedArray, char** theMaze, sf::RectangleShape** arrOfRects, int mazeR, int mazeC, Position startingLocation);

    Position doDFS(sf::RenderWindow& window, bool** checkedArray, char** theMaze, sf::RectangleShape** arrOfRects, int mazeR, int mazeC, Position startingLocation);


private:
    std::queue<Position> positionsToCheck;

    std::stack<Position> positionsToCheckStack;

    std::vector<Position> notOnList;

    std::vector<Position> unCheckedBlues;

    std::vector<Position> checked;

    std::vector<Position> allClear;

};

#endif