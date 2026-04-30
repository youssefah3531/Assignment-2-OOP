#include "Product.h"
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
T findMaxPrice (const vector<T>& products) {
	if (products.empty()) {
		throw runtime_error("No products available");
	}
	T maxPriceProduct = products[0];
	for (const auto& product : products) {
		if (product->get_price() > maxPriceProduct->get_price()) {
			maxPriceProduct = product;
		}
	}
	return maxPriceProduct;
}

template <typename T>
void swapProducts (T& product1, T& product2) {
	T temp = product1;
	product1 = product2;
	product2 = temp;
}	