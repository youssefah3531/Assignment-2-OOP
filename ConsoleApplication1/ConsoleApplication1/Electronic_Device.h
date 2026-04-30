#pragma once
#include "Product.h"
#include <iostream>
#include <string>
using namespace std;
class Electronic_Device :public Product
{
private:
	string brand;
	int warranty;
public:
	Electronic_Device();
	Electronic_Device(int id, string n, int p, string b, int w);
	void add_product() override;
	void display() override;
	void save(std::ofstream& out) override;
	int operator + (Electronic_Device E);
	bool operator == (Electronic_Device E);
	friend ostream& operator << (ostream& out, Electronic_Device E);
};

