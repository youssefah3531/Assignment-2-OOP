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
	void setCustomerId(int i);
	void setCustomerName(string n);
	void setCustomerPhone(string p);
	int getCustomerId();
	string getName();
	string getPhone();
	virtual ~Customer() = default;
	virtual void displayInfo() = 0;
	virtual double calculateDiscount(double amount) = 0;
};

