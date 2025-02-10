#include "movie.h"

Movie::Movie(const std::string category, const std::string name, double price, int qty, 
    std::string genre, std::string rating)
: Product(category, name, price, qty), genre_(genre), rating_(rating) {}

std::set<std::string> Movie::keywords() const
{
    // add all keyword-containing information to a string 
    std::string wordString = category_ + " " + name_ + " " + genre_;
    
    // extract keywords from the string and add to a set
    std::set<std::string> MovieKeys = parseStringToWords(wordString);

    return MovieKeys;
}

std::string Movie::displayString() const
{
    // <name>
    // Genre: <genre> Rating: <rating>
    // <price> <quantity> left.

    std::string MovieString = 
        name_ + '\n' +
        "Genre: " + genre_ + " Rating: " + rating_ + '\n' +
        std::to_string(price_) + " " + std::to_string(qty_) + " left.";

    return MovieString;
}

void Movie::dump(std::ostream& os) const
{
    Product::dump(os);
    os << genre_ << "\n" << rating_ << std::endl;
}