#include "File.h"
#include "Book.h"
#include "Electronic_Device.h"
#include "Office_Supply.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
static bool tryParseInt(const string& s, int& out)
{
    try
    {
        size_t idx = 0;
        int value = stoi(s, &idx);
        if (idx != s.size())
            return false;
        out = value;
        return true;
    }
    catch (...)
    {
        return false;
    }
}

void saveToFile(vector<Product*>& products)
{
    ofstream out("products.txt");

    for (auto p : products)
    {
        p->save(out);
    }

    out.close();
}

void loadFromFile(vector<Product*>& products)
{
    ifstream in("products.txt");

    if (!in)
        return;

    string type;

    while (getline(in, type))
    {
        if (type.empty())
            continue;

        string idLine, name, priceLine, quantityLine, extra1, extra2;
        if (!getline(in, idLine)) break;
        if (!getline(in, name)) break;
        if (!getline(in, priceLine)) break;
        if (!getline(in, quantityLine)) break;
        if (!getline(in, extra1)) break;
        if (!getline(in, extra2)) break;

        int id = 0, price = 0, quantity = 0;
        if (!tryParseInt(idLine, id) || !tryParseInt(priceLine, price) || !tryParseInt(quantityLine, quantity))
            continue;

        Product* p = nullptr;
        if (type == "Book")
        {
            int pages = 0;
            if (!tryParseInt(extra2, pages))
                continue;
            p = new Book(id, name, price, extra1, pages);
        }
        else if (type == "Electronic Device")
        {
            int warranty = 0;
            if (!tryParseInt(extra2, warranty))
                continue;
            p = new Electronic_Device(id, name, price, extra1, warranty);
        }
        else if (type == "Office Supply")
        {
            p = new Office_Supply(id, name, price, extra1, extra2);
        }
        else
        {
            continue;
        }

        p->set_quantity(quantity);
        products.push_back(p);
    }

    in.close();
}
