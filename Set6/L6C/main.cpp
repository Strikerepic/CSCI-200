#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>


using namespace std;
using namespace sf;

int main(int argc, char** argv) {
    string filename;

    // Check if the correct number of command-line arguments is provided
    if (argc == 2) {
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

    int R = 0;
    int C = 0;


    fin >> R;
    fin >> C;

    char** maze = new char*[R];

    // Allocate memory for each row
    for (int i = 0; i < R; ++i) {
        maze[i] = new char[C];
    }

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            fin >> maze[i][j];
        }
    }


int scaleVector = 15;
int screenW = scaleVector * C;
int screenH = scaleVector * R;
RenderWindow window(VideoMode(screenW, screenH), "L6C");
Event event;

while (window.isOpen()) {
    window.clear();  // Clear the window before rendering

    // Uncomment this section for rendering using the nested loop
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            RectangleShape rect;
            rect.setSize(Vector2f(scaleVector, scaleVector));
            rect.setPosition(Vector2f(scaleVector * j, scaleVector * i));
            if (maze[i][j] == 'S') {
                rect.setFillColor(Color::Green);
            } else if (maze[i][j] == 'E') {
                rect.setFillColor(Color::Red);
            } else if (maze[i][j] == '#') {
                rect.setFillColor(Color::Black);
            } else {
                rect.setFillColor(Color::White);
            }

            window.draw(rect);
        }
    }

    window.display();

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