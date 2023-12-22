#ifndef FINALFRAME_H
#define FINALFRAME_H

#include "Frame.h"

class FinalFrame: public Frame {

public:


    /**
     * @brief Construct a new Final Frame object
     * 
     */
    FinalFrame();

    /**
     * @brief Construct a new Final Frame object
     * 
     * @param a Frame Throw 1
     * @param b Throw 2
     * @param c Throw 3
     */
    FinalFrame(int a, int b, int c);


    /**
     * @brief Displays the frame postiton when given top left and right cords
     * 
     * @param window 
     * @param leftX 
     * @param topY 
     */
    void draw(sf::RenderTarget& window,int leftX, int topY) override;


    /**
     * @brief As the name implies it does that No need for 
     * 
     */
    void calcFrameScore() override;


        //No need for a setFrameScoreTotal function here as this frame acts independently of the other 9.

    /**
     * @brief Get the Frame Score objects score
     * 
     * @return int 
     */
    int getFrameScore() override;



protected:

        //Public inheritnace gives us the throw 1 and throw 2.
    int _throw3Pins;
    int _totalFrameScore;              


};

#endif