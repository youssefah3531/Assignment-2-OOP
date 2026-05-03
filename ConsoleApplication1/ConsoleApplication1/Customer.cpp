#include "Customer.h"
#include <iostream>
#include <string>
using namespace std;

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
