#pragma once
#include "Product.h"
#include <iostream>
#include <string>
using namespace std;
class Office_Supply : public Product
{
private:
	string category;
	string material;
public:
	Office_Supply();
	Office_Supply(int id, string n, int p, string c, string m);
	void add_product() override;
	void display() override;
};

