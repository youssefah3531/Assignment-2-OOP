#include "Office_Supply.h"

Office_Supply::Office_Supply()
{
}

Office_Supply::Office_Supply(int id, string n, int p, string c, string m):Product(id,n,p)
{
	category = c;
	material = m;
}

void Office_Supply::add_product()
{
	cout << "Enter the Product ID" << endl;
	cin >> productID;
	cout << "Enter the name Supply" << endl;
	cin >> name;
	cout << "Enter the Price" << endl;
	cin >> price;
	cout << "Enter the quantity of this Item" << endl;
	cin >> available_quantity;
	cout << "Enter the Category" << endl;
	cin >> category;
	cout << "Enter the material" << endl;
	cin >> material;
}

void Office_Supply::display()
{
	cout << "----------------------" << endl;
	cout << "Id: " << productID << endl;
	cout << "Name: " << name << endl;
	cout << "Price: " << price << endl;
	cout << "Quantity: " << available_quantity << endl;
	cout << "Category: " << category << endl;
	cout << "Material: " << material << endl;
	cout << "----------------------" << endl;
}

void Office_Supply::save(std::ofstream& out)
{
	out << "Office Supply" << endl;
	out << productID << endl;
	out << name << endl;
	out << price << endl;
	out << available_quantity << endl;
	out << category << endl;
	out << material << endl;
 }

int Office_Supply::operator+(Office_Supply O)
{
	return this->available_quantity + O.available_quantity;
}

bool Office_Supply::operator==(Office_Supply O)
{
	if (this->price == O.price)
		return true;
	else
		return false;
}

ostream& operator<<(ostream& out, Office_Supply O)
{
	out << "Id: " << O.productID << endl;
	out << "Name: " << O.name << endl;
	out << "Price: " << O.price << endl;
	out << "Quantity: " << O.available_quantity << endl;
	out << "Category: " << O.category << endl;
	out << "Material: " << O.material << endl;
	return out;
}
