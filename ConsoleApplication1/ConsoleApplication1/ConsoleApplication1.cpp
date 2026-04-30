#include "Product.h"
#include "Electronic_Device.h"
#include "Office_Supply.h"
#include "Book.h"
#include <iostream>
#include <string>
#include <vector>
#include "Templates.h"
#include "File.h"

using namespace std;

int main()
{
    int mainchoice;

    vector<Product*> products;
    try {
        loadFromFile(products);
    }
    catch (exception& e) {
		cout << "Error loading products: " << e.what() << endl;
    }

    cout << "What do you want to do" << endl;

    do
    {

        try
        {
            cout << "1- Add Product\n2- Display product details\n3- Buy Product\n4- Find Max Price Product\n5- Swap Products\n0- Exit" << endl;
            if (!(cin >> mainchoice))
                throw runtime_error("Invalid input");

            switch (mainchoice)
            {
            case 1:
            {
                int choice;
                cout << "Which Product do you want to add" << endl;
                cout << "1- Book\n2- Electronic Device\n3- Office Supply" << endl;
                if (!(cin >> choice))
                    throw runtime_error("Invalid input");

                Product* p = nullptr;

                    if (choice == 1)
                        p = new Book();
                    else if (choice == 2)
                        p = new Electronic_Device();
                    else if (choice == 3)
                        p = new Office_Supply();
                    else
                        throw runtime_error("Invalid product type");
                p->add_product();
                products.push_back(p);
                break;
            }

            case 2:
            {
                if (products.empty()) {
                    cout << "No products available\n";
                    break;
                }
                for (auto p : products)
                {
                    p->display();
                }
                break;
            }


            case 3:
            {

                if (products.empty())
                    throw runtime_error("No products available");
                for (auto p : products)
                    p->display();
                int id, q;
                cout << "Enter product ID: ";
                if (!(cin >> id))
                    throw runtime_error("Invalid ID");
                bool found = false;
                for (auto p : products) {
                    if (p->get_id() == id) {
                        found = true;
                        cout << "Enter quantity: ";
                        if (!(cin >> q))
                            throw runtime_error("Invalid quantity");
                        if (q <= 0)
                            throw runtime_error("Quantity must be positive");
                        if (q > p->get_quantity())
                            throw runtime_error("Not enough quantity");
                        p->set_new_quantity( q);
                        cout << "Purchased successfully\n";
                        break;
                    }
                }
                if (!found)
                    throw runtime_error("Product not found");
                break;
            }

            case 4:
            {
                if (products.empty())
                    throw runtime_error("No products available");


                Product* maxProduct = findMaxPrice(products);

                cout << "Highest Price Product:\n";
                maxProduct->display();

                break;
            }

            case 5:
            {
                int id1, id2;
                cout << "Enter first product id: ";
                if (!(cin >> id1))
                    throw runtime_error("Invalid ID");
                cout << "Enter second product id: ";
                if (!(cin >> id2))
                    throw runtime_error("Invalid ID");
                int index1 = -1;
                int index2 = -1;
                for (size_t i = 0; i < products.size(); i++)
                {
                    if (products[i]->get_id() == id1)
                        index1 = i;

                    if (products[i]->get_id() == id2)
                        index2 = i;
                }

                if (index1 == -1 || index2 == -1)
                    throw runtime_error("Invalid IDs");

                swapProducts(products[index1], products[index2]);

                cout << "Products swapped successfully\n";
                break;
            }

            case 0:
            {
                cout << "Exiting...\n";
                break;
            }

            default:
            {
                throw runtime_error("Invalid choice");
            }
            }
        }
        catch (exception& e) {
            cout << "Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }

    } while (mainchoice != 0);

    
    try {
    saveToFile(products);
    }
    catch (exception& e) {
        cout << "Error saving products: " << e.what() << endl;
	}

    for (auto p : products)
		delete p;
    return 0;
}