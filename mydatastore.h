#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <map>
#include <deque>
#include "datastore.h"
#include "util.h" 

class MyDataStore : public DataStore
{
public:
    ~MyDataStore() override;
    void addProduct(Product* p) override;
    void addUser(User* u) override;
    bool userExists(const std::string u) const;
    User* findUser(std::string u) const;
    std::vector<Product*> search(std::vector<std::string>& terms, int type) override;
    void dump(std::ostream& ofile) override;

    // -- cart management --
    void addToCart(std::string u, Product* p);
    void showCart(std::string u);
    void buyCart(std::string u);

private:
    std::set<Product*> products_;
    std::set<User*> users_;
    // a map of user carts where carts store pointers to products added to cart
    std::map<std::string, std::deque<Product*>> carts_; 

};

#endif