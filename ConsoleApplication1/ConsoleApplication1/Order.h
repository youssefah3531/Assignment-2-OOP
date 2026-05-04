#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Product.h"
#include "Customer.h"
#include "Payment.h"
#include "Delivery.h"
#include "OrderItem.h"
using namespace std;
class Customer;
class Payment;
class Delivery;
class OrderItem;
class Product;
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
    Order(int id, string date, string status, Customer* c);
    ~Order();
    void setPayment(Payment* p);
    void setDelivery(Delivery* d);
    int getOrderId();
    string getOrderDate();
    string getStatus();
    Customer* getCustomer();
    void addItem(Product* product, int quantity);
    double calculateSubtotal();
    double calculateFinalTotal();
    void printInvoice();
};

