#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Product
{
protected:
	int productID;
	string name;
	int price;
	int available_quantity;
	static int productCount;
public:
	Product();
	Product(int id,string name,int price);
	virtual void add_product()=0;
	virtual void display() =0;
	void set_id(int id);
	void set_name(string n);
	void set_price(int p);
	void set_quantity(int q);
	void set_new_quantity(int q);
	int get_id();
	int get_price();
	int get_quantity();
	string get_name();
	static int getProductCount();
	virtual void save(std::ofstream& out) = 0;
	friend Product* compareByPrice(Product* a, Product* b);
};

