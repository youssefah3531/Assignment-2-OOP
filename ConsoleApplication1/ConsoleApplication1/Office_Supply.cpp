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
	cout << "Category: " << category << endl;
	cout << "Material: " << material << endl;
	cout << "----------------------" << endl;
}
