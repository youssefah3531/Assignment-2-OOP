#include "Electronic_Device.h"

Electronic_Device::Electronic_Device()
{
}

Electronic_Device::Electronic_Device(int id, string n, int p, string b, int w):Product(id,n,p)
{
	warranty = w;
	brand = b;
}

void Electronic_Device::add_product()
{
	cout << "Enter the Product ID" << endl;
	cin >> productID;
	cout << "Enter the name of the electronic device" << endl;
	cin >> name;
	cout << "Enter the Price" << endl;
	cin >> price;
	cout << "Enter the quantity of this Item" << endl;
	cin >> available_quantity;
	cout << "Enter the brand name" << endl;
	cin >> brand;
	cout << "Enter the warranty period" << endl;
	cin >> warranty;
}

void Electronic_Device::display()
{
	cout << "----------------------" << endl;
	cout << "Id: " << productID << endl;
	cout << "Name: " << name << endl;
	cout << "Price: " << price << endl;
	cout << "Quantity: "<<available_quantity<<endl;
	cout << "brand: " << brand <<endl;
	cout << "warranty: " << warranty << endl;
	cout << "----------------------" << endl;
}
