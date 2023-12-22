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
    ding.setBuffer(dingSoundeffect);\
    


    if( !enterSoundEffect.openFromFile("assets/EnterSound.mp3")) {
        cerr << "Music Couldn't be located in the assets folder";
    }







    

    mainMenuMusic.play();
    mainMenuMusic.setLoop(true);

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






    int screenW = 1400;
    int screenH = 720;

    int numPlayers = 1;
    bool crazySelect = false;

    Event event1;
    vector<String> mainMenuOpps;
    mainMenuOpps.push_back("Start Game");
    mainMenuOpps.push_back("Change Players:" + to_string(numPlayers));
    mainMenuOpps.push_back("Crazy Mode????: OFF");
    unsigned int mainMenuOppsPosition = 0;


    RenderWindow MainMenu( VideoMode(screenW, screenH), "MainMenu" );
    while (MainMenu.isOpen()) {

        MainMenu.clear(Color::Black);
        MainMenu.draw(mainMenuPict);
        for(size_t i = 0; i < mainMenuOpps.size(); i++) {
            Text holded;
            holded.setFont(myFont);
            holded.setCharacterSize(76);
            holded.setString(mainMenuOpps.at(i));
            holded.setPosition(Vector2f(screenW/2-580,200*i));
            holded.setFillColor(Color::White);
            if(i == mainMenuOppsPosition) {
                holded.setFillColor(Color::Blue);
                holded.setCharacterSize(82);
            }
            if( i == 2) {
                if(crazySelect == false) {
                    holded.setFillColor(Color::Red);
                } else {
                    holded.setFillColor(Color::Green);
                }
            }
            MainMenu.draw(holded);

        }
        MainMenu.display();
        while( MainMenu.pollEvent(event1) ) {
            if(event1.type == Event::KeyPressed && event1.key.code == Keyboard::Down) {
                ding.stop();
                ding.play();
                if(mainMenuOppsPosition == 2) {
                    mainMenuOppsPosition = 0;
                } else {
                    mainMenuOppsPosition++;
                }
            }
            if(event1.type == Event::KeyPressed && event1.key.code == Keyboard::Up) {
                ding.stop();
                ding.play();
                if(mainMenuOppsPosition == 0) {
                    mainMenuOppsPosition = 2;
                } else {
                    mainMenuOppsPosition--;
                }
            }
            if(event1.type == Event::KeyPressed && event1.key.code == Keyboard::Enter) {
                if(mainMenuOppsPosition == 0) {
                    enterSoundEffect.play();
                    sf::sleep( sf::milliseconds(900) );
                    mainMenuMusic.stop();
                    MainMenu.close();

                } else if( mainMenuOppsPosition == 1) {
                    if(numPlayers == 4) {
                        numPlayers = 1;
                    } else {
                        numPlayers++;
                    }
                    mainMenuOpps.at(1) = "Change Players: " + to_string(numPlayers);
                } else {  //MainMenuOppsPosition == 3
                    if(crazySelect == false) {
                        mainMenuOpps.at(2) = "Crazy Mode????: ON";
                    } else {
                        mainMenuOpps.at(2) = "Crazy Mode????: OFF";
                    }
                    crazySelect = !crazySelect;
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



    vector<vector<Frame*>> fullGame;
    for(int i = 0; i < numPlayers; i++) {

        vector<Frame*> held;
        for(int i = 0; i < 10; i++) {
            if(i == 9) {
            held.push_back(new FinalFrame());
            cout << "Pushed final frame;";
            } else {
            held.push_back(new Frame());
            }
        }
        fullGame.push_back(held);
    }




    RectangleShape textHeldRect;
    textHeldRect.setSize( Vector2f(400,50));
    textHeldRect.setPosition(screenW/2-200,625);
    textHeldRect.setFillColor(Color::White);
    textHeldRect.setOutlineColor(Color::Black);
    textHeldRect.setOutlineThickness(2);

    Text whatToInput;
    Text inputed;

    whatToInput.setFont(myFont);
    whatToInput.setCharacterSize(36);
    whatToInput.setFillColor(Color::Black);
    whatToInput.setPosition(screenW/2-190,625);
    whatToInput.setString("P1. Throw 1:");
    inputed.setFont(myFont);
    inputed.setCharacterSize(36);
    inputed.setFillColor(Color::Black);
    inputed.setPosition(screenW/2+75,625);

    RenderWindow window( VideoMode(screenW, screenH), "Bowling" );
    Event event;
    sf::String playerInsText;
    Clock waiter;



    int currentPlayer = 0;
    int currentFrame = 0;
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
            textHeldRect.setFillColor(Color::White);
        }


        for(int i = 0; i < numPlayers; i++) {
            for(unsigned int j = 0; j < fullGame.at(i).size(); j++) {
                int frameWidth = fullGame.at(i).at(j)->getDrawnFrameWidth();
                int frameHeight = fullGame.at(i).at(j)->getDrawnFrameHeight();

                fullGame.at(i).at(j)->draw(window, frameWidth*j+120, frameHeight*i+40);
            }
        }

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

                if(event.text.unicode == 8) { //Does the delete
                    if(!playerInsText.isEmpty()) {
                        playerInsText.erase(playerInsText.getSize()-1,1);
                    }
                } else if (event.text.unicode >= '0' && event.text.unicode <= '9' && playerInsText.getSize() < 2) { //Just adds an int and only and int
                playerInsText+=event.text.unicode;

                } else if (event.text.unicode == '\r') {
                    try {
                            // Convert sf::String to std::wstring
                            std::wstring wideString = playerInsText.toWideString();

                            // Convert std::wstring to std::string
                            std::string str(wideString.begin(), wideString.end());

                            // Convert string to integer
                            int intValue = std::stoi(str);

                            std::cout << "Integer value: " << intValue << std::endl;

                            if(currentFrame < 9) {
                                if(10 < throw1+intValue) {
                                    throw std::invalid_argument("Cheater!");
                                    wow.play();
                                }
                            }
                            if(currentFrame == 9) {
                                if(intValue > 10) {
                                    throw std::invalid_argument("Cheater!");
                                    wow.play();
                                }

                            }
                            
                            if(currentFrame != 9) {

                                if(throwNum == 0) {
                                    throw1 = intValue;
                                    if(throw1 != 10) {
                                        throwNum++;
                                        fullGame.at(currentPlayer).at(currentFrame)->setFrameScore(throw1,throw2);
                                    } else { //-------------------------------------When Strike
                                        if(crazySelect) {
                                            niceStrike.play();
                                        }
                                        fullGame.at(currentPlayer).at(currentFrame)->setFrameScore(throw1,0);
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
                                        throw1 = 0;
                                        throw2 = 0;
                                        
                                        }
                                    } else { 
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

                                whatToInput.setString("P" + to_string(currentPlayer+1) + " Throw " + to_string(throwNum+1) + ":");

                            } else {  //Final Frame Calculations
                                if(throwNum==0){
                                    throw1 = intValue;
                                    fullGame.at(currentPlayer).at(currentFrame) = new FinalFrame(throw1,throw2,throw3); 
                                    cout << "made new ff";
                                    throwNum++;
                                } else if(throwNum == 1) {
                                    throw2 = intValue;
                                    fullGame.at(currentPlayer).at(currentFrame) = new FinalFrame(throw1,throw2,throw3); 
                                    cout << "made new ff2";
                                    if(throw1+throw2 >= 10) {
                                        throwNum++;
                                    } else {
                                        currentPlayer++;
                                        if(!(currentPlayer >= numPlayers)) {
                                            throw1 = 0;
                                            throw2 = 0;
                                            throw3 = 0;
                                            throwNum = 0;
                                        } else {
                                            mainGameMusic.stop();
                                            cout << "Games done";
                                            window.close();
                                            displayEndGame(numPlayers, fullGame);
                                            
                                        }
                                    }
                                } else {
                                    if(throw1+throw2 >= 10) {
                                        throw3 = intValue;
                                        fullGame.at(currentPlayer).at(currentFrame)->calcFrameScore();
                                        fullGame.at(currentPlayer).at(currentFrame) = new FinalFrame(throw1,throw2,throw3); 
                                        cout << "made new ff3";
                                        fullGame.at(currentPlayer).at(currentFrame)->calcFrameScore();
                                        currentPlayer++;
                                        }
                                        if(!(currentPlayer >= numPlayers)) {
                                            throw1 = 0;
                                            throw2 = 0;
                                            throw3 = 0;
                                            throwNum = 0;
                                        } else {
                                            mainGameMusic.stop();
                                            cout << "Games done";
                                            window.close();
                                            displayEndGame(numPlayers, fullGame);
                                            
                                        }
                                    } 
                                    whatToInput.setString("P" + to_string(currentPlayer+1) + " throw " + to_string(throwNum+1) + ":");
                                }



                           



                
        

                        } catch (const std::invalid_argument& e) {
                            std::cerr << "Invalid argument: " << e.what() << std::endl;
                            waiter.restart();
                        } catch (const std::out_of_range& e) {
                            std::cerr << "Out of range: " << e.what() << std::endl;
                            waiter.restart();
                        }
                        
                        
                } else {
                    waiter.restart();
                }
                inputed.setString(playerInsText);
            }
        }
    }


    return 1;
}



