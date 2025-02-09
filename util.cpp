#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
    // remove all punctuation
    for (size_t i = 0; i < rawWords.size(); ++i){  
        char ch = rawWords[i]; 
        if (std::ispunct(ch)){  // here's an exam:ple_
            rawWords[i] = ' ';  // here s an exam ple
        } 
    }
    convToLower(rawWords);  // lowercase all words
    
    std::istringstream iss(rawWords); // turn the cleaned string into a stream
    std::string word;   // words to add to keywords set
    std::set<std::string> keywords;   // store extracted words in set

    while (iss >> word){
        if (word.size() >= 2) keywords.insert(word);   // add word to set if at least 2 chars
    }

    return keywords;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
