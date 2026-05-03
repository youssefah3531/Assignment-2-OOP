#pragma once
#include "Customer.h"
class PremiumCustomer : public Customer
{
private:
	double discountRate;
public:
	void setDiscountRate(double newRate);
	double getDiscountRate();
	void displayInfo() override;
	double calculateDiscount(double amount) override;
};

