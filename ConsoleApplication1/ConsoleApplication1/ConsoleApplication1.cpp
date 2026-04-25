#include "Product.h"
#include "Electronic_Device.h"
#include "Office_Supply.h"
#include "Book.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int mainchoice;
    int choice;
    int displaychoice;
    int id;
    int buyquantity;

    vector<Product*> products;

    cout << "What do you want to do" << endl;

    do
    {
        cout << "1- Add Product\n2- Display product details\n3- Buy Product\n0- Exit" << endl;
        cin >> mainchoice;

        switch (mainchoice)
        {
        case 1:
        {
            cout << "Which Product do you want to add" << endl;
            cout << "1- Book\n2- Electronic Device\n3- Office Supply" << endl;
            cin >> choice;

            switch (choice)
            {
            case 1:
            {
                Product* b = new Book();
                b->add_product();
                products.push_back(b);
                break;
            }
            case 2:
            {
                Product* e = new Electronic_Device();
                e->add_product();
                products.push_back(e);
                break;
            }
            case 3:
            {
                Product* o = new Office_Supply();
                o->add_product();
                products.push_back(o);
                break;
            }
            default:
            {
                cout << "Invalid input";
                break;
            }
            }
            break;
        }

        case 2:
        {
            cout << "Which Product do you want to display:" << endl;
            cout << "1- Book\n2- Electronic Device\n3- Office Supply" << endl;
            cin >> displaychoice;

            switch (displaychoice)
            {
            case 1:
            {
                for (auto p : products)
                {
                    Book* b = dynamic_cast<Book*>(p);
                    if (b != nullptr)
                    {
                        b->display();
                    }
                }
                break;
            }
            case 2:
            {
                for (auto p : products)
                {
                    Electronic_Device* e = dynamic_cast<Electronic_Device*>(p);
                    if (e != nullptr)
                    {
                        e->display();
                    }
                }
                break;
            }
            case 3:
            {
                for (auto p : products)
                {
                    Office_Supply* o = dynamic_cast<Office_Supply*>(p);
                    if (o != nullptr)
                    {
                        o->display();
                    }
                }
                break;
            }
            default:
            {
                cout << "Invalid input";
                break;
            }
            }
            break;
        }

        case 3:
        {
            int buychoice;

            cout << "Which Product do you want to buy" << endl;
            cout << "1- Book\n2- Electronic Device\n3- Office Supply" << endl;
            cin >> buychoice;

            switch (buychoice)
            {
            case 1:
            {
                for (auto p : products)
                {
                    Book* b = dynamic_cast<Book*>(p);
                    if (b != nullptr)
                    {
                        b->display();
                    }
                }

                cout << "Enter the id of the product that you want to buy" << endl;
                cin >> id;

                for (size_t i = 0; i < products.size(); i++)
                {
                    if (id == products[i]->get_id())
                    {
                        cout << "Enter the quantity that you want to buy" << endl;
                        cin >> buyquantity;

                        if (buyquantity < products[i]->get_quantity())
                        {
                            cout << "Added Successfully" << endl;
                            products[i]->set_new_quantity(
                                products[i]->get_quantity() - buyquantity
                            );
                        }
                        else
                        {
                            cout << "Invalid Quantity try again" << endl;
                            i--;
                        }
                    }
                }
                break;
            }

            case 2:
            {
                for (auto p : products)
                {
                    Electronic_Device* e = dynamic_cast<Electronic_Device*>(p);
                    if (e != nullptr)
                    {
                        e->display();
                    }
                }

                cout << "Enter the id of the product that you want to buy" << endl;
                cin >> id;

                for (size_t i = 0; i < products.size(); i++)
                {
                    if (id == products[i]->get_id())
                    {
                        cout << "Enter the quantity that you want to buy" << endl;
                        cin >> buyquantity;

                        if (buyquantity < products[i]->get_quantity())
                        {
                            cout << "Added Successfully" << endl;
                            products[i]->set_new_quantity(
                                products[i]->get_quantity() - buyquantity
                            );
                        }
                        else
                        {
                            cout << "Invalid Quantity try again" << endl;
                            i--;
                        }
                    }
                }
                break;
            }

            case 3:
            {
                for (auto p : products)
                {
                    Office_Supply* o = dynamic_cast<Office_Supply*>(p);
                    if (o != nullptr)
                    {
                        o->display();
                    }
                }

                cout << "Enter the id of the product that you want to buy" << endl;
                cin >> id;

                for (size_t i = 0; i < products.size(); i++)
                {
                    if (id == products[i]->get_id())
                    {
                        cout << "Enter the quantity that you want to buy" << endl;
                        cin >> buyquantity;

                        if (buyquantity < products[i]->get_quantity())
                        {
                            cout << "Added Successfully" << endl;
                            products[i]->set_new_quantity(
                                products[i]->get_quantity() - buyquantity
                            );
                        }
                        else
                        {
                            cout << "Invalid Quantity try again" << endl;
                            i--;
                        }
                    }
                }
                break;
            }

            default:
            {
                cout << "Invalid input";
                break;
            }
            }

            break;
        }

        default:
        {
            cout << "Invalid choice" << endl;
            break;
        }
        }

    } while (mainchoice != 0);

    return 0;
}