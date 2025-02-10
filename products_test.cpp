#include <iostream>
#include <set>
#include "book.h"
#include "clothing.h"
#include "movie.h"

int main() {

    // -------- Book test ---------
    Book book("category", "name", 13.20, 1, "iiii-ssss-bbbb-nnnn", "author"); 
    std::set<std::string> bookwords = book.keywords();

    std::cout << "Book Keywords: ";
    for (const auto& keyword : bookwords) {
        std::cout << keyword << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << book.displayString() << std::endl << std::endl;
    book.dump(std::cout);
    
    std::cout << std::endl;


    // ------ Clothing test -------
    Clothing clothing("clothing", "blouse", 49.99, 2, "XL", "ZARA"); 
    std::set<std::string> clothwords = clothing.keywords();

    std::cout << "Clothing Keywords: ";
    for (const auto& keyword : clothwords) {
        std::cout << keyword << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << clothing.displayString() << std::endl << std::endl;
    clothing.dump(std::cout);
    
    std::cout << std::endl;
    
    // ------- Movie test --------
    Movie movie("movie", "there will be blood", 2.99, 2, "drama", "4.8"); 
    std::set<std::string> moviewords = movie.keywords();

    std::cout << "Movie Keywords: ";
    for (const auto& keyword : moviewords) {
        std::cout << keyword << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << movie.displayString() << std::endl << std::endl;
    movie.dump(std::cout);
    
    std::cout << std::endl;

    return 0;
}