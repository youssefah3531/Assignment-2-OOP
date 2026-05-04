#pragma once
#include "Payment.h"
#include <string>
class CardPayment :public Payment
{
private:
	string cardNumber;
public:
	void setCardNumber(string num);
	bool validateCard();
	void pay() override;
};

