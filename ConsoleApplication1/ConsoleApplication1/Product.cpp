#include "Product.h"
#include <iostream>
#include <string>
using namespace std;
Product::Product()
{
	productID = 0;
	name = "";
	price = 0;
}

Product::Product(int id, string n, int p)
{
	productID = id;
	name = n;
	price = p;
}

int Product::get_id()
{
	return productID;
}

void Product::set_new_quantity(int q)
{
	available_quantity = available_quantity - q;
}

int Product::get_quantity()
{
	return available_quantity;
}


