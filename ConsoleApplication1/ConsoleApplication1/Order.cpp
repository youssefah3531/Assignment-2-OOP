#include "Order.h"
#include "Delivery.h"
#include "Payment.h"
#include "CardPayment.h"
#include "CashPayment.h"
#include "OrderItem.h"
#include "Product.h"
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

Payment* Order::getPayment()
{
    return payment;
}

Delivery* Order::getDelivery()
{
    return delivery;
}

void Order::addItem(Product* product, int quantity)
{
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
        total -= customer->calculateDiscount(total);
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
    cout << "Subtotal:   " << calculateSubtotal() << " EGP" << endl;
    if (delivery != nullptr)
        cout << "Delivery:   " << delivery->getDeliveryFee() << " EGP" << endl;
    cout << "Total:      " << calculateFinalTotal() << " EGP" << endl;
    if (payment != nullptr) {
        cout << "Payment:    ";
        payment->pay();
    }
    if (delivery != nullptr)
        delivery->displayDeliveryInfo();
    cout << "=============================" << endl;
}
    
