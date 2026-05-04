#pragma once
#include <iostream>
#include "Order.h"
#include <string>
using namespace std;
class Delivery
{
private:
	int deliveryId;
	string address;
	double deliveryFee;
	string driverName;
public:
	Delivery(int id, string addr, double fee, string driver);
	void displayDeliveryInfo();
	double getDeliveryFee();
};

