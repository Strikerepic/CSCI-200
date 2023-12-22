#include "processor.h"
#include "StringCounter.h"
#include "StringFilter.h"

#include <string>
#include <vector>       

using namespace std;

const string PUNCTUATION_TO_REMOVE = "?!.,;:\"()_-'&[]?";

void process_data(istream& in, ostream& out) {
    StringCounter strCtr;

    // read in all the words of a given file
    strCtr.readAllWords( in, PUNCTUATION_TO_REMOVE );
    
    // retrieve a complete listing of all the words read in to this point
    vector<string> allWords = strCtr.getAllWords();

    StringFilter strFilter;

    // add all of the words read in to your string filterer
    strFilter.addWords( allWords );

    // retrieve a complete listing of the set of the unique words present 
    vector<string> uniqueWords = strFilter.getUniqueWords();

    // print out statistics about the contents of the file
    out << "Read in " << allWords.size() << " words" << endl;
    out << "Encountered " << uniqueWords.size() << " unique words" << endl;
    strFilter.printUniqueWordCounts( out );
    strFilter.printUniqueWordStats( out );
    strCtr.printLetterCounts( out );
    strCtr.printLetterStats( out );
}