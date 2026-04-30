#pragma once
#include <vector>
#include "Product.h"

using namespace std;

void saveToFile(vector<Product*>& products);
void loadFromFile(vector<Product*>& products);