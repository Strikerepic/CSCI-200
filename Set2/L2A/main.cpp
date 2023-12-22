/* CSCI 200: Fix Loop and Function Errors
 *
 * Author: Christian Brennan
 *
 * Description:
 *    This program illustrates a variety of common loop and function 
 *    errors.  Fix the errors in each section.
 * 
 *   Help reviced: Stack-overflow and google
 *
 */

#include <cstdlib>      // for rand(), srand()
#include <ctime>        // for time()
#include <iostream>     // for cout, cin, endl etc.
using namespace std;

/**
 * @brief adds five to the given parameter
 * @param x integer to be added to
 * @returns parameter plus five
 */
int add_five( int x ) {
    x = x+5;
    return x;
}

/**
 * @brief generates a single random integer number within the expected range
 * @param MIN lower inclusive bound of range
 * @param MAX upper inclusive bound of range
 * @returns random integer within the range [MIN, MAX]
 */
int generate_random_integer(const int MIN, const int MAX) {
    rand();
    rand();
    return rand() % (MAX-MIN + 1) + MIN;
}

/**
 * @brief generates a single random floating point number within the expected range
 * @param MIN lower inclusive bound of range
 * @param MAX upper inclusive bound of range
 * @return random float within the range [MIN, MAX]
 */
float generate_random_float(const float MIN, const float MAX) {
    float a = ((float)rand()/RAND_MAX) * (MAX-MIN+1)+MIN;
    return a;
}

/**
 * @brief sums three integer values
 * @param x first value to be added
 * @param y second value to be added
 * @param z third value to be added
 * @returns the sum of all three parameters
 */
int sum( int x, int y, int z ) {
    return x + y + z;
}

/**
 * @brief multiples two floats together
 * @param a first value to multiply
 * @param b second value to multipl
 * @returns the product of the two float parameters
 */
float multiply( float a, float b ) {
    // fixed the function actually having stuff in it. Bruh. Added the following line. Bruh.
    return a * b;
}

/**
 * @brief runs test summing numbers in the range [1, N]
 */
void loopTest1() {
    // FIX = In the loop added the <= to allow the sum to be inclusive up to value N.
    // TESTS:

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Looping 1 " << endl;
    cout << "******************" << endl;

    int n;  
    cout << "Enter a number greater than 1 to sum up to: ";
    cin >> n;

    int sum;
    for(int i = 1; i <= n; i++) {
         sum += i;
     }
    cout << "The sum of the numbers from 1 to " << n << " (inclusive) is: " << sum << endl;
}

/**
 * @brief runs test summing set of prices entered by the user
 */
void loopTest2() {
    // FIX = Moved the totalPrice = 0; to out of the while loop. Litteraly slapped my face when I saw this error. It took a min for me to see it.
    // TESTS:

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Looping 2 " << endl;
    cout << "******************" << endl;

    int numItems;
    cout << "How many items do you have? ";
    cin >> numItems;
    cout << endl;

    int counter = 1;
    float totalPrice, price;
    totalPrice = 0;
    while (counter <= numItems) {
        cout << "Enter the price of item " << counter << ": ";
        cin >> price;
        totalPrice = totalPrice + price;
        counter++;
    }
    cout << "The total price is: " << totalPrice << endl;
}

/**
 * @brief runs test summing numbers in the range [1, N]
 */
void loopTest3() {
    // FIX = changed the loop condition to counter <= n; (Was orginally coutner <= sum.) Then added counter++; to actually inc the counter each loop through.
    // TESTS:

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Looping 3 " << endl;
    cout << "******************" << endl;

    int n;
    cout << "What number do you wish me to sum to?" << endl;
    cin >> n;

    int sum = 0, counter = 1;
    do {
        sum += counter;
        cout << "Sum so far: " << sum << endl;
        counter++;
    } while (counter <= n);

    cout << endl << "Section III Recap" << endl;

    cout << "I calculated the sum of numbers from 1 to " << n << " (inclusive) as " << sum << endl;
}

/**
 * @brief runs test summing i^2 in the range [1, N]
 */
void loopTest4() {
    // FIX = adjusted the i++ to be i-- instead. So yeah.
    // TESTS:

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Looping 4 " << endl;
    cout << "******************" << endl;

    cout << "I will now calculate the sum of squares from 1 to N (inclusive)" << endl;
    
    int n;
    cout << "Enter N: ";
    cin >> n;

    int sum = 0;
    for (int i = n; i > 0; i--) {
        sum += i*i;
    }

    cout << "The sum of squares from 1 to " << n << " is: " << sum << endl;
}

