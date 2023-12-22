#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate {
    public:

    /**
     * @brief Construct a new Coordinate object
     * 
     */
    Coordinate();

    /**
     * @brief Construct a new Coordinate object
     * 
     * @param x the x postion
     * @param y the y postion
     */
    Coordinate(double x, double y);


    /**
     * @brief The X cord of the cordinate
     * 
     */
    double x;

    /**
     * @brief The Y cord of the cordinate
     * 
     */
    double y;
};

#endif