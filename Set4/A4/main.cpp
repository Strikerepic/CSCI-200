/* CSCI 200: A4 - SFML: Bubble Bobble
 *
 * Author: Christian Brennan
 *
 * Description:
 *   Made magic balls that bounced around the screen. Changed a few things to make the balls move at a speed that I liked.
 *   Also chagned the threshold the be 7ms for the full 144hz experience. Also made sure the balls will never get stuck no matter 
 *    Where you attempt to spawn them in.  
 * 
 *      Q AND ESC      TO EXIT THE PROGRAM
 * 
 *      LFT-CLICK      SPAWN A BALL WHEREEVER THE MOUSE CURSOR IS
 * 
 *      D              TO DELETE THE LAST PLACED BALL.
 * 
 */


#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include "Bubble.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SFML/System/Clock.hpp>

using namespace sf;
using namespace std;

Bubble genNew();


int main() {
    srand(time(0));
    rand();
    const int THRESHOLD = 7; //We bombin at 144Hz baby!
    Clock programClock;
    Time lastTime = programClock.getElapsedTime();
    Bubble myBubble(0.2,0.2);
    vector<Bubble> ballList;


    for(int i = 0; i < 5000; i++) {
        //Speed Randomizer
        double xRand = 1;
        double yRand = 1;
        if((rand() % 2) == 0) {
            xRand = ((rand()%10))*0.1 +0.02;
        } else {
            xRand = ((rand()%10))*-0.1 -0.02;
        }


        if((rand() % 2) == 0) {
            yRand = ((rand()%10))*0.1 +0.02;;
        } else {
            yRand = ((rand()%10))*-0.1 -0.02;
        }

        //Color Randomizer
        int randCol = rand()%7;
        Color colHold = Color::Red;
        switch(randCol) {
            case 0:
                colHold = Color::Red;
                break;
            case 1:
                colHold = Color(255,165,0);
                break;
            case 2:
                colHold = Color::Yellow;
                break;
            case 3:
                colHold = Color(40,114,51);
                break;
            case 4:
                colHold = Color::Blue;
                break;
            case 5:
                colHold = Color(155,0,255);
                break;
            case 6:
                colHold = Color(185,242,255);
                break;
        }
        //Postion Randomizer
        int randStartX = 0;
        int randStartY = 0;
        randStartX = (rand()%301) + 100;
        randStartY = (rand()%301) + 100;
        //Radius Randomizer
        int randRadi = 1;
        randRadi = (rand()%41) + 10;
        //Construciton and vector placement
        ballList.push_back(Bubble(xRand,yRand,randStartX,randStartY,colHold,randRadi));

    }
    


    // create a window
    int screenW = 1280;
    int screenH = 720;
    RenderWindow window( VideoMode(screenW, screenH), "Bubble Bobble" );
    Event event;
    while( window.isOpen() ) {
        window.clear( Color::Black );

        for(size_t i = 0; i < ballList.size(); i++ ) {
            ballList.at(i).draw(window);
        }

        

            
        

            





        window.display();
        while( window.pollEvent(event) ) {
            if(event.type == Event::Closed) {
                // tell the window to close
                window.close();
            }

            if((sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ) ||(sf::Keyboard::isKeyPressed(sf::Keyboard::Q) ) ) {
                if((event.key.code == sf::Keyboard::Q) || (event.key.code == sf::Keyboard::Escape)) {
                    window.close();
                }
            }


            if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::D) {
                if(!(ballList.size()==0)) { 
                ballList.pop_back();
                }

            }

            if(event.type == sf::Event::MouseButtonPressed) {
                if(event.mouseButton.button == sf::Mouse::Left) {
                //Speed Randomizer
                double xRand = 1;
                double yRand = 1;
                if((rand() % 2) == 0) {
                    xRand = ((rand()%10))*0.1 +0.02;
                } else {
                    xRand = ((rand()%10))*-0.1 ;
                }
                if((rand() % 2) == 0) {
                    yRand = ((rand()%10))*0.1 +0.02;
                } else {
                    yRand = ((rand()%10))*-0.1;
                }
                //Color Randomizer
                int randCol = rand()%7;
                Color colHold = Color::Red;
                switch(randCol) {
                    case 0:
                        colHold = Color::Red;
                        break;
                    case 1:
                        colHold = Color(255,165,0);
                        break;
                    case 2:
                        colHold = Color::Yellow;
                        break;
                    case 3:
                        colHold = Color(40,114,51);
                        break;
                    case 4:
                        colHold = Color::Blue;
                        break;
                    case 5:
                        colHold = Color(155,0,255);
                        break;
                    case 6:
                        colHold = Color(185,242,255);
                        break;
                }

                int randRadi = 1;
                randRadi = (rand()%41) + 10;
                //Postion Randomizer
                int randStartX = event.mouseButton.x;
                int randStartY = event.mouseButton.y;

                
                if(event.mouseButton.x+randRadi >= screenW) {
                    randStartX = event.mouseButton.x - (randRadi+2);
                } else if( event.mouseButton.x-(randRadi+1) <= 0) {
                    randStartX = event.mouseButton.x + (randRadi+2);
                    std::cout << "noticed Poxy X" << std::endl;
                }

                if(event.mouseButton.y+randRadi >= screenH) {
                    randStartY = event.mouseButton.y - (randRadi+2);
                } else if (event.mouseButton.y-(randRadi+1) <= 0) {
                    randStartY = event.mouseButton.y + (randRadi+2);
                    std::cout << "Noticed poxy y" << std::endl;
                }
                
                
                //Radius Randomizer
                //Construciton and vector placement
                ballList.push_back(Bubble(xRand,yRand,randStartX-randRadi,randStartY-randRadi,colHold,randRadi));
                }
            }



        }

            Time currTime = programClock.getElapsedTime();
            if( (currTime - lastTime).asMilliseconds() > THRESHOLD ) {
                for(size_t i = 0; i < ballList.size(); i++) {
                    ballList.at(i).updatePosition(screenW,screenH);
                }
                lastTime = currTime;
        }

    }
    return 0;
}




