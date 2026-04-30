#include "Product.h"
#include <iostream>
#include <string>
using namespace std;
Product::Product()
{
	productID = 0;
	name = "";
	price = 0;
	available_quantity = 0;
}

Product::Product(int id, string n, int p)
{
	productID = id;
	name = n;
	price = p;
}

void Product::set_id(int id)
{
	productID = id;
}

void Product::set_name(string n)
{
	name = n;
}

void Product::set_price(int p)
{
	price = p;
}

void Product::set_quantity(int q)
{
	available_quantity = q;
}

int Product::get_id()
{
	return productID;
}

int Product::get_price()
{
	return price;
}

void Product::set_new_quantity(int q)
{
	available_quantity = available_quantity - q;
}

int Product::get_quantity()
{
	return available_quantity;
}
