#include "Store.h"
#include <iostream>
#include "Product.h"
using namespace std;
void Store::addProduct(Product* p)
{
    products.push_back(p);
}

void Store::addCustomer(Customer*)
{
}

void Store::addOrder(Order*)
{
}

void Store::displayStoreSummary()
{
}
