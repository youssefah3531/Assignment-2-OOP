#pragma once
#include "Product.h"
#include <iostream>
#include <string>
using namespace std;
class Book : public Product
{
private:
	string author;
	int pages_number;
public:
	Book();
	Book(int id,string n,int p ,string a,int pnum);
	void add_product() override;
	void display() override;
};

