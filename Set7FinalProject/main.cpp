#include <iostream>
#include "Frame.h"
#include <SFML/Graphics.hpp>
#include <exception>
#include "FinalFrame.h"
#include <SFML/Audio.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <iomanip>

using namespace std;
using namespace sf;

void displayEndGame(int numPlayers, vector<vector<Frame*>> completeGame);

int main() {


    //All of the following untill the next comment of this nature is simply just loading music,text,or pictures. 
    sf::Music mainMenuMusic;

    sf::Music mainGameMusic;

    sf::SoundBuffer dingSoundeffect;

    sf::Music enterSoundEffect;

    sf::Music niceSpare;

    sf::Music niceStrike;

    sf::Music wow;

    if( !mainMenuMusic.openFromFile("assets/MainMenuWiiSports.mp3")) {
        cerr << "Music Couldn't be located in the assets folder";
    }

    if( !mainGameMusic.openFromFile("assets/BowlingOSTWii Sports.mp3")) {
        cerr << "Music Couldn't be located in the assets folder";
    }

    if( !niceSpare.openFromFile("assets/SpareSound.mp3")) {
        cerr << "Music Couldn't be located in the assets folder";
    }

    if( !niceStrike.openFromFile("assets/StrikeSound.mp3")) {
        cerr << "Music Couldn't be located in the assets folder";
    }

    if( !wow.openFromFile("assets/Incorrect.mp3")) {
        cerr << "Music Couldn't be located in the assets folder";
    }

    if( !dingSoundeffect.loadFromFile("assets/menuDing.mp3")) {
        cerr << "Music Couldn't be located in the assets folder";
    }

    Sound ding;
    ding.setBuffer(dingSoundeffect); //Buffer for sound to not store into memory
    
    if( !enterSoundEffect.openFromFile("assets/EnterSound.mp3")) {
        cerr << "Music Couldn't be located in the assets folder";
    }

    mainMenuMusic.play();
    mainMenuMusic.setLoop(true); //Loop it.

    Texture bowlingBack;
        if(!(bowlingBack.loadFromFile("assets\\BNGPic.png"))) {
            cerr << "Coulnd't find the backgroun";
            throw runtime_error("Couldn't find the background");
            return -1;
        }
    Sprite bowlingBackg(bowlingBack);
    bowlingBackg.setScale(Vector2f(0.5,0.5));
    bowlingBackg.setPosition(-10,-10);


    Texture mainMenuPic;
        if(!(mainMenuPic.loadFromFile("assets\\MainMenuPic.jpg"))) {
            cerr << "Coulnd't find the backgroun";
            throw runtime_error("Couldn't find the background");
            return -1;
        }
    Sprite mainMenuPict(mainMenuPic);
    mainMenuPict.setScale(Vector2f(1.9,1.9));
    mainMenuPict.setPosition(-10,-10);


    Font myFont;
    if( !myFont.loadFromFile( "assets/VeraMono.ttf" ) ) {
            cerr << "Couldn't Locate the type font from the data file." << endl;
            throw runtime_error("Could not find type font.");
    }

    //END of file loading for the project



    int const SCREENW = 1400; //Seting screen width to 1400 px
    int const SCREENH = 720;  //setting height.

    int numPlayers = 1;         //This setting is for the number of players as the name implies. Can be up to 4. Modified be SFML below.
    bool crazySelect = false;

    Event event1;
    vector<String> mainMenuOpps;    //Main menu opps. Holds a list of all the options that a user can change/interact with on the main menu screen.
    mainMenuOpps.push_back("Start Game");
    mainMenuOpps.push_back("Change Players:" + to_string(numPlayers));
    mainMenuOpps.push_back("Crazy Mode????: OFF");                          //Crazy mode is for the strike and spare sound effects later down in the mainGameLoop
    unsigned int mainMenuOppsPosition = 0;                                  //This is for where the "Cursor is" is makes the text there blue and larger.


    RenderWindow MainMenu( VideoMode(SCREENW, SCREENH), "MainMenu" );
    while (MainMenu.isOpen()) {

        MainMenu.clear(Color::Black);
        MainMenu.draw(mainMenuPict);
        for(size_t i = 0; i < mainMenuOpps.size(); i++) {
            Text holded;
            holded.setFont(myFont);
            holded.setCharacterSize(76);
            holded.setString(mainMenuOpps.at(i));
            holded.setPosition(Vector2f(SCREENW/2-580,200*i));
            holded.setFillColor(Color::White);                  //Displaying all the text
            if(i == mainMenuOppsPosition) {
                holded.setFillColor(Color::Blue);
                holded.setCharacterSize(82);                    //If cursor is on the main menu ops at i make it bigger and blue.
            }
            if( i == 2) {
                if(crazySelect == false) {
                    holded.setFillColor(Color::Red);
                } else {
                    holded.setFillColor(Color::Green);          //Boolean coloring for the crazy select
                }
            }
            MainMenu.draw(holded);      

        }
        MainMenu.display();
        while( MainMenu.pollEvent(event1) ) {
            if(event1.type == Event::KeyPressed && event1.key.code == Keyboard::Down) {     //Check if key was pressed and it was down. Increments the position of the cursor
                ding.stop();    //Stop->start so the audio plays ASAP on key press
                ding.play();
                if(mainMenuOppsPosition == 2) {
                    mainMenuOppsPosition = 0;       //For looping (At the bottom cursor returns to the top)
                } else {
                    mainMenuOppsPosition++;    
                }
            }
            if(event1.type == Event::KeyPressed && event1.key.code == Keyboard::Up) {   //Check if key was pressed and it was ip. decrements the position of the cursor
                ding.stop();
                ding.play();
                if(mainMenuOppsPosition == 0) {
                    mainMenuOppsPosition = 2;       //Looping again so from the top snaps to bottom of the list.
                } else {
                    mainMenuOppsPosition--;  
                }
            }
            if(event1.type == Event::KeyPressed && event1.key.code == Keyboard::Enter) {
                if(mainMenuOppsPosition == 0) {                   //If on the start block.
                    enterSoundEffect.play();                
                    sf::sleep( sf::milliseconds(900) );
                    mainMenuMusic.stop();       
                    MainMenu.close();                             //Close and open the next window for the maingame

                } else if( mainMenuOppsPosition == 1) {            //For the player numbers
                    if(numPlayers == 4) {                          //Player number limit. Modify this number if you want to exceed the 4 player limit.
                        numPlayers = 1;
                    } else {
                        numPlayers++;
                    }
                    mainMenuOpps.at(1) = "Change Players: " + to_string(numPlayers);        //Sets the string in MMOps to be the number of players so it changes
                } else {  //MainMenuOppsPosition == 3
                    if(crazySelect == false) {      
                        mainMenuOpps.at(2) = "Crazy Mode????: ON";
                    } else {
                        mainMenuOpps.at(2) = "Crazy Mode????: OFF";
                    }
                    crazySelect = !crazySelect;                                             //Swaps crazy select
                }
            }
            
            if(event1.type == Event::Closed) {
                // tell the window to close
                mainMenuMusic.stop();
                MainMenu.close();
                return 1;
            }
        }

    }



    vector<vector<Frame*>> fullGame;                            // 2d Vector Rows =  Each player         Columns = each frame
    for(int i = 0; i < numPlayers; i++) {                       

        vector<Frame*> held;
        for(int i = 0; i < 10; i++) {
            if(i == 9) {
            held.push_back(new FinalFrame());
            // cout << "Pushed final frame;";
            } else {
            held.push_back(new Frame());
            }
        }
        fullGame.push_back(held);
    }                                                            //Pushing the frames to the vector.




    RectangleShape textHeldRect;
    textHeldRect.setSize( Vector2f(400,50));
    textHeldRect.setPosition(SCREENW/2-200,625);
    textHeldRect.setFillColor(Color::White);
    textHeldRect.setOutlineColor(Color::Black);
    textHeldRect.setOutlineThickness(2);                       //Rectange where the text for the inputed frames remains    

    Text whatToInput;
    Text inputed;

    whatToInput.setFont(myFont);
    whatToInput.setCharacterSize(36);
    whatToInput.setFillColor(Color::Black);
    whatToInput.setPosition(SCREENW/2-190,625);
    whatToInput.setString("P1. Throw 1:");
    inputed.setFont(myFont);
    inputed.setCharacterSize(36);
    inputed.setFillColor(Color::Black);
    inputed.setPosition(SCREENW/2+75,625);                      //Setting font and position for the aformentioned text.

    RenderWindow window( VideoMode(SCREENW, SCREENH), "Bowling" );
    Event event;
    sf::String playerInsText;
    Clock waiter;                                               //Used for the red blinky red square to tell you that ya goofed



    int currentPlayer = 0;              //Keep track of the current player
    int currentFrame = 0;               //Keep track of the current frame
    int throw1 = 0;
    int throw2 = 0;
    int throw3 = 0;

    int throwNum = 0;

    mainGameMusic.play();
    mainGameMusic.setLoop(true);

    while( window.isOpen() ) {
        window.clear( Color::Black );
        window.draw(bowlingBackg);

        if(waiter.getElapsedTime().asSeconds() < 0.25) {
            textHeldRect.setFillColor(Color::Red);
        } else {
            textHeldRect.setFillColor(Color::White);        //This is for setting the rectange to red only for a breif (0.25s time)
        }


        for(int i = 0; i < numPlayers; i++) {
            for(unsigned int j = 0; j < fullGame.at(i).size(); j++) {
                int frameWidth = fullGame.at(i).at(j)->getDrawnFrameWidth();
                int frameHeight = fullGame.at(i).at(j)->getDrawnFrameHeight();

                fullGame.at(i).at(j)->draw(window, frameWidth*j+120, frameHeight*i+40);
            }
        }                                                                                   //Those 2 loops yeah. Thats all for drawing the frames. The rest is input handling.

        window.draw(textHeldRect);
        window.draw(whatToInput);
        window.draw(inputed);
        window.display();

        while( window.pollEvent(event) ) {
            if(event.type == Event::Closed) {
                // tell the window to close
                mainGameMusic.stop();
                window.close();
                return 1;
            }
            if(event.type == Event::TextEntered) {

                if(event.text.unicode == 8) { //Does the delete. Deletes keys when backspace is pressed.
                    if(!playerInsText.isEmpty()) {
                        playerInsText.erase(playerInsText.getSize()-1,1);
                    }
                } else if (event.text.unicode >= '0' && event.text.unicode <= '9' && playerInsText.getSize() < 2) { //Just adds only numbers. Unicode between 0 9.
                playerInsText+=event.text.unicode;                                                                  //Concates them

                } else if (event.text.unicode == '\r') {                                                            //When return key is pressed
                    try {
                            // Convert sf::String to std::wstring
                            std::wstring wideString = playerInsText.toWideString();

                            // Convert std::wstring to std::string
                            std::string str(wideString.begin(), wideString.end());

                            // Convert string to integer
                            int intValue = std::stoi(str);

                            // std::cout << "Integer value: " << intValue << std::endl;                             //Catch's at the bottom.

                            if(currentFrame < 9) {
                                if(10 < throw1+intValue) {
                                    throw std::invalid_argument("Too Many Pins Per Frame!");                                    //So you can't bowl more then 10 pins per frame.
                                    wow.play();
                                }
                            }
                            if(currentFrame == 9) {                                                             //Exception for the final frame. you can bowl 30 pins. only 10 per throw tho.
                                if(intValue > 10) {
                                    throw std::invalid_argument("Too Many Pins Per Frame!");
                                    wow.play();
                                }

                            }
                            
                            if(currentFrame != 9) {                                                            //Regular gameplay loop frames 1-9.

                                if(throwNum == 0) {
                                    throw1 = intValue;
                                    if(throw1 != 10) {
                                        throwNum++;
                                        fullGame.at(currentPlayer).at(currentFrame)->setFrameScore(throw1,throw2);
                                    } else { //-------------------------------------When Strike
                                        if(crazySelect) {   //Here's crazy slect from earlier.
                                            niceStrike.play();
                                        }
                                        fullGame.at(currentPlayer).at(currentFrame)->setFrameScore(throw1,0);           //Sets the following. (Display text for frames handled in the frame class. This means somthing there)
                                        fullGame.at(currentPlayer).at(currentFrame)->calcFrameScore();                  //Auto calcs score. Modified by the next lines.



                                        if(currentFrame > 0 && fullGame.at(currentPlayer).at(currentFrame-1)->getStrike() && !fullGame.at(currentPlayer).at(currentFrame)->getStrike()) {           //If single strike followed by another strike followed by a regular frame
                                            fullGame.at(currentPlayer).at(currentFrame-1)->setTotalFrameScore( 10 + fullGame.at(currentPlayer).at(currentFrame)->getThrow1Pins() + fullGame.at(currentPlayer).at(currentFrame)->getThrow2Pins());
                                        }

                                        if(currentFrame > 1 && fullGame.at(currentPlayer).at(currentFrame-2)->getStrike() && fullGame.at(currentPlayer).at(currentFrame-1)->getStrike()) {          //If 3 strikes back to back to back
                                            fullGame.at(currentPlayer).at(currentFrame-2)->setTotalFrameScore(10 + 10 + fullGame.at(currentPlayer).at(currentFrame)->getThrow1Pins());
                                        }


                                        if(currentFrame > 0 && fullGame.at(currentPlayer).at(currentFrame-1)->getSpare()) {                                                                         //Spare calculation. Only 1 throw so no extra condtions need to be checked
                                            fullGame.at(currentPlayer).at(currentFrame-1)->setTotalFrameScore(10+fullGame.at(currentPlayer).at(currentFrame)->getThrow1Pins());
                                        }

                                        if(currentPlayer == numPlayers-1) {             //Changes to next frame otherwise moves on to next player
                                            currentFrame++;
                                            currentPlayer=0;
                                        } else {
                                            currentPlayer++;
                                        }
                                        throw1 = 0;
                                        throw2 = 0;                                     //Resets throws (Number of pins knocked down per)
                                        
                                        }
                                    } else {                                           //Following is for the second throw. Need to have it structured like this because a strike is 1 throw and can change to the next player or frame.  A second throw can do the same. Annoying but it is what it is.
                                        throw2 = intValue;
                                        throwNum=0;
                                        fullGame.at(currentPlayer).at(currentFrame)->setFrameScore(throw1,throw2);
                                        fullGame.at(currentPlayer).at(currentFrame)->calcFrameScore();


                                        
                                        if(currentFrame > 0 && fullGame.at(currentPlayer).at(currentFrame-1)->getStrike() && !fullGame.at(currentPlayer).at(currentFrame)->getStrike()) {
                                            fullGame.at(currentPlayer).at(currentFrame-1)->setTotalFrameScore( 10 + fullGame.at(currentPlayer).at(currentFrame)->getThrow1Pins() + fullGame.at(currentPlayer).at(currentFrame)->getThrow2Pins());
                                        }

                                        if(currentFrame > 1 && fullGame.at(currentPlayer).at(currentFrame-2)->getStrike() && fullGame.at(currentPlayer).at(currentFrame-1)->getStrike()) {
                                            fullGame.at(currentPlayer).at(currentFrame-2)->setTotalFrameScore(10 + 10 + fullGame.at(currentPlayer).at(currentFrame)->getThrow1Pins());
                                        }


                                        if(currentFrame > 0 && fullGame.at(currentPlayer).at(currentFrame-1)->getSpare()) {
                                            fullGame.at(currentPlayer).at(currentFrame-1)->setTotalFrameScore(10+fullGame.at(currentPlayer).at(currentFrame)->getThrow1Pins());
                                        }
                                    
                                        if(currentPlayer == numPlayers-1) {
                                            currentFrame++;
                                            currentPlayer=0;
                                        } else {
                                            currentPlayer++;
                                        }

                                        if( ( throw1 + throw2 == 10) && crazySelect ) {
                                            niceSpare.play();
                                        }

                                        throw1 = 0;
                                        throw2 = 0;
                                        
                                    }

                                whatToInput.setString("P" + to_string(currentPlayer+1) + " Throw " + to_string(throwNum+1) + ":");          //Changes the text to be displayed for UI & UX. Player doesnt need to know whats going on. This program does that for you.

                            } else {  //Final Frame Calculations
                                if(throwNum==0){                                                                            //Always allowed to bowl the final frame.
                                    throw1 = intValue;
                                    fullGame.at(currentPlayer).at(currentFrame) = new FinalFrame(throw1,throw2,throw3); 
                                    // cout << "made new ff";
                                    throwNum++;
                                    if(throw1 == 10 && crazySelect) {
                                        niceStrike.play();
                                    }
                                } else if(throwNum == 1) {                                                                 //Second throw
                                    throw2 = intValue;
                                    fullGame.at(currentPlayer).at(currentFrame) = new FinalFrame(throw1,throw2,throw3); 
                                    // cout << "made new ff2";
                                    if(throw1+throw2 >= 10 ) {           //If you bowled a spare allow player to bowl another final throw. Else calc score for final frame and exit this itteration.
                                        if(throw2 == 10 && crazySelect) {
                                            niceStrike.play();
                                        } else if(throw1+throw2 == 10 && crazySelect) {
                                            niceSpare.play();
                                        }
                                        throwNum++;
                                    } else {

                                        if(fullGame.at(currentPlayer).at(currentFrame-1)->getStrike()) {
                                            fullGame.at(currentPlayer).at(currentFrame-1)->setTotalFrameScore(10+throw1+throw2);
                                        }

                                        if(fullGame.at(currentPlayer).at(currentFrame-2)->getStrike() && fullGame.at(currentPlayer).at(currentFrame-1)->getStrike()) {
                                            fullGame.at(currentPlayer).at(currentFrame-2)->setTotalFrameScore(10+10+throw1);
                                        } 

                                        currentPlayer++;
                                        if(!(currentPlayer >= numPlayers)) {
                                            throw1 = 0;
                                            throw2 = 0;
                                            throw3 = 0;
                                            throwNum = 0;
                                        } else {                                //If all done stop everything.
                                            mainGameMusic.stop();
                                            // cout << "Games done";
                                            window.close();
                                            displayEndGame(numPlayers, fullGame);
                                            
                                        }
                                    }
                                } else {                                                                        //Final Throw (Throw 3)
                                    if(throw1+throw2 >= 10) {                                                   //If allowed
                                        throw3 = intValue;
                                        if(throw3 == 10 && crazySelect) {
                                            niceStrike.play();
                                        }
                                        fullGame.at(currentPlayer).at(currentFrame)->calcFrameScore();
                                        fullGame.at(currentPlayer).at(currentFrame) = new FinalFrame(throw1,throw2,throw3); 
                                        //cout << "made new ff3";
                                        fullGame.at(currentPlayer).at(currentFrame)->calcFrameScore();
                                        if(fullGame.at(currentPlayer).at(currentFrame-1)->getStrike()) {
                                            fullGame.at(currentPlayer).at(currentFrame-1)->setTotalFrameScore(10+throw1+throw2);
                                        }

                                        if(fullGame.at(currentPlayer).at(currentFrame-2)->getStrike() && fullGame.at(currentPlayer).at(currentFrame-1)->getStrike()) {      //If frame 9 was a strike then we need to take into account the pins collected here.
                                            fullGame.at(currentPlayer).at(currentFrame-2)->setTotalFrameScore(10+10+throw1);
                                        } 
                                        currentPlayer++;
                                        }

                                    if(!(currentPlayer >= numPlayers)) {                //If outa players end the game
                                        throw1 = 0;
                                        throw2 = 0;
                                        throw3 = 0;
                                        throwNum = 0;
                                    } else {
                                        mainGameMusic.stop();                           //Stop everything
                                        // cout << "Games done";
                                        window.close();
                                        displayEndGame(numPlayers, fullGame);
                                            
                                    }
                                    } 

                                    whatToInput.setString("P" + to_string(currentPlayer+1) + " throw " + to_string(throwNum+1) + ":");      //Set string each time. Allow for throw 3 to be displayed

                            }



                           

                        } catch (const std::invalid_argument& e) {                          //All the catches if a player tries to enter anything other than numbers. Or anything else not allowed
                            // std::cerr << "Invalid argument: " << e.what() << std::endl;
                            waiter.restart();
                        } catch (const std::out_of_range& e) {
                            // std::cerr << "Out of range: " << e.what() << std::endl;
                            waiter.restart();
                        }               
                        
                        
                } else {
                    waiter.restart();                                                       //Restart blinky red rectangle for UI & UX to tell player what they did was wrong!
                }
                inputed.setString(playerInsText);                                           //Display what the player typed in
            }
        }
    }


    return 1;
}



