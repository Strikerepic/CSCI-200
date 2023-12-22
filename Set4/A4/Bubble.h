#ifndef BUBBLE_H
#define BUBBLE_H

#include <SFML/Graphics.hpp>



class Bubble {
    public:

    /**
    * @brief Construct a new Bubble object
    * 
    */
    Bubble();

    /**
     * @brief Construct a new Bubble object
     * 
     * @param xDir input for xdir
     * @param yDir same thing as above
     */
    Bubble(double xDir, double yDir);

    /**
     * @brief Construct a new Bubble object
     * 
     * @param xDir input for xdir
     * @param yDir same thing as above
     * @param xStart This places the starting point of the ball X cord
     * @param yStart ycord
     */
    Bubble(double xDir, double yDir, int xStart, int yStart);

    /**
     * @brief Construct a new Bubble object
     * 
     * @param xDir input for xdir
     * @param yDir same thing as above
     * @param xStart This places the starting point of the ball X cord
     * @param yStart ycord
     * @param ballColor the color of the ball. Use a color object from the SFML lib.
     * @param ballRadius radius of the ball. Bigger = easier to hit.
     */
    Bubble(double xDir, double yDir, int xStart, int yStart, sf::Color ballColor, int ballRadius);

    /**
     * @brief 
     * 
     * @return double of Xdir
     */
    double getXDir();


    /**
     * @brief 
     * 
     * @return double of yDir
     */
    double getYDir();


    /**
     * @brief The function then draws the CircleShape member of the class.
     * 
     * @param window accepts an SFML RenderWindow object by reference.
     */
    void draw(sf::RenderWindow &window);


    /**
     * @brief Moves the ball
     * 
     * @param windowW used to reverse direction when a wall is hit
     * @param windowH 
     */
    void updatePosition(int windowW, int windowH);

    private:

    /**
     * @brief This is the radius of the ball
     * 
     */
    int _ballRadius;


    /**
     * @brief As the name implies this is the color of the ball
     * 
     */
    sf::Color _ballColor;

    /**
     * @brief used to draw the Bubble
     * 
     */
    void _circleShape();

    /**
     * @brief These will hold the vector speeds for the balls
     * 
     */
    double _xDir;
    double _yDir;

    /**
     * @brief Is the circle.
     * 
     */
    sf::CircleShape _theCircle;
    
};













#endif