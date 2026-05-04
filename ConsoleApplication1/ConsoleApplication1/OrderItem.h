#pragma once
#include <iostream>
#include "Product.h"
#include "Order.h"
using namespace std;
class OrderItem
{
private:
	Product* product;
	int quantity;
	double unitPriceAtPurchase;
public:
	void setProduct(Product * p);
	void setquantity(int q);
	void setUnitPrice(double price);
	int calculateItemTotal();
	void displayItem();
};

