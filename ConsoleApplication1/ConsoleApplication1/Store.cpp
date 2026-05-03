#include "Store.h"
#include <iostream>
#include "Product.h"
#include "Customer.h"
#include "PremiumCustomer.h"
#include "RegularCustomer.h"
using namespace std;
void Store::addProduct(Product* p)
{
    products.push_back(p);
}

void Store::addCustomer(Customer*c)
{
    customers.push_back(c);
}

void Store::addOrder(Order*)
{
}

void Store::displayStoreSummary()
{
}
