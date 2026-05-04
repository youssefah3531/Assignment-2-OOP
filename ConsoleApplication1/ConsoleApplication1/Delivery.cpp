#include "Delivery.h"


Delivery::Delivery(int id, string addr, double fee, string driver)
{
	if (fee < 0)
		throw invalid_argument("Delivery fee cannot be negative");
	deliveryId = id;
	address = addr;
	deliveryFee = fee;
	driverName = driver;
}

void Delivery::displayDeliveryInfo()
{
	cout << "DeliveryId: " << deliveryId << endl;
	cout << "Address: " << address << endl;
	cout << "DeliveryFee: " << deliveryFee << endl;
	cout << "DriverName: " << driverName << endl;
}

double Delivery::getDeliveryFee()
{
	return deliveryFee;
}
