#pragma once
#include "Payment.h"
#include <string>
class CardPayment :public Payment
{
private:
	string cardNumber;
public:
	bool validateCard();
	void pay() override;
};

