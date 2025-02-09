#include "util.h"

void printStringSet(std::set<std::string> myset) 
{
    for (std::set<std::string>::iterator it = myset.begin(); it != myset.end(); ++it){
        std::cout << *it << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    std::string input = "Here's and ex;ample._ss";

    std::set<std::string> out1 = parseStringToWords(input);
    printStringSet(out1);

    std::set<std::string> s1;
    s1.insert("cat");
    s1.insert("apple");
    s1.insert("fruit");
    s1.insert("upheaval");
    s1.insert("mango");

    std::set<std::string> s2;
    s2.insert("hat");
    s2.insert("play");
    s2.insert("apple");
    s2.insert("cat");
    s2.insert("mango");
    s2.insert("corn");
    s2.insert("kill");
    // should give {"cat", "apple", "mango"}
    
    std::set<std::string> out2 = setIntersection(s1, s2);
    printStringSet(out2);

    std::set<std::string> out3 = setUnion(s1, s2);
    printStringSet(out3);


    return 0; 
}