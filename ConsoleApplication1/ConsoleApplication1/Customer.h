#pragma once
#include <iostream>
#include <string>
using namespace std;
class Customer
{
private:
	int customerId;
	string name;
	string phone;
public:
	int getCustomerId();
	string getName();
	string getPhone();
	virtual void displayInfo() = 0;
	virtual double calculateDiscount(double amount) = 0;
};

