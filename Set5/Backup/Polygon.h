#ifndef POLYGON_H
#define POLYGON_H


#include <SFML/Graphics.hpp>
#include <Coordinate.h>
#include <cstdlib>

class Polygon {
    public:

    /**
     * @brief  sets the color to white, specifies the number of vertices as 0, sets the vertices array to be a nullptr
     * 
     */
    Polygon();

    /**
     * @brief Destroy the Polygon object
     * 
     */
    virtual ~Polygon();

    /**
     * @brief sets the private color data member
     * 
     */
    void setColor(const sf::Color color);

    /**
     * @brief creates a ConvexShape, sets the points for each coordinate, sets the fill color, draws it to the provided window
     * 
     */
    void draw(sf::RenderTarget& window);

    /**
     * @brief function that sets the corresponding coordinate in the vertices array
     * 
     */
    void setCoordinate(int idx, Coordinate coord);

    /**
     * @brief function that returns true if the set coordinates form the intended polygon
     * 
     * @return true 
     * @return false 
     */
    virtual bool validate() = 0;

    protected:
    int numVert;
    Coordinate* coordArray = nullptr;
    


    private:
    sf::Color theColor;


};



#endif