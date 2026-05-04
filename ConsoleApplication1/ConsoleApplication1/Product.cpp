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
	productCount++;
}

Product::Product(int id, string n, int p)
{
	if (p < 0)
		throw invalid_argument("Price cannot be negative");
	productID = id;
	name = n;
	price = p;
	available_quantity = 0;
	productCount++;
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
	if (p < 0)
		throw invalid_argument("Price cannot be negative");
	price = p;
}

void Product::set_quantity(int q)
{
	if (q < 0)
		throw invalid_argument("Quantity cannot be negative");
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
	if (q <= 0)
		throw invalid_argument("Quantity must be positive");
	if (q > available_quantity)
		throw runtime_error("Not enough stock");
	available_quantity -= q;
}

int Product::get_quantity()
{
	return available_quantity;
}

string Product::get_name()
{
	return name;
}

int Product::productCount = 0;
int Product::getProductCount()
{
	return productCount;
}

Product* compareByPrice(Product* a, Product* b)
{
	if (a->price > b->price) {
		cout << a->name << " Price: " << a->price << " is more expensive than "
			<< b->name << " Price: " << b->price << "" << endl;
		return a;
	}
	else if (b->price > a->price) {
		cout << b->name << " Price: " << b->price << " is more expensive than "
			<< a->name << " Price: " << a->price << "" << endl;
		return b;
	}
	else {
		cout << a->name << " and " << b->name << " have the same price " << a->price << "" << endl;
		return a;
	}
}
