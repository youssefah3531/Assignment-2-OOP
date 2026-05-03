#include "PremiumCustomer.h"
#include <iostream>
#include <string>
using namespace std;

void PremiumCustomer::setDiscountRate(double newRate)
{
    if (newRate >= 0.0 && newRate <= 1.0)
        discountRate = newRate;
    else
        cout << "Invalid rate! Must be between 0.0 and 1.0" << endl;
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
