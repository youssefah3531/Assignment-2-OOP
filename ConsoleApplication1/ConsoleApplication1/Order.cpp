#include "Order.h"
#include "Delivery.h"
#include "Payment.h"
#include "CardPayment.h"
#include "CashPayment.h"
#include "OrderItem.h"
#include "Product.h"
Order::Order(int id, string date, string stat, Customer* c)
{
    orderId = id;
    orderDate = date;
    status = stat;
    customer = c;
    payment = nullptr;
    delivery = nullptr;
}
Order::~Order()
{
    for (auto item : items)
        delete item;
    delete payment;
    delete delivery;
}
void Order::setPayment(Payment* p)
{
    payment = p;
}
void Order::setDelivery(Delivery* d)
{
    delivery = d;
}
int Order::getOrderId()
{
    return orderId;
}

string Order::getOrderDate()
{
    return orderDate;
}

string Order::getStatus()
{
    return status;
}

Customer* Order::getCustomer()
{
    return customer;
}

void Order::addItem(Product* product, int quantity)
{
    if (quantity <= 0)
        throw invalid_argument("Quantity must be positive");
    if (quantity > product->get_quantity())
        throw runtime_error("Insufficient stock for: " + product->get_name());
    OrderItem* item = new OrderItem();
    item->setProduct(product);
    item->setquantity(quantity);
    item->setUnitPrice(product->get_price());
    items.push_back(item);
}
double Order::calculateSubtotal()
{
    double total = 0;
    for (OrderItem* item : items)
        total += item->calculateItemTotal();
    return total;
}

double Order::calculateFinalTotal()
{
    double total = calculateSubtotal();
    if (delivery != nullptr)
        total += delivery->getDeliveryFee();
    if (customer != nullptr)
        total -= customer->calculateDiscount(calculateSubtotal());
    return total;
}

void Order::printInvoice()
{
    cout << "========== INVOICE ==========" << endl;
    cout << "Order ID:   " << orderId << endl;
    cout << "Date:       " << orderDate << endl;
    cout << "Status:     " << status << endl;
    if (customer != nullptr) {
        cout << "Customer:   " << customer->getName() << endl;
        cout << "Phone:      " << customer->getPhone() << endl;
    }
    cout << "----- Items -----" << endl;
    for (OrderItem* item : items)
        item->displayItem();
    cout << "-----------------" << endl;
    double subtotal = calculateSubtotal();
    double discount = (customer != nullptr) ? customer->calculateDiscount(subtotal) : 0;
    double deliveryFee = (delivery != nullptr) ? delivery->getDeliveryFee() : 0;
    cout << "Subtotal:      " << subtotal << " EGP" << endl;
    cout << "Discount:      " << discount << " EGP" << endl;
    if (delivery != nullptr)
        cout << "Delivery:   " << delivery->getDeliveryFee() << " EGP" << endl;
    cout << "Total:      " << calculateFinalTotal() << " EGP" << endl;
    cout << "Payment:       ";
    if (payment != nullptr) 
        payment->pay();
    else 
        cout << "Not set" << endl;
    if (delivery != nullptr)
        delivery->displayDeliveryInfo();
    cout << "=============================" << endl;
}
    
