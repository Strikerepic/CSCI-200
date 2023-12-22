#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <queue>

#include "Searching.h"
#include "Position.h"
#include "Searching.h"


using namespace std;
using namespace sf;

int main(int argc, char** argv) {
    string filename;

    // Check if the correct number of command-line arguments is provided
    if (argc == 2) {
        // cout << "Using the inputted command" << std::endl;
        filename = argv[1];
    }

    if (argc == 1 || argc > 2) {
        cout << "Type filename: ";
        cin >> filename;
    }

    // Check if the filename is empty
    if (filename.empty()) {
        cerr << "Error: Empty filename" << std::endl;
        return 1;
    }

    // Open the file
    ifstream fin(filename);

    // Check if the file is successfully opened
    if (!fin.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1; // Return an error code
    }

    cout<< "Would you like Breadth-Fisrt (B) or Depth-First(D): ";
    char UserChoice;
    while(true) {
        cin >> UserChoice;
        if(!cin.fail()) {break;}
        cerr << "Please type either B, b, D, or d" << endl;
        char badChar;
        do{badChar = cin.get();} while(badChar != '\n' );
        cout << "Would you like Breadth-Fisrt (B) or Depth-First(D):";
    }

    int R = 0;
    int C = 0;

    fin >> R;
    fin >> C;

    char** maze = new char*[R];


    bool** hasBeenVisited = new bool*[R];

    RectangleShape** arrOfRects = new RectangleShape*[R];

    // Allocate memory for each row
    for (int i = 0; i < R; i++) {
        maze[i] = new char[C];
        hasBeenVisited[i] = new bool[C];
        arrOfRects[i] = new RectangleShape[C];
    }

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            fin >> maze[i][j];
            hasBeenVisited[i][j] = false;
        }
    }

int scaleVector = 15;
int screenW = scaleVector * C;
int screenH = scaleVector * R;
RenderWindow window(VideoMode(screenW, screenH), "A6");
Event event;


queue<Position> positionsToCheck;
Position start(0,0);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            RectangleShape rect;
            rect.setSize(Vector2f(scaleVector, scaleVector));
            rect.setPosition(Vector2f(scaleVector * j, scaleVector * i));
            if (maze[i][j] == 'S') {
                rect.setFillColor(Color::Green);
                arrOfRects[i][j] = rect;
                start.r = i;
                start.c = j;
            } else if (maze[i][j] == 'E') {
                rect.setFillColor(Color::Red);
                arrOfRects[i][j] = rect;
            } else if (maze[i][j] == '#') {
                rect.setFillColor(Color::Black);
                arrOfRects[i][j] = rect;
            } else {
                rect.setFillColor(Color::White);
                arrOfRects[i][j] = rect;
            }

            
        }
    }

    Position target(0,0);
    Searching mySearch;
    bool searchedConcluded = false;
    while (window.isOpen()) {
    window.clear();  // Clear the window before rendering
    // Uncomment this section for rendering using the nested loop
    
    if((UserChoice == 'b' || UserChoice == 'B')) {
        target = mySearch.doBFS(window,hasBeenVisited,maze,arrOfRects,R,C,start);
        if(searchedConcluded ==  false) {
            cout << "Found End @ " <<  target.r << "  " << target.c << endl;
            for(int i = 0; i < R; i++) {
                for(int j = 0; j < C; j++) {
                    hasBeenVisited[i][j] = true;
                }
            }
        }
        searchedConcluded = true;
    }

    if((UserChoice == 'd' || UserChoice == 'D')) {
        target = mySearch.doDFS(window,hasBeenVisited,maze,arrOfRects,R,C,start);
        if(searchedConcluded ==  false) {
            cout << "Found End @ " <<  target.r << "  " << target.c << endl;
            for(int i = 0; i < R; i++) {
                for(int j = 0; j < C; j++) {
                    hasBeenVisited[i][j] = true;
                }
            }
        }
        
        searchedConcluded = true;
    }

    while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
            // tell the window to close
            window.close();
        }
    }
}



    // Close the file when done
    fin.close();

    return 0; // Return 0 to indicate successful execution
}