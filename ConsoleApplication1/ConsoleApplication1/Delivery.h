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
	void displayDeliveryInfo();
};

