#include "OrderItem.h"
#include "Product.h"
void OrderItem::setProduct(Product * p)
{
	product = p;
}

void OrderItem::setquantity(int q)
{
    if (product != nullptr) {
        int currentQty = product->get_quantity();
        product->set_quantity(currentQty - q);
        quantity = q;
    } else {
        quantity = 0;
    }
}

void OrderItem::setUnitPrice(double price)
{
	unitPriceAtPurchase = price;
}

int OrderItem::calculateItemTotal()
{
	return quantity*unitPriceAtPurchase;
}

void OrderItem::displayItem()
{
	if (product != nullptr)
		cout << "  - " << product->get_name()
		<< " | Quantity: " << quantity
		<< " | Unit Price: " << unitPriceAtPurchase << " EGP"
		<< " | Total: " << calculateItemTotal() << " EGP" << endl;
}
