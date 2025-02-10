#include <sstream>
#include <iomanip>
#include "book.h"
#include "product.h"

Book::Book(const std::string category, const std::string name, double price, int qty, 
                 std::string isbn, std::string author)
    : Product(category, name, price, qty), isbn_(isbn), author_(author) {}

std::set<std::string> Book::keywords() const
{
    // add all keyword-containing information to a string 
    std::string wordString = category_ + " " + name_ + " " + author_;
    
    // extract keywords from the string and add to a set
    std::set<std::string> bookKeys = parseStringToWords(wordString);

    // since ISBN has to be exact, add it separately
    bookKeys.insert(isbn_);

    return bookKeys;
}

std::string Book::displayString() const
{
    // <name>
    // Author: <author> ISBN: <isbn>
    // <price> <quantity> left.

    // ** 2 decimal places for price **
    // std::ostringstream oss;
    // oss << std::fixed << std::setprecision(2) << price_;
    // std::string priceStr = oss.str();

    std::string bookString = 
        name_ + '\n' +
        "Author: " + author_ + " ISBN: " + isbn_ + '\n' +
        std::to_string(price_) + " " + std::to_string(qty_) + " left.";

    return bookString;
}

void Book::dump(std::ostream& os) const
{
    Product::dump(os);
    os << isbn_ << "\n" << author_ << std::endl;
}