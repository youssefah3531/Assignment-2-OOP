#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Product.h"
#include "Customer.h"
using namespace std;

class Order
{
private:
    int orderId;
    string orderDate;
    string status;
    Customer* customer;
    Payment* payment;
    Delivery* delivery;
    vector<OrderItem*> items;
public:
    int getOrderId();
    string getOrderDate();
    string getStatus();
    Customer* getCustomer();
    Payment* getPayment();
    Delivery* getDelivery();
    void addItem(Product* product, int quantity);
    double calculateSubtotal();
    double calculateFinalTotal();
    void printInvoice();
};

