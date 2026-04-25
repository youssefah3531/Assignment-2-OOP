#include "Book.h"
#include <iostream>
#include <string>
#include <vector>
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
	cin >> price;
	cout << "Enter the quantity of this Item"<<endl;
	cin >> available_quantity;
	cout << "Enter the author name" << endl;
	cin >> author;
	cout << "Enter the number of pages" << endl;
	cin >> pages_number;
}

void Book::display()
{
	cout << "----------------------" << endl;
	cout << "Id: " << productID<<endl;
	cout << "Name: " << name << endl;
	cout << "Price: " << price << endl;
	cout << "Author: " << author << endl;
	cout << "Number of pages is: " << pages_number << endl;
	cout << "----------------------" << endl;
}








