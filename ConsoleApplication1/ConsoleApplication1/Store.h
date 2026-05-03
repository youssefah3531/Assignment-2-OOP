#include <iostream>
#include <string>
#include <vector>
#include "Product.h"
#include "Customer.h"
#include "Order.h"
using namespace std;
class Store
{
private:
	string name;
	vector<Product*> products;
	vector<Customer*> customers;
	vector<Order*> orders;
public:
	void addProduct(Product*);
	void addCustomer(Customer*);
	void addOrder(Order*);
	void displayStoreSummary();
};

