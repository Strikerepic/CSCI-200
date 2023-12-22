/* CSCI 200: The Secret Moosage
 *
 * Author: Christian Brennan
 *
 * Description:
 *    Reads data from an "input file stream" or ifstream object and writes data to an "output file stream" or ofstream object.
 *    "Decrypts" from secret message.txt. The "Enctryption method" is just a letter shift. A->B B-C C->D ect. ~ indicates a " " (Spacebar)
 * 
 *    Help reviced: Stack-overflow and google
 * 
 */




#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    ifstream fileIn("secretMessage.txt"); //Opens and declares

    ofstream fileOut("decipheredMessage.txt"); // Opens and declares

    if(fileIn.fail()) {
        cerr << "Could not open the secret message";
        return -1;
    }

    if(fileOut.fail()) {
        cerr << "Could not open the output file.";
        return -1;
    }

    char c;
    while(!fileIn.eof()) {
        fileIn.get(c);
        if(c == '~') {
            fileOut << " ";
        } else if( c == '\n') {
            fileOut << endl;
        } else {
            c = (char)(c+1);
            fileOut << c;
        }
    }





}