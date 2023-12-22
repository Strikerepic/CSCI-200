#ifndef FRAME_H
#define FRAME_H

#include <SFML/Graphics.hpp>


class Frame {
    public:


    /**
     * @brief Construct a new Frame object. Sets everything to 0
     * 
     */
    Frame();


    /**
     * @brief will put in the required info into the frame to have it hold the proper data. 
     * 
     * @throw1 The first throw num pins knoked down
     * @throw2 the second throw num of pins knocked down
     * 
     */
    virtual void setFrameScore(int throw1, int throw2);

    /**
     * @brief This will calculate the score of this frame
     * 
     */
    virtual void calcFrameScore();


    /**
     * @brief Get the Throw1 Pins object
     * 
     * @return int the number of pins knocked down on the first throw
     */
    virtual int getThrow1Pins();



    /**
     * @brief Get the Throw2 Pins object
     * 
     * @return int the number of pins knocked down on the second throw
     */
    virtual int getThrow2Pins();


    /**
     * @brief Get the Strike object
     * 
     * @return true 
     * @return false 
     */
    bool getStrike();


    /**
     * @brief Get the Spare object
     * 
     * @return true there was a spare
     * @return false there was not a spare
     */
    bool getSpare();


    /**
     * @brief Get the Frame Score object
     * 
     * @return int the total score of the frame object
     */
    virtual int getFrameScore();


    /**
     * @brief This will draw the frame object on the screen at cord x,y. Where the cord is the top left part of the screen
     * 
     */
    virtual void draw(sf::RenderTarget& window,int leftX, int topY);


    /**
     * @brief Set the Total Frame Score's data vaule. (Set to 0 Must be handled due to strike counting) Used over the other 1 for spare and strike handling
     * 
     */
    virtual void setTotalFrameScore(int newTotal);


    /**
     * @brief Get the Drawn Frame Width object
     * 
     * @return int gets the width that
     */
    virtual int getDrawnFrameWidth();
    


    /**
     * @brief Get the Drawn Frame Height object
     * 
     * @return int 
     */
    virtual int getDrawnFrameHeight();

    protected:

    int _throw1Pins;
    int _throw2Pins;
    int _totalFrameScore;

    bool _wasStrike;
    bool _wasSpare;

    int _drawnFrameHeight;
    int _drawnFrameWidth;
};


#endif