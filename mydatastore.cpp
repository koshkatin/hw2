#include "mydatastore.h"

MyDataStore::~MyDataStore()
{
    for (std::set<Product*>::iterator it = products_.begin(); it != products_.end(); ++it) {
        delete *it;
    }
    for (std::set<User*>::iterator it = users_.begin(); it != users_.end(); ++it) {
        delete *it;
    }
}

void MyDataStore::addProduct(Product* p)
{
    products_.insert(p);    ///
}

void MyDataStore::addUser(User* u)
{
    users_.insert(u);   /// 
}

bool MyDataStore::userExists(const std::string u) const
{
    std::set<User*>::iterator it;
    for (it = users_.begin(); it != users_.end(); ++it) {
        if (u == (*it)->getName()) return true;
    }
    return false;
}

User* MyDataStore::findUser(std::string u) const
{
    std::set<User*>::iterator it;
    for (it = users_.begin(); it != users_.end(); ++it) {
        if ((*it)->getName() == u) return *it;
    }
    return NULL;
}

void MyDataStore::addToCart(std::string u, Product* p)
{
    carts_[u].push_back(p);
}

void MyDataStore::showCart(std::string u) 
{
    std::deque<Product*>::iterator it;
    int i = 1;
    for (it = carts_[u].begin(); it != carts_[u].end(); ++it) {
        std::cout << std::endl << i << ".  " << (*it)->displayString() << std::endl;
        ++i;
    }
}

void MyDataStore::buyCart(std::string u)
{
    User* user = findUser(u);

    std::deque<Product*>::iterator it;
    for (it = carts_[u].begin(); it != carts_[u].end(); ++it) {
        if (((*it)->getQty() >= 1) && (user->getBalance() - (*it)->getPrice() >= 0)) {
            carts_[u].pop_front();  // remove from cart
            (*it)->subtractQty(1);  // subtract from stock
            user->deductAmount((*it)->getPrice());  // charge user
        } 
    }
}
std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type)
{
    std::vector<Product*> matchProds;
    std::set<std::string> termsSet(terms.begin(), terms.end()); // Convert vector to set

    for (std::set<Product*>::iterator it = products_.begin(); it != products_.end(); ++it) {
        std::set<std::string> keywords = (*it)->keywords();

        std::set<std::string> matchTerms;
        if (type == 0) { // AND search
            matchTerms = setIntersection(keywords, termsSet);
            if (matchTerms.size() == termsSet.size()) matchProds.push_back(*it);
        }
        else { // OR search
            matchTerms = setIntersection(keywords, termsSet);
            if (!matchTerms.empty()) matchProds.push_back(*it);
        }
    }
    return matchProds;
}

void MyDataStore::dump(std::ostream& ofile)
{
    ofile << "<products>" << "\n";
    std::set<Product*>::iterator pit;
    for (pit = products_.begin(); pit != products_.end(); ++pit){
        (*pit)->dump(ofile); // ? does this call the overriden dump()s ?
    }
    ofile << "</products>" << "\n";

    ofile << "<users>" << "\n";
    std::set<User*>::iterator uit;
    for (uit = users_.begin(); uit != users_.end(); ++uit){
        (*uit)->dump(ofile); // ? does this call the overriden dump()s ?
    }
    ofile << "</users>" << "\n";
}


