#pragma once
#include "Payment.h"
class CashPayment :public Payment
{
public:
	void pay() override;
};

