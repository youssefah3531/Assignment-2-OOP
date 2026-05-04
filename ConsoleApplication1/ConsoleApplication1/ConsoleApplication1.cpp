#include "Product.h"
#include "Customer.h"
#include "Electronic_Device.h"
#include "Office_Supply.h"
#include "Book.h"
#include <iostream>
#include <string>
#include <vector>
#include "Templates.h"
#include "File.h"
#include "Store.h"
#include "RegularCustomer.h"
#include "PremiumCustomer.h"
#include "Order.h"
#include "Delivery.h"
#include "Payment.h"
#include "CardPayment.h"
#include "CashPayment.h"
#include "OrderItem.h"
using namespace std;
int main()
{
    Store st;
    vector<Product*> products;
    vector<Customer*> customers;
    vector<Order*> orders;
    int orderCounter = 1001;
    try {
        loadFromFile(products);
        for (auto p : products)
            st.addProduct(p);
        if (!products.empty())
            cout << "[File] Loaded " << products.size() << " product(s)." << endl;
    }
    catch (exception& e) {
        cout << "Error loading products: " << e.what() << endl;
    }

    int choice;
    cout << "\nWelcome to Smart Store" << endl;
    cout << "What do you want to do" << endl;

    do
    {
        try
        {
            cout << "1- Add Product\n2- Display product details\n3- Find Max Price Product\n4- Swap Products\n5- Add Customer\n6- Create Order & Print Invoice\n7- Display Total Product Count\n8- Compare Price\n0- Exit" << endl;
            if (!(cin >> choice))
                throw runtime_error("Invalid input");

            switch (choice)
            {
            case 1:
            {
                int type;
                cout << "Which Product do you want to add" << endl;
                cout << "1- Book\n2- Electronic Device\n3- Office Supply" << endl;
                if (!(cin >> type))
                    throw runtime_error("Invalid input");

                Product* p = nullptr;

                if (type == 1)
                    p = new Book();
                else if (type == 2)
                    p = new Electronic_Device();
                else if (type == 3)
                    p = new Office_Supply();
                else
                    throw runtime_error("Invalid product type");
                p->add_product();
                products.push_back(p);
                st.addProduct(p);
                saveToFile(products);
                cout << "Product added successfully." << endl;
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

                Product* maxProduct = findMaxPrice(products);

                cout << "Highest Price Product:\n";
                maxProduct->display();

                break;
            }

            case 4:
            {
                if (products.size() < 2)
                    throw runtime_error("Need at least 2 products to swap");
                for (auto p : products) p->display();

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
                for (auto p : products) p->display();
                break;
            }

            case 5:
            {
                int type;
                cout << "1- Regular Customer\n2-Premium Customer: " << endl;
                do {
                    if (!(cin >> type)) {
                        cout << "Invalid input.\n";
                        cin.clear(); cin.ignore(1000, '\n');
                        continue;
                    }
                    if (type != 1 && type != 2)
                        cout << "Please enter 1 or 2: ";
                } while (type != 1 && type != 2);

                int id; string name, phone;
                cout << "Enter Customer ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Phone: ";
                cin >> phone;

                Customer* c = nullptr;
                if (type == 1)
                {
                    c = new RegularCustomer();
                    c->setCustomerId(id);
                    c->setCustomerName(name);
                    c->setCustomerPhone(phone);
                    cout << "Regular customer added." << endl;
                }
                else
                {
                    double rate;
                    cout << "Enter Discount Rate (0.0 - 1.0): "; cin >> rate;
                    PremiumCustomer* pc = new PremiumCustomer();
                    pc->setCustomerId(id);
                    pc->setCustomerName(name);
                    pc->setCustomerPhone(phone);
                    pc->setDiscountRate(rate);
                    c = pc;
                    cout << "Premium customer added." << endl;
                }
                customers.push_back(c);
                st.addCustomer(c);
                c->displayInfo();
                break;
            }

            case 6:
            {
                if (products.empty())
                    throw runtime_error("No products available to order");
                if (customers.empty())
                    throw runtime_error("No customers found. Please add a customer first (option 6)");

                cout << "\nAvailable Customers:" << endl;
                for (size_t i = 0; i < customers.size(); i++) {
                    cout << i + 1 << "- ";
                    customers[i]->displayInfo();
                }
                int custIdx;
                cout << "Choose customer number: ";
                if (!(cin >> custIdx) || custIdx < 1 || (size_t)custIdx > customers.size())
                    throw runtime_error("Invalid customer selection");
                Customer* cust = customers[custIdx - 1];
                Order* order = new Order(orderCounter++, "2026-05-04", "Confirmed", cust);
                for (auto p : products)
                    p->display();
                int more = 1;
                while (more == 1) {
                    int pid, qty;
                    cout << "Enter product ID to add: ";
                    if (!(cin >> pid)) throw runtime_error("Invalid ID");
                    cout << "Enter quantity: ";
                    if (!(cin >> qty)) throw runtime_error("Invalid quantity");
                    bool found = false;
                    for (auto p : products) {
                        if (p->get_id() == pid) {
                            found = true;
                            try {
                                order->addItem(p, qty);
                                cout << "Item added." << endl;
                            }
                            catch (exception& e) {
                                cout << "Error: " << e.what() << endl;
                            }
                            break;
                        }
                    }
                    if (!found) cout << "Product not found." << endl;
                    cout << "Add another item? 1-Yes  0-No: ";
                    cin >> more;
                }
                int payType;
                cout << "Payment method:\n1- Cash\n2- Card\nChoice: ";
                if (!(cin >> payType)) throw runtime_error("Invalid payment choice");

                Payment* pay = nullptr;
                if (payType == 2) {
                    string cardNum;
                    cout << "Enter 16-digit card number: ";
                    cin >> cardNum;
                    CardPayment* cp = new CardPayment();
                    cp->setCardNumber(cardNum);
                    pay = cp;
                }
                else {
                    pay = new CashPayment();
                }
                order->setPayment(pay);
                int hasDelivery;
                cout << "Delivery:\n1- Shipped (with delivery fee)\n0- Pickup (no fee)\nChoice: ";
                cin >> hasDelivery;
                if (hasDelivery == 1) {
                    string addr, driver; double fee;
                    cout << "Delivery Address: ";
                    cin >> addr;
                    cout << "Delivery Fee: ";
                    cin >> fee;
                    cout << "Driver Name: ";
                    cin >> driver;
                    try {
                        Delivery* del = new Delivery(1, addr, fee, driver);
                        order->setDelivery(del);
                    }
                    catch (exception& e) {
                        cout << "Delivery error: " << e.what() << endl;
                    }
                }

                order->printInvoice();
                st.addOrder(order);
                orders.push_back(order);
                saveToFile(products);
                break;
            }

            case 7:
            {
                cout << "Total Product objects created: " << Product::getProductCount() << endl;
                break;
            }

            case 8:
            {
                int comp_a;
                int comp_b;
                if (products.empty()) {
                    cout << "No products available\n";
                    break;
                }
                for (auto p : products)
                {
                    p->display();
                }
                cout << "Enter the First Product Id: " << endl;
                cin >> comp_a;
                cout << "Enter the Secound Product Id: " << endl;
                cin >> comp_b;

                Product* a = nullptr;
                Product* b = nullptr;

                for (size_t i = 0; i < products.size(); i++)
                {
                    if (products[i]->get_id() == comp_a)
                    {
                        a = products[i];
                    }
                    else if (products[i]->get_id() == comp_b)
                    {
                        b = products[i];
                    }
                    if (a != nullptr && b != nullptr)
                    {
                        compareByPrice(a, b);
                        break;
                    }
                }
                break;
            }

            case 0:
            {
                cout << "Saving data" << endl;
                try {
                    saveToFile(products);
                    cout << "Products saved successfully." << endl;
                }
                catch (exception& e) {
                    cout << "Save error: " << e.what() << endl;
                }
                st.displayStoreSummary();
                cout << "Goodbye!" << endl;
                break;
            }

            default:
            {
                throw runtime_error("Invalid choice. Please enter 0-8");
            }
            }
        }
        catch (exception& e) {
            cout << "Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    } while (choice != 0);

    for (auto o : orders)
        delete o;
    for (auto c : customers)
        delete c;
    for (auto p : products)
        delete p;
}