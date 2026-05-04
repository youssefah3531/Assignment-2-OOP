#pragma once
#include <vector>
#include "Product.h"
#include "Order.h"
using namespace std;

void saveToFile(vector<Product*>& products);
void loadFromFile(vector<Product*>& products);
