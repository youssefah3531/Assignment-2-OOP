#include <iostream>
#include "Product.h"
#include "Order.h"
using namespace std;
class OrderItem
{
private:
	Product* product;
	int quantity;
	double unitPriceAtPurchase;
public:
	int calculateItemTotal();
};

