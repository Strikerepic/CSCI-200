/* Lecture 14/15 - File I/O
 * Reading files - ifstream
 * Writing files - ofstream
 */
#include <iostream>
// 1. include the file stream library


#include <fstream>

#include <iomanip>

using namespace std;
int main() {
    cout << "Working with  Streams\n\n";

/*
    int x,y;
    while(true) { // Or slide 8 in LEC15 // This is for expected data type.
        cin >> x >> y;
        if(!cin.fail()) {break;}  //If cin is all clear Ball the fuck out

        cerr << "Dumbass" << endl;
        cin.clear(); // THis clears the error

        char badChar;
        do {badChar = cin.get(); } while(badChar != '\n');  //Get in the next char until theres the enter/New line. Clears the line for 
        cout << "Enter 2 Ints";
    }

    while(true) {
        char userVal;
        cout << "q to quit";
        cin >> userVal;
        if (userVal == 'q') {break;}

        cout << "Bruv that wasn't right!!!!" << endl;
    }
*/

    
    // 2/3. declare/open the input/output file stream
    ifstream fin("nums.txt");  // Declares and opens it in 1 step. W Shit!
    ofstream fout("nums.out"); //Declare and open output


    ofstream fout2("nums.out", ios::app); // Doesn't clear the file just appeneds it.

    // It will create the file if nums.out doens't exsit. Errors with file already in use or
    // Permission not granted with that file.
    //Close other terminal window to fix the issue 
    
    ifstream fin2;  //Other way
    fin2.open("nums.txt");

    // 4. Check for an error opening the file

    if(fin.fail()) {
        cerr << "Ratio bozo file is in an error state" << endl;
        return -1;  //Just bomb out of the program. -1 Because an error state. We should typically put this in a loop
        // So it could be fixed instead of just exiting
    }

    if(!fout.is_open() || fout.fail()) {
        cerr << "Some bullshit occured" << endl;
        return -1;
    }

    // 5. Read/Write data
    int num = 0, sum = 0;
    int count = 0;
    // REPL to read the input file
        while(!fin.eof()) {
            fin >> num;
            sum += num;
            fout << "The num is " << num << endl;  // fout goes to file now.
            count++;
        }

    // output the sum after the loop
    fout << "The sum is " << sum << endl;
    fout << fixed << setprecision(2) << "The avg is " << ((double)sum/count) << endl;

    // 6. Close the input/output file

    fin.close();
    fout.close();


    return 0;
}


/*
if (cin.fail()) {
    while(true) {
        char a;
        a = cin.get();
        if(a == '\n') {
            break;
        }
    }
}
*/