void displayEndGame(int numPlayers, vector<vector<Frame*>> completeGame) {              //Didn't want the code to get tooooo bad. Made this function to call on the games completion. This does the SFML and txt output

    sf::Music finalGameMusic;
    //Loading more music
    if( !finalGameMusic.openFromFile("assets/BowlingResultsOSTWiiSports.mp3")) {
        cerr << "Music Couldn't be located in the assets folder";
    }

    finalGameMusic.play();
    finalGameMusic.setLoop(true);
    int SCREENW = 1400;
    int SCREENH = 720;

    //Loading more picutues
    Texture bowlingBack;
        if(!(bowlingBack.loadFromFile("assets\\Finished.png"))) {
            cerr << "Coulnd't find the backgroun";
            throw runtime_error("Couldn't find the background");
        }

    Sprite bowlingBackg(bowlingBack);
    bowlingBackg.setScale(Vector2f(0.52,0.52));
    bowlingBackg.setPosition(0,0);

    string winningPlayerNum;
    int sum = 0;
    int topSum = 0;
    for(int i = 0; i < numPlayers; i++) {
        sum = 0;
        for(int j = 0; j < 9; j++) {
            sum += completeGame.at(i).at(j)->getFrameScore();
        }
        if(sum >= topSum) {                                         //Determine who had the highest score by summing together all of the total frame scores.
            if(sum > topSum) {
                winningPlayerNum.clear();
                topSum = sum;
            }
            winningPlayerNum += to_string(i+1);                     //Concate it to a list if there is a tie.
        }
    }
    
    //Loading a font
    Font myFont;
    if( !myFont.loadFromFile( "assets/VeraMono.ttf" ) ) {
            cerr << "Couldn't Locate the type font from the data file." << endl;
            throw runtime_error("Could not find type font.");
    }
        Text holded;
        holded.setFont(myFont);
        holded.setCharacterSize(70);
        Text whereItAt;
        whereItAt.setFont(myFont);
        whereItAt.setCharacterSize(70);
        if(winningPlayerNum.length() > 1) {                                     //Handling for cases that involve ties 
            string temp = "A Tie! Congrats Players:";
            for(unsigned int i = 0; i < winningPlayerNum.length(); i++) {
                temp += winningPlayerNum.substr(i,1) + " ";
            }
            holded.setString(temp);
        } else {                                                                //Just a simple win.
            holded.setString("Congrats Player:" + winningPlayerNum + " you've won!");
        }

        whereItAt.setString("Box Score saved to game.txt");

        holded.setPosition(Vector2f(50,200));
        holded.setFillColor(Color::White);

        whereItAt.setPosition(50,500);
        whereItAt.setFillColor(Color::White);

        ofstream fout("game.txt");
        fout << "P#:       ";
        for(int i = 0; i < 10; i++) {
            fout << " | " << setw(2) << left << i+1 << "| ";                                           //Setting up the file out to have the frame numbers on top.
        }
        fout << endl;

        for(int i = 0; i < numPlayers; i++) {                                                   //File O stuffs.
            int sum = 0;
            fout << "Player-" << i << "  ";
            for(int j = 0; j < 10; j++) {
                fout << " | " << setw(2) << completeGame.at(i).at(j)->getFrameScore() << "| ";
                sum += completeGame.at(i).at(j)->getFrameScore();
            }
            fout << "Total-" << sum << endl;                                                //Displays frame scores and player numbers. 
        }


        Event event;
        RenderWindow endGame( VideoMode(SCREENW, SCREENH), "Games Done" );                   //Display the SFML last and call it a day. Whoo! 
        while( endGame.isOpen() ) {
            endGame.clear( Color::Black );
            endGame.draw(bowlingBackg);
            endGame.draw(holded);
            endGame.draw(whereItAt);


            endGame.display();


            while( endGame.pollEvent(event) ) {
                if(event.type == Event::Closed) {
                    // tell the window to close
                    endGame.close();
                }
            }
            }

}