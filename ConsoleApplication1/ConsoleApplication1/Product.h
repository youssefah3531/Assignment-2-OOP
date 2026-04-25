#pragma once
#include <iostream>
#include <string>
using namespace std;
class Product
{
protected:
	int productID;
	string name;
	int price;
	int available_quantity;
public:
	Product();
	Product(int id,string name,int price);
	virtual void add_product()=0;
	virtual void display() = 0;
	int get_id();
	void set_new_quantity(int q);
	int get_quantity();
	//virtual int get_available_quantity()=0;
};

