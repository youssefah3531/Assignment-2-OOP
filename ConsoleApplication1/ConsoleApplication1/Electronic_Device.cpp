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
	if (this->price == E.price)
		return true;
	else
		return false;
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