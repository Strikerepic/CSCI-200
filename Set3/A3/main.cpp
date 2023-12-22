/* CSCI 200: Green Eggs and Ham
 *
 * Author: Christian Brennan
 *
 * Description:
 *    Counts the number of occurrences of each word & letter and display the frequencies.
 *    Pulls from texts such as Green Eggs and Ham. The Output can either be displayed to the
 *    terminal in a cout statment or to a file that can be named by the user.
 * 
 * 
 *    Help reviced: Stack-overflow, google, vincent, tyler, sandwhich, dragon, micha.
 * 
 */




#include "processor.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    // get filename to open
    short inputLocation = 0;
    while(true) {
        cout << "Where would you like to read the word data from?" << endl;
        cout << "\t1 - Green Eggs and Ham" << endl;
        cout << "\t2 - Alice in Wonderland" << endl;
        cout << "\t3 - Romeo and Juliet" << endl;
        cout << "\t4 - Enter other filename" << endl;
        cin >> inputLocation;

        // make sure we got a number
        if(!cin.fail()) {
            // check if number was valid or not
            if(inputLocation < 0 || inputLocation > 4) {
                cout << "Please enter a valid choice" << endl;
            } else {
                break;
            }
        } else {
            cin.clear();
            char badChar = ' ';
            do { badChar = cin.get(); } while(badChar != '\n');
        }
    }
    string filename = "";
    switch(inputLocation) {
        case 1: filename = "input/greeneggsandham.txt";    break;
        case 2: filename = "input/aliceChapter1.txt";      break;
        case 3: filename = "input/romeoandjuliet.txt";     break;
        case 4:
            cout << "Enter file to read words from: ";
            cin >> filename;
            break;
    }

    // open file for parsing
    ifstream fileIn;
    fileIn.open(filename);
    if( !fileIn.is_open() ) {
        cerr << "Could not open file \"" << filename << "\" for reading.  Shutting down..." << endl;
        return -1;
    }

    short outputLocation = 0;
    while(true) {
        cout << "Where would you like to print the output?" << endl;
        cout << "\t1 - Standard Out" << endl;
        cout << "\t2 - File" << endl;
        cin >> outputLocation;
        // make sure we got a number
        if(!cin.fail()) {
            // check if number was valid or not
            if(outputLocation < 1 || outputLocation > 2) {
                cout << "Please enter a valid choice" << endl;
            } else {
                break;
            }
        } else {
            cin.clear();
            char badChar = ' ';
            do { badChar = cin.get(); } while(badChar != '\n');
        }
    }

    // user chose to output to standard output
    if(outputLocation == 1) {
        process_data(fileIn, cout);
    } 
    // user wishes to output to a file
    else if(outputLocation == 2) {
        string outputFilename = "";
        cout << "Enter output filename: ";
        cin >> outputFilename;
        ofstream letterFileOut(outputFilename);
        if( !letterFileOut.is_open() ) {
            cerr << "Could not open file \"" << outputFilename << "\" for writing.  Shutting down..." << endl;
            return -2;
        }
        process_data(fileIn, letterFileOut);
        letterFileOut.close();
    }

    return 0;
}