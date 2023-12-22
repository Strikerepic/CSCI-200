#include "StringCounter.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;


StringCounter::StringCounter() {
    _totalLetterCount = 0;
    for(int i = 0; i < 26; i++) {
        _letterCounts.push_back(0);
    }
}


void StringCounter::readAllWords(istream& a, string b){
    vector<char> eliminators;

    for(size_t i = 0; i < b.length(); i ++) {
        eliminators.push_back(b[i]);
    } 

    while(!a.eof()) {
        string goofyWord = "";
        a >> goofyWord;

        string clean = "";

        for(size_t i = 0; i < goofyWord.length(); i++) {
            bool isClean = true;
            for(unsigned int j = 0; j < eliminators.size(); j++) {
                if(goofyWord[i] == eliminators.at(j)) {
                    isClean = false;
                    break;
                }
            }
            if(isClean) {
                clean += goofyWord.at(i);
            }
        }
        if (!clean.empty()) {
            _allWords.push_back(clean);
        }
    }
}


void StringCounter::printLetterCounts(ostream& out) {

    string totalAl = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for(size_t i = 0; i < totalAl.length(); i ++) {

        char tempCompare = totalAl[i];

        for(unsigned int j = 0; j < _allWords.size(); j ++) {

            string wordCompare = _allWords.at(j);

            for(size_t k = 0; k < wordCompare.length(); k++ ) {

                if(toupper(wordCompare[k]) == tempCompare) {
                    _letterCounts.at(i) = _letterCounts.at(i) + 1;
                }
            }
        }
    }

    int maxDigitsInCount = 0;

    for(size_t i = 0; i < _letterCounts.size(); i++) {
        int maxInThis = 1;
        int heldCount = _letterCounts.at(i);
        while( heldCount > 10 ) {
            maxInThis++;
            heldCount = heldCount/10;
        }

        if(maxInThis > maxDigitsInCount) {
            maxDigitsInCount = maxInThis;
        }
    }



    for(unsigned int i = 0; i < totalAl.length(); i++ ) {
        out << left << totalAl[i] << ": " << right << setw(maxDigitsInCount) << _letterCounts.at(i) << " " << endl;
    }

}


void StringCounter::printLetterStats(std::ostream& out) {
    string totalAl = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(unsigned int i = 0; i < _allWords.size(); i ++) {
        _totalLetterCount += _allWords.at(i).length();
    }

    unsigned int letterMaxIndex = 0;
    unsigned int letterMax = 0;
    unsigned int letterMinIndex = 0;
    unsigned int letterMin = INT_MAX-1;

    for(unsigned int i = 0; i < _letterCounts.size(); i++) {

        if(_letterCounts.at(i) > letterMax ) {
            letterMax = _letterCounts.at(i);
            letterMaxIndex = i;
        }

        if(_letterCounts.at(i) < letterMin) {
            letterMin = _letterCounts.at(i);
            letterMinIndex = i;
        }
    }

    string a = to_string(_letterCounts.at(letterMaxIndex));

    out << left << " Most Frequent Letter: " << totalAl[letterMaxIndex] << "  " << right  << setw(a.length()) <<  _letterCounts.at(letterMaxIndex) << " (" << setw(6) << fixed << setprecision(3) << (static_cast<double>(_letterCounts.at(letterMaxIndex)) / _totalLetterCount) *100 << " % )"  << endl;
    out << left << "Least Frequent Letter: " << totalAl[letterMinIndex] << "  " << right  << setw(a.length()) << _letterCounts.at(letterMinIndex) << " (" << setw(6) << fixed << setprecision(3) << (static_cast<double>(_letterCounts.at(letterMinIndex)) / _totalLetterCount) *100 << " % )" << endl;

}

vector<std::string> StringCounter::getAllWords() {
    return _allWords;
}












