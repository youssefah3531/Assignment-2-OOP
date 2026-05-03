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

};

