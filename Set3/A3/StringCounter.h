#ifndef STRINGCOUNTER_H
#define STRINGCOUNTER_H


#include <string>
#include <vector>

class StringCounter {
public:

    /**
     * @brief Construct a new String Counter object
     * 
     */
    StringCounter();

    /**
     * @brief Read all the words that are in the input stream and store in the private vector of all words
     * 
     */
    void readAllWords(std::istream&, std::string);


    /**
     * @brief For each letter, print out the letter and its corresponding count to the standard out
     * 
     */
    void printLetterCounts(std::ostream&);

    /**
     * @brief Print out the two letters that occur least often and most often to the standard out.
     * 
     */
    void printLetterStats(std::ostream&);

    /**
     * @brief The function will return the private vector of strings.
     * 
     * @return std::vector<std::string> 
     */
    std::vector<std::string> getAllWords();




private:
    std::vector<std::string> _allWords;
    std::vector<unsigned int> _letterCounts;
    unsigned int _totalLetterCount;





};

#endif