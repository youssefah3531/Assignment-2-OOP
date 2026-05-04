#pragma once
#include <iostream>
#include "Order.h"
using namespace std;
class Payment
{
private:
	int paymentId;
	double amount;
public:
	virtual void pay() = 0;
	virtual ~Payment() = default;
};