void displayEndGame(int numPlayers, vector<vector<Frame*>> completeGame) {

    sf::Music finalGameMusic;

    if( !finalGameMusic.openFromFile("assets/BowlingResultsOSTWiiSports.mp3")) {
        cerr << "Music Couldn't be located in the assets folder";
    }

    finalGameMusic.play();
    finalGameMusic.setLoop(true);
    int screenW = 1400;
    int screenH = 720;


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
        if(sum >= topSum) {
            if(sum > topSum) {
                winningPlayerNum.clear();
                topSum = sum;
            }
            winningPlayerNum += to_string(i+1);
        }
    }
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
        if(winningPlayerNum.length() > 1) {
            string temp = "A Tie! Congrats Players:";
            for(unsigned int i = 0; i < winningPlayerNum.length(); i++) {
                temp += winningPlayerNum.substr(i,1) + " ";
            }
            holded.setString(temp);
        } else {
            holded.setString("Congrats Player:" + winningPlayerNum + " you've won!");
        }

        whereItAt.setString("Box Score saved to game.txt");

        holded.setPosition(Vector2f(50,200));
        holded.setFillColor(Color::White);

        whereItAt.setPosition(50,500);
        whereItAt.setFillColor(Color::White);

        ofstream fout("game.txt");

        for(int i = 0; i < numPlayers; i++) {
            int sum = 0;
            fout << "Player-" << i << "  ";
            for(int j = 0; j < 9; j++) {
                fout << " | " << setw(2) << completeGame.at(i).at(j)->getFrameScore() << "| ";
                sum += completeGame.at(i).at(j)->getFrameScore();
            }
            fout << "Total-" << sum << endl;
        }


        Event event;
        RenderWindow endGame( VideoMode(screenW, screenH), "Games Done" );
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