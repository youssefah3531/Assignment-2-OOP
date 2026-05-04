#include "Electronic_Device.h"
#include <stdexcept>

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
	int p;
	cout << "Enter the Price" << endl;
	cin >> p;
	if (p < 0) throw invalid_argument("Price cannot be negative");
	price = p;
	int q;
	cout << "Enter the quantity of this Item" << endl;
	cin >> q;
	if (q < 0) throw invalid_argument("Quantity cannot be negative");
	available_quantity = q;
	cout << "Enter the brand name" << endl;
	cin >> brand;
	cout << "Enter the warranty period" << endl;
	cin >> warranty;
}

void Electronic_Device::display()
{
	cout << "----------------------" << endl;
	cout << "Type: Electronic Device" << endl;
	cout << "Id: " << productID << endl;
	cout << "Name: " << name << endl;
	cout << "Price: " << price << endl;
	cout << "Quantity: "<<available_quantity<<endl;
	cout << "brand: " << brand <<endl;
	cout << "warranty: " << warranty << endl;
	cout << "----------------------" << endl;
}

 void Electronic_Device::save(std::ofstream& out)
{
	out << "Electronic Device" << endl;
	out << productID << endl;
	out << name << endl;
	out << price << endl;
	out << available_quantity << endl;
	out << brand << endl;
	out << warranty << endl;
 }

 int Electronic_Device::operator+(Electronic_Device E)
 {
	 return this->available_quantity + E.available_quantity;
 }

 bool Electronic_Device::operator==(Electronic_Device E)
 {
	 return this->price == E.price;
 }

 ostream& operator<<(ostream& out, Electronic_Device E)
 {
	 out << "Id: " << E.productID << endl;
	 out << "Name: " << E.name << endl;
	 out << "Price: " << E.price << endl;
	 out << "Quantity: " << E.available_quantity << endl;
	 out << "Brand: " << E.brand << endl;
	 out << "Warranty: " << E.warranty << endl;
	 return out;
 }