#include "CardPayment.h"

void CardPayment::setCardNumber(string num)
{
	cardNumber = num;
}

bool CardPayment::validateCard()
{
	if (cardNumber.size() != 16)
		return false;
	for (char c : cardNumber)
		if (!isdigit(c))
			return false;
	return true;
}

void CardPayment::pay()
{
	if (!validateCard())
        throw invalid_argument("Invalid card number. Must be exactly 16 digits.");
    cout << "Card Payment successful. Card: ****" << cardNumber.substr(12) << endl;
}
