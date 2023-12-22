#include "string_functions.h"

#include <iostream>
#include <string>


using namespace std;
//Works
unsigned long string_length(const string STR)  {
    unsigned long result = -1;
    result = STR.length();  // set result to the length of the string
    return result;
}
//Works
char string_char_at(const string STR, const int IDX) {
    char result = '\0';

    result = STR.at(IDX);
    return result;
}
//Works
string string_append(const string LEFT, const string RIGHT)  {
    string result = LEFT + RIGHT;

    return result;
}
//Works
string string_insert(const string STR, const string TO_INSERT, const int IDX) {
    string result = STR;

    result = result.insert(IDX,TO_INSERT);
    return result;
}
//Works
size_t string_find(const string STR, const char C)  {
    size_t result = 0;
    result = STR.find(C);
    return result;
}
//Works
string string_substring(const string STR, const int IDX, const int LEN) {
    string result = STR;
    result = STR.substr(IDX,LEN);
    return result;
}
//Works
string string_replace(const string STR, const string TEXT_TO_REPLACE, const string REPLACE_WITH) {
    string result = STR;
    if(result.find(TEXT_TO_REPLACE) <= result.length()) {
        result = result.replace(result.find(TEXT_TO_REPLACE),TEXT_TO_REPLACE.length(),REPLACE_WITH);
    }
    return result;

}
//Words ->42
string string_first_word(const string STR)  {
    string result = STR;

    result = result.substr(0,result.find(' '));
    // TODO 07: set result to the first word from the string
    return result;
}
//Works -
string string_remove_first_word(const string STR)  {
    string result = STR;
    if(result.find(" ") <= result.size()) {
        result = result.substr(result.find(' ') + 1);
    } else {
        return "";
    }
    return result;
}
// ->56
string string_second_word(const string STR)  {
    string result = STR;
    result = string_remove_first_word(result);
    result = string_first_word(result);
    return result;
}
// ->62
string string_third_word(const string STR)  {
    string result = STR;
    result = string_remove_first_word(result);
    result = string_remove_first_word(result);
    result = string_first_word(result);
    return result;
}
// - > 77
string string_nth_word(const string STR, const int N)  {
    string result = STR;
    // TODO 11: set result to be the nth word from the string
    for(int i = 1; i < N; i++) {
        result = string_remove_first_word(result);
    }
    result = string_first_word(result);
    return result;
}
// -> 81
vector<string> string_tokenize(const string STR, const char DELIMINATOR) {
    string hold = STR;
    vector<string> result;
    while(hold.find(DELIMINATOR) <= hold.length()) {
        result.push_back(hold.substr(0,hold.find(DELIMINATOR)));
        hold.erase(0,hold.find(DELIMINATOR)+1);
    }
    result.push_back(hold);
    // TODO 12: split the string by the given deliminator

    return result;
}
// ->86
string string_substitute(const string STR, const char TARGET, const char REPLACEMENT)  {
    string result = STR;
    char c = REPLACEMENT;
    // TODO 13: set result to be the string with all instances of TARGET replaced
    while(result.find(TARGET) <= result.length()) {
        result = result.replace(result.find(TARGET),1,1,c);
    }
    return result;
}

string string_to_lower(const string STR) {
    string result = STR;
    string result2 = "";
    for(size_t i = 0; i < result.length(); i ++) {
        char c = result[i];
        c = putchar (tolower(c));
        result2 += c;
    }
    // TODO 15: convert all characters to upper case

    return result2;
}

string string_to_upper(const string STR) {
    string result = STR;
    string result2 = "";
    for(size_t i = 0; i < result.length(); i ++) {
        char c = result[i];
        c = putchar (toupper(c));
        result2 += c;
    }
    // TODO 15: convert all characters to upper case

    return result2;
}

int string_compare(const string LHS, const string RHS) {
    int result = 0;
    if(LHS.compare(RHS) == 0) {
        result = 0;
    } else if (LHS.compare(RHS) < 0) {
        result = -1;
    } else {
        result = 1;
    }

    return result;
}