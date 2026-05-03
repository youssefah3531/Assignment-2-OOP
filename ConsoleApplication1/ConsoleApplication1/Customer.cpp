#include "Customer.h"
#include <iostream>
#include <string>
using namespace std;
void Customer::setCustomerId(int i)
{
	customerId = i;
}

void Customer::setCustomerName(string n)
{
	name = n;
}

void Customer::setCustomerPhone(string p)
{
	phone = p;
}

int Customer::getCustomerId()
{
	return customerId;
}

string Customer::getName()
{
	return name;
}

string Customer::getPhone()
{
	return phone;
}
