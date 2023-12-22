#ifndef CONVERSIONS_H
#define CONVERSIONS_H



/**
 * @brief Converts polar (r, θ) to cartesian (x, y)
 * 
 * @param radius 
 * @param angle 
 * @param xCoordinate The pointer of where xCord is in the heap
 * @param yCoordinate The pointer of where yCord is in the heap
 */
void polar_to_cartesian(double radius, double angle, double* xCoordinate, double* yCoordinate);



/**
 * @brief Converts cartesian (x, y) to polar (r, θ)
 * Now Works
 * @param xCoordinate 
 * @param yCoordinate 
 * @param radius 
 * @param angle 
 */
void cartesian_to_polar(double xCoordinate, double yCoordinate, double* radius, double* angle);


#endif