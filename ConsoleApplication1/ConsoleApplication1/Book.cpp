#include "Book.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;
Book::Book()
{
}

Book::Book(int id, string n, int p, string a, int pnum) :Product(id, n, p)
{
	author = a;
	pages_number = pnum;
}

void Book::add_product() 
{
	cout << "Enter the Product ID" << endl;
	cin >> productID;
	cout << "Enter the name of the book" << endl;
	cin >> name;
	cout << "Enter the Price" << endl;
	int p;
	cin >> p;
	if (p < 0) throw invalid_argument("Price cannot be negative");
	price = p;
	int q;
	cout << "Enter the quantity of this Item"<<endl;
	cin >> q;
	if (q < 0) throw invalid_argument("Quantity cannot be negative");
	available_quantity = q;
	cout << "Enter the author name" << endl;
	cin >> author;
	cout << "Enter the number of pages" << endl;
	cin >> pages_number;
}

void Book::display()
{
	cout << "----------------------" << endl;
	cout << "Type: Book" << endl;
	cout << "Id: " << productID<<endl;
	cout << "Name: " << name << endl;
	cout << "Price: " << price << endl;
	cout << "Quantity: " << available_quantity << endl;
	cout << "Author: " << author << endl;
	cout << "Number of pages is: " << pages_number << endl;
	cout << "----------------------" << endl;
}

void Book::save(std::ofstream& out)
{
	out << "Book" << endl;
	out << productID << endl;
	out << name << endl;
	out << price << endl;
	out << available_quantity << endl;
	out << author << endl;
	out << pages_number << endl;
}

int Book::operator+(Book B)
{
	return this->available_quantity + B.available_quantity;
}

bool Book::operator==(Book B)
{
	return this->price == B.price;
}

ostream& operator<<(ostream& out, Book B)
{
	out << "Id: " << B.productID << endl;
	out << "Name: " << B.name << endl;
	out << "Price: " << B.price << endl;
	out << "Quantity: " << B.available_quantity << endl;
	out << "Author: " << B.author << endl;
	out << "Number of pages is: " << B.pages_number << endl;
	return out;
}
