#ifndef VECTOR_MATH_H
#define VECTOR_MATH_H

/**
 * @brief  Prompts the user to enter an angle and updates the corresponding parameter.
 *  
 * 
 * @param pAngle 
 */
void angle_input(float* pAngle);




/**
 * @brief Prompts the user to input x,y cords
 * 
 * @param xCord pointer to resulting xCord entered by user
 * @param yCord pointer to resulting yCord entered by user
 */
void point_input(float* xCord, float* yCord);



/**
 * @brief User inputs vector <x,y> and sets vecX and vecY
 * 
 * @param vecX pointer to resulting vectorX (cord) entered by user
 * @param vecY pointer to resulting vectorY (cord) entered by user
 */
void vector_input(float* vecX, float* vecY);


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


/**
 * @brief determines angle from vector. Just does simple conversion.
 * 
 * @param vecX this is the vectors X cord
 * @param vecY this is the vectors Y cord
 * @return float angle vector forms with x axis.
 */
float vector_to_angle(float vecX, float vecY);



/**
 * @brief angle then makey vector
 * 
 * @param angleIn inputed angle pointer
 * @param vecX this is the things that vector (Vector x)
 * @param vecY this is vector y part.
 */
void angle_to_vector(float* angleIn, float* vecX, float* vecY);

/**
 * @brief Normalizes the input vector setting the corresponding pointer parameters to the output normalized vector
 * 
 * @param vecX corresponding to the input vector's x coordinate
 * @param vecY corresponding to the input vector's y coordinate
 * @param normVecX pointer corresponding to the output normalized vector's x coordinate
 * @param normVecY pointer corresponding to the output normalized vector's y coordinate
 */
void vector_normalize(float* vecX, float* vecY, float* normVecX, float* normVecY);



/**
 * @brief PERFORMS THE GIGA ROTATION.
 * 
 * @param inputX corresponding to the input point's x coordinate
 * @param inputY corresponding to the input point's y coordinate
 * @param vecInX corresponding to the input vector's x coordinate
 * @param vecInY corresponding to the input vector's y coordinate
 * @param rotatedX pointer corresponding to the output rotated point's x coordinate
 * @param rotatedY pointer corresponding to the output rotated point's y coordinate
 */
void rotate_point_by_vector(float inputX, float inputY, float vecInX, float vecInY, float* rotatedX, float* rotatedY);




#endif