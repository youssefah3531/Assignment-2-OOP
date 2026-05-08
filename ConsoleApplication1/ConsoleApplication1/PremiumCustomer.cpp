#include "PremiumCustomer.h"
#include <iostream>
#include <string>
using namespace std;

void PremiumCustomer::setDiscountRate(double newRate)
{
        discountRate = newRate;
}

double PremiumCustomer::getDiscountRate()
{
    return discountRate;
}

void PremiumCustomer::displayInfo()
{
    cout << "Premium Customer:" << endl;
    cout << "  ID: " << getCustomerId() << endl;
    cout << "  Name: " << getName() << endl;
    cout << "  Phone: " << getPhone() << endl;
    cout << "  Discount Rate: " << (discountRate * 100) << "%" << endl;
}

double PremiumCustomer::calculateDiscount(double amount)
{
    return amount * discountRate;
}
