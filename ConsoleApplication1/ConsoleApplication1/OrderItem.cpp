#include "OrderItem.h"

void OrderItem::setProduct(Product * p)
{
	product = p;
}

void OrderItem::setquantity(int q)
{
	quantity = q;
}

void OrderItem::setUnitPrice(double price)
{
	unitPriceAtPurchase = price;
}

int OrderItem::calculateItemTotal()
{
	return quantity*unitPriceAtPurchase;
}
