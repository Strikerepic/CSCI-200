/* CSCI 200: Lab L1B: (Random Classification) user selects range for random numbers. Then the number selected is classified.
 *
 * Author: Christian Brennan
 *
 *  User sets the range for a random number generator. Then the number is classified where it is within the inputed range (1 2 3 or 4)
 */



#include <iostream> // For cin, cout, etc.
#include <cmath>
#include <ctime>


using namespace std;

int main() {

    char userInput = 'Y';

    while(userInput != 'N') {
        int userMax;
        int userMin;
        cout << "Enter the minimum value: ";
        cin >> userMin;
        cout << "Enter the maximum value: ";
        cin >> userMax;

        int range = userMax-userMin;




        srand(time(0));
        rand();


        double randNum =  (double)rand()/RAND_MAX * (range) + userMin; 
        // int randNumInt = rand() % (userMax-userMin + 1) + userMin; For integer. Don't forget the +1 to keep it inclusive otherwise only the 1st num is inclusive

        /* Firstly double type cast to the rand() function call to allow for successful float/double division. Then divide by RAND_MAX to get a random double
        * between 0 and 1 inclusive. Then multiply by range (This means that both max and min will be inclusive in random selection if we wanted per say only
        * the first to be inclusive we'd subtract 1 from the range.) Finally we add + userMin to get the lower starting point in the range to start at the us
        * er minimum.
        */

        cout << "A random value is: " << randNum << endl;
        cout << "This is in the ";
        if(randNum>= ( (double)range/4) *3 + userMin ) {     // Huge else if branch that tests the quartile of the range from 4th down to 1st using math to determine if the val is greater
            cout << "fourth quartile";
        } else if (randNum >= ((double)range/4) *2  + userMin ) {
            cout << "third quartile";
        } else if(randNum>= ((double)range/4) *1  + userMin ) {
            cout << "second quartile";
        } else {
            cout << "first quartile";
        } 
        cout << endl;

        cout << "Do you want another random value? (Y/N) ";
        cin >> userInput;
    }


    cout << endl << endl << endl << "Cheese is just a loaf of milk. Goodbye.";




}