#include "CardPayment.h"

bool CardPayment::validateCard()
{
	cin >> cardNumber;
	if (cardNumber.size()>15)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CardPayment::pay()
{
	if (validateCard)
	{
		cout << "Successful Payment"<<endl;
	}
	else
	{
		cout << "Invaild Card" << endl;
	}
}
