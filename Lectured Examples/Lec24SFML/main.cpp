#include <iostream>
#include <cmath>
using namespace std;

#include <SFML/Graphics.hpp> 
using namespace sf;




int main() {

    // TODO #1
    RenderWindow window(VideoMode(640,640,32), "SFML EXAMPLE");

    while(window.isOpen()) {
        window.clear( Color::Green );
    

    // TODO #3

        // TODO #6

        CircleShape circ;
        circ.setRadius(20);
        circ.setPosition(45,90);
        circ.setFillColor(Color::Yellow);
        window.draw(circ);


        RenctangleShape rect;

        rect.setSize(Vector2f (150,75)); //Make a 2d vector holding the length and width

        rect.setPosition(115,120);

        rect.setFillColor(Color::Blue);

        window.draw(rect);






        //TEXT~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

        Font myFont;
        if( !myFont.loadFromFile( "data/arial.ttf" ) ) {
            cerr << "Could not load font" << endl;
            return -1;
        }


        Text myLabel;
        myLabel.setFont( myFont );
        myLabel.setString( "Hello World!" );
        myLabel.setFillColor( Color::Black );
        myLabel.setPosition( 400, 150 );

        window.draw( myLabel );



        //Image


        






        // TODO #7

        // TODO #9: 

        // TODO #10

        // TODO #2:
        window.display();

        // TODO #5

        Event event
        while(window.pollEvent(event)) {  //This will monitor for events and 
            if(event.type == Event::Close) { //If its closes
                window.close(); //Close the window
            }
        }
    // TODO #4
    }

    return EXIT_SUCCESS;
}
