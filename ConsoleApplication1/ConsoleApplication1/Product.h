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
public:
	Product();
	Product(int id,string name,int price);
	virtual void add_product() =0;
	virtual void display() = 0;
	void set_id(int id);
	void set_name(string n);
	void set_price(int p);
	void set_quantity(int q);
	
	int get_id();
	int get_price();
	void set_new_quantity(int q);
	int get_quantity();
	virtual void save(std::ofstream& out) = 0;
	//virtual int get_available_quantity()=0;
};

