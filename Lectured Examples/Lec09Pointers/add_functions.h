#ifndef ADD_FUNCTIONS_H
#define ADD_FUNCTIONS_H

/**
 * @brief sums two doubles
 * 
 * @param LHS left hand side value to add
 * @param RHS right hand side value to add
 * @return double sum of left and right hand sides
 */
double add(const double LHS, const double RHS);  

/**
 * @brief subtracts two doubles
 * 
 * @param LHS left hand side value to subtract
 * @param RHS right hand side value to subtract
 * @return double difference of left and right hand sides
 */
double sub(const double LHS, const double RHS);

/**
 * @brief multiplies two doubles
 * 
 * @param LHS left hand side value to multiply
 * @param RHS right hand side value to multiply
 * @return double product of left and right hand sides
 */
double mult(double, double);

/**
 * @brief divides two doubles
 * 
 * @param LHS numerator
 * @param RHS denominator
 * @return double quotient of numerator divided by denominator
 */
double div(const double LHS, const double RHS);

/**
 * @brief implements floating point modulus operator
 * 
 * @param LHS numerator 
 * @param RHS denominator
 * @return double remainder leftover of numerator / denominator
 */
double mod(const double LHS, const double RHS);

/**
 * @brief prints to standard out the template: "LHS op RHS = result" ending with a newline
 * 
 * @param LHS left hand side value
 * @param OP operator
 * @param RHS right hand side value
 * @param RESULT resultant value
 */
void print_equation(const double LHS, const char OP, const double RHS, const double RESULT);

#endif
