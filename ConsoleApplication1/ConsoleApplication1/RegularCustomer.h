#pragma once
#include <iostream>
#include <string>
#include "Customer.h"
using namespace std;

class RegularCustomer : public Customer {
public:
	void displayInfo() override;
	double calculateDiscount(double amount) override;
};
