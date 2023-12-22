#include "StringFilter.h"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

StringFilter::StringFilter() {
    _totalWordCount = 0;
}


void StringFilter::addWords(vector<string> theWordS) {
    vector<string> allCaps;

    for(unsigned int i =0; i < theWordS.size();i++) {
        string temp = "";
        for(size_t j = 0; j < theWordS.at(i).length(); j++) {
            temp += toupper((theWordS.at(i))[j]);
        }
        allCaps.push_back(temp);
    }


    for(unsigned int i = 0; i < allCaps.size(); i++) {
        bool capture = false;
        int saveIndex = -1;
        for(unsigned int j = 0; j < _uniqueWords.size(); j++) {
            if(allCaps.at(i) == _uniqueWords.at(j)) {
                capture = true;
                saveIndex = j;
            }
        }

        if(capture == true) {
            _wordCounts.at(saveIndex) = _wordCounts.at(saveIndex) + 1;
        } else {
            _uniqueWords.push_back(allCaps.at(i));
            _wordCounts.push_back(1);
        }
    }
    
    vector<string> temp(_uniqueWords.size());
    string tempString;
    int tempInt = 0;
    for(unsigned int i = 0; i < _uniqueWords.size(); i ++) {

        for(unsigned int j = i+1; j < _uniqueWords.size() ; j++) {

            if( (_uniqueWords.at(i).compare(_uniqueWords.at(j))) > 0 ) {
                 tempInt  = _wordCounts.at(i);
                 tempString = _uniqueWords.at(i);
                 _uniqueWords.at(i) = _uniqueWords.at(j);
                 _uniqueWords.at(j) = tempString;

                 _wordCounts.at(i) = _wordCounts.at(j);
                 _wordCounts.at(j) = tempInt;
            }
        }
    }

}




void StringFilter::printUniqueWordCounts(ostream& out) {


    unsigned int wordMaxNum = 0;

    for(unsigned int i = 0; i < _wordCounts.size(); i++) {
        if(_wordCounts.at(i) > wordMaxNum) {
            wordMaxNum = _wordCounts.at(i);
        }
    }

    int count = 0;
    while (wordMaxNum != 0) {
        wordMaxNum /= 10;
        ++count;
    }





    unsigned int maxWordSize = 0;
    for(unsigned int i = 0; i < _uniqueWords.size(); i ++) {

        if(maxWordSize < _uniqueWords.at(i).length()) {
            maxWordSize = _uniqueWords.at(i).length();
        }
    }

    for(unsigned int i = 0; i < _uniqueWords.size(); i++) {
        out << left << setw(maxWordSize) <<  _uniqueWords.at(i) << " : " << right << setw(count+1) << _wordCounts.at(i) << endl;
    }
}




void StringFilter::printUniqueWordStats(ostream& out) {
    int totalWords = 0;



    for(unsigned int i = 0; i < _wordCounts.size(); i++) {
        totalWords += _wordCounts.at(i);
    }

    unsigned int wordMaxIndex = 0;
    unsigned int wordMax = 0;
    unsigned int wordMinIndex = 0;
    unsigned int wordMin = INT_MAX-1;
    for(unsigned int i = 0; i < _wordCounts.size(); i++) {
        if(_wordCounts.at(i) > wordMax) {
            wordMax = _wordCounts.at(i);
            wordMaxIndex = i;
        }

        if(_wordCounts.at(i) < wordMin) {
            wordMin = _wordCounts.at(i);
            wordMinIndex = i;
        }
    }

    int maxDis = 0;
    if(_uniqueWords.at(wordMaxIndex).length() > _uniqueWords.at(wordMinIndex).length()) {
        maxDis = _uniqueWords.at(wordMaxIndex).length();
    } else {
        maxDis = _uniqueWords.at(wordMinIndex).length();
    }


    int maxInThis = 1;
    int maxNum = _wordCounts.at(wordMaxIndex);
    while( maxNum > 10 ) {
            maxInThis++;
            maxNum = maxNum/10;
        }
    int someNum = 0;
    if((((static_cast<double>(_wordCounts.at(wordMaxIndex)) / totalWords * 100) > (static_cast<double>(_wordCounts.at(wordMinIndex)) / totalWords) * 100) )) {
        someNum = static_cast<double>(_wordCounts.at(wordMaxIndex)) / totalWords * 100;
    } else {
        someNum = static_cast<double>(_wordCounts.at(wordMinIndex)) / totalWords * 100;
    }


    string doubleString = std::to_string(someNum);

    int totalDigits = doubleString.size() + 6;

    

    out << left << " Most Frequent Word: " << left << setw(maxDis+1) <<  _uniqueWords.at(wordMaxIndex) << right << setw(maxInThis) << _wordCounts.at(wordMaxIndex) << right << " (" << fixed << setprecision(3)  << setw(totalDigits) <<  (static_cast<double>(_wordCounts.at(wordMaxIndex)) / totalWords) * 100 << "%)" << endl;
    out << left << "Least Frequent Word: " << left << setw(maxDis+1) <<  _uniqueWords.at(wordMinIndex) << right << setw(maxInThis) << _wordCounts.at(wordMinIndex) << right << " (" << fixed << setprecision(3)  << setw(totalDigits) <<  (static_cast<double>(_wordCounts.at(wordMinIndex)) / totalWords) * 100 << "%)" << endl;

}


vector<string> StringFilter::getUniqueWords() {
    return _uniqueWords;
}