/**
 * @brief runs test summing i^3 in the range [1, N]
 */
void loopTest5() {
    // FIX = moved counter++ to inside the loop. And changed the looping condtion to allow for values to n not just 10.
    // TESTS: 3. 5 . 4

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Looping 5 " << endl;
    cout << "******************" << endl;

    cout << "I will now calculate the sum of cubes from 1 to N (inclusive)" << endl;

    int n;
    cout << "Enter N: ";
    cin >> n;

    int sum = 0, counter = 1;
    while (counter <= n) {
        sum += (counter * counter * counter);
        counter++;
    }

    

    cout << "The sum of cubes from 1 to " << n << " is: " << sum << endl;
}

/**
 * @brief Prints out a nice little smiley face guy. Awww! :)
 * 
 */
void printSmileyFace() {
    cout << ":)" << endl;
    return;
}

/**
 * @brief runs test using function to add five to an entered value
 */
void functionTest1() {
    // FIX = add_five function adjusted to return an int type instead of void. This allows numTrees=add_five... to work properly
    // TESTS:

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Function 1" << endl;
    cout << "******************" << endl;

    int numTrees;
    cout << "How many trees do you currently have? ";
    cin >> numTrees;
    cout << "There are initially " << numTrees << " trees." << endl;
    numTrees = add_five( numTrees );
    cout << "We planted five trees, there are now " << numTrees << " trees." << endl;
}

/**
 * @brief runs test to call a function that outputs a smiley face to the standard out
 * 
 */
void functionTest2() {
    // FIX = Made a function at the top of this file called printSmileyFace()
    // TESTS:

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Function 2" << endl;
    cout << "******************" << endl;

    printSmileyFace();
}

/**
 * @brief runs test to generate five random integers within a provided range
 */
void functionTest3() {
    // FIX = Adjusted the generate_random_int function to actaully work. Also set the seed to only seed rng once rather than each time the function was called.
    // TESTS:

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Function 3" << endl;
    cout << "******************" << endl;

    int min, max;
    cout << "Enter the minimum integer range value: ";
    cin >> min;
    cout << "Enter the maximum integer range value: ";
    cin >> max;

    cout << "Five different random numbers are: " << endl;
    srand( time(0) );
    for( int i = 0; i < 5; i++ ) {
        cout << "\t" << generate_random_integer(min, max) << endl;
    }
}

/**
 * @brief runs test to use function to sum three values
 */
void functionTest4() {
    // FIX = added the num3 to the parameters of the sum function as it called for 3 parameters and the example code only
    //       provided 2. Also fixed the sum function to addded 1 2 and 3 instead of 1 1 1.
    // TESTS:

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Function 4" << endl;
    cout << "******************" << endl;

    int num1, num2, num3;
    cout << "Enter three integer numbers: ";
    cin >> num1 >> num2 >> num3;
    cout << "The sum of all three is " << sum( num1, num2, num3 ) << endl;
}

/**
 * @brief runs test to generate five random floats within a provided range
 */
void functionTest5() {
    // FIX =
    // TESTS:

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Function 5" << endl;
    cout << "******************" << endl;

    float min, max;
    cout << "Enter the minimum float range value: ";
    cin >> min;
    cout << "Enter the maximum float range value: ";
    cin >> max;
    cout << "Five different random floats are: " << endl;
    for( int i = 0; i < 5; i++ ) {
        cout << "\t" << generate_random_float(min,max) << endl;
    }
}

/**
 * @brief runs test to use function to multiply two provided numbers
 */
void functionTest6() {
    // FIX =
    // TESTS:

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Function 6" << endl;
    cout << "******************" << endl;

    float leftHandSide, rightHandSide;
    cout << "Enter two floats: ";
    cin >> leftHandSide >> rightHandSide;
    cout << "Their product is: " << multiply( leftHandSide, rightHandSide ) << endl;
}

int main() {
    cout << "Welcome To Looping Function World!" << endl;
    
    loopTest1();        // run looping test 1
    loopTest2();        // run looping test 2
    loopTest3();        // run looping test 3
    loopTest4();        // run looping test 4
    loopTest5();        // run looping test 5

    functionTest1();    // run function test 1
    functionTest2();    // run function test 2
    functionTest3();    // run function test 3
    functionTest4();    // run function test 4
    functionTest5();    // run function test 5
    functionTest6();    // run function test 6

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Done" << endl;
    cout << "******************" << endl;

    cout << endl << "Congrats!  You fixed them all (hopefully correctly!)" << endl << endl << "Goodbye" << endl << endl;

    return 0;
}

