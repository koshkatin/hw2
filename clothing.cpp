#include "clothing.h"

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, 
    std::string size, std::string brand)
: Product(category, name, price, qty), size_(size), brand_(brand) {}

std::set<std::string> Clothing::keywords() const
{
    // add all keyword-containing information to a string 
    std::string wordString = category_ + " " + name_ + " " + brand_;
    
    // extract keywords from the string and add to a set
    std::set<std::string> ClothingKeys = parseStringToWords(wordString);

    return ClothingKeys;
}

std::string Clothing::displayString() const
{
    // <name>
    // Size: <size> Brand: <brand>
    // <price> <quantity> left.

    std::string ClothingString = 
        name_ + '\n' +
        "Size: " + size_ + " Brand: " + brand_ + '\n' +
        std::to_string(price_) + " " + std::to_string(qty_) + " left.";

    return ClothingString;
}

void Clothing::dump(std::ostream& os) const
{
    Product::dump(os);
    os << size_ << "\n" << brand_ << std::endl;
}