#ifndef STRINGFILTER_H
#define STRINGFILTER_H

#include <string>
#include <vector>


class StringFilter {

public:

    StringFilter();

    void addWords(std::vector<std::string>);

    void printUniqueWordCounts(std::ostream&);

    void printUniqueWordStats(std::ostream&);

    std::vector<std::string> getUniqueWords();






private:
    std::vector<std::string> _uniqueWords;
    std::vector<unsigned int> _wordCounts;
    unsigned int _totalWordCount;








};

#endif