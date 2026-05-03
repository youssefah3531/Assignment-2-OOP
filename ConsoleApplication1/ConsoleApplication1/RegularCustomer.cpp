#include "RegularCustomer.h"
#include <iostream>
#include <string>
using namespace std;

void RegularCustomer::displayInfo()
{
    cout << "Regular Customer:" << endl;
    cout << "  ID: " << getCustomerId() << endl;
    cout << "  Name: " << getName() << endl;
    cout << "  Phone: " << getPhone() << endl;
}

double RegularCustomer::calculateDiscount(double amount)
{
    return amount * 0.05;
}
