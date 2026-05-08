#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <string>
using namespace std;

// ========== Helper ==========

void clearInput() {
    cin.ignore(1000, '\n');
}

// ========== Product (Base Class - Abstract) ==========

class Product {
protected:
    int id;
    string name;
    double price;
    int qty;
    static int count;

public:
    Product(int id, string name, double price, int qty)
        : id(id), name(name), price(price), qty(qty) {
        if (price < 0) throw invalid_argument("Price can't be negative.");
        if (qty < 0) throw invalid_argument("Quantity can't be negative.");
        count++;
    }

    virtual ~Product() { count--; }

    // Getters
    int getID() const { return id; }
    string getName() const { return name; }
    double getPrice() const { return price; }
    int getQty() const { return qty; }

    // Pure virtual (makes Product abstract)
    virtual string getType() const = 0;

    // Virtual display (overridden in derived classes)
    virtual void display() const {
        cout << "ID: " << id << " | Name: " << name
             << " | Price: " << price << " | Qty: " << qty;
    }

    // Virtual save (overridden in derived classes)
    virtual void save(ofstream& f) const {
        f << getType() << "\n" << id << "\n" << name << "\n"
          << price << "\n" << qty << "\n";
    }

    // Buy method
    void buy(int amount) {
        if (amount <= 0) throw invalid_argument("Invalid amount.");
        if (amount > qty) throw runtime_error("Not enough stock.");
        qty -= amount;
    }

    // Operator + overloading (add stock)
    Product& operator+(int amount) {
        if (amount < 0) throw invalid_argument("Can't add negative.");
        qty += amount;
        return *this;
    }

    // Operator == overloading (compare by ID)
    bool operator==(const Product& other) const {
        return id == other.id;
    }

    // Friend function
    friend Product& moreExpensive(Product& a, Product& b);

    // Operator << overloading (using friend)
    friend ostream& operator<<(ostream& out, const Product& p) {
        p.display();
        return out;
    }

    static int getCount() { return count; }
};

int Product::count = 0;

// Friend function definition
Product& moreExpensive(Product& a, Product& b) {
    return (a.price >= b.price) ? a : b;
}

// ========== Derived Class 1: Book ==========

class Book : public Product {
    string author;
public:
    Book(int id, string name, double price, int qty, string author)
        : Product(id, name, price, qty), author(author) {}

    string getType() const override { return "Book"; }

    void display() const override {
        cout << "[Book] ";
        Product::display();
        cout << " | Author: " << author << endl;
    }

    void save(ofstream& f) const override {
        Product::save(f);
        f << author << "\n";
    }
};

// ========== Derived Class 2: Device ==========

class Device : public Product {
    string brand;
public:
    Device(int id, string name, double price, int qty, string brand)
        : Product(id, name, price, qty), brand(brand) {}

    string getType() const override { return "Device"; }

    void display() const override {
        cout << "[Device] ";
        Product::display();
        cout << " | Brand: " << brand << endl;
    }

    void save(ofstream& f) const override {
        Product::save(f);
        f << brand << "\n";
    }
};

// ========== Derived Class 3: Supply ==========

class Supply : public Product {
    string material;
public:
    Supply(int id, string name, double price, int qty, string material)
        : Product(id, name, price, qty), material(material) {}

    string getType() const override { return "Supply"; }

    void display() const override {
        cout << "[Supply] ";
        Product::display();
        cout << " | Material: " << material << endl;
    }

    void save(ofstream& f) const override {
        Product::save(f);
        f << material << "\n";
    }
};

// ========== Template Functions ==========

template <class T>
T* findHighest(vector<T*>& items) {
    if (items.empty()) throw runtime_error("No items.");
    T* best = items[0];
    for (T* item : items)
        if (item->getPrice() > best->getPrice())
            best = item;
    return best;
}

template <class T>
void mySwap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// ========== Customer (Base - Abstract) ==========

class Customer {
protected:
    int id;
    string name;
public:
    Customer(int id, string name) : id(id), name(name) {}
    virtual ~Customer() {}

    int getID() const { return id; }
    string getName() const { return name; }

    virtual double getDiscount(double total) const = 0;

    virtual void display() const {
        cout << "Customer: " << name << " (ID: " << id << ")";
    }
};

// Regular Customer (no discount)
class RegularCustomer : public Customer {
public:
    RegularCustomer(int id, string name) : Customer(id, name) {}

    double getDiscount(double total) const override { return 0; }

    void display() const override {
        cout << "[Regular] ";
        Customer::display();
        cout << endl;
    }
};

// Premium Customer (has discount)
class PremiumCustomer : public Customer {
    double rate;
public:
    PremiumCustomer(int id, string name, double rate)
        : Customer(id, name), rate(rate) {}

    double getDiscount(double total) const override {
        return total * rate;
    }

    void display() const override {
        cout << "[Premium] ";
        Customer::display();
        cout << " | Discount: " << rate * 100 << "%" << endl;
    }
};

// ========== Payment (Abstract) ==========

class Payment {
public:
    virtual ~Payment() {}
    virtual void pay() const = 0;
};

class CashPayment : public Payment {
public:
    void pay() const override { cout << "Paid with Cash.\n"; }
};

class CardPayment : public Payment {
    string card;
public:
    CardPayment(string card) : card(card) {
        if (card.length() != 16) throw invalid_argument("Card must be 16 digits.");
    }
    void pay() const override { cout << "Paid with Card.\n"; }
};

// ========== Order Item ==========

class OrderItem {
    Product* product;  // Association relationship
    int qty;
public:
    OrderItem(Product* p, int qty) : product(p), qty(qty) {
        if (!p) throw invalid_argument("Null product.");
        if (qty <= 0) throw invalid_argument("Invalid qty.");
        p->buy(qty);
    }

    double getTotal() const { return product->getPrice() * qty; }

    void display() const {
        cout << "  " << product->getName() << " x" << qty
             << " = " << getTotal() << endl;
    }
};

// ========== Order (Composition with OrderItem, Payment) ==========

class Order {
    int id;
    Customer* customer;       // Association
    vector<OrderItem> items;  // Composition
    Payment* payment;         // Composition

public:
    Order(int id, Customer* c) : id(id), customer(c), payment(nullptr) {
        if (!c) throw invalid_argument("Customer required.");
    }

    ~Order() { delete payment; }

    int getID() const { return id; }

    void addItem(Product* p, int qty) {
        items.push_back(OrderItem(p, qty));
    }

    void setPayment(Payment* p) {
        delete payment;
        payment = p;
    }

    void printInvoice() const {
        cout << "\n====== INVOICE ======\n";
        cout << "Order #" << id << endl;
        customer->display();

        cout << "Items:\n";
        double sub = 0;
        for (const auto& item : items) {
            item.display();
            sub += item.getTotal();
        }

        double disc = customer->getDiscount(sub);
        cout << "Subtotal: " << sub << endl;
        cout << "Discount: " << disc << endl;
        cout << "Total: " << sub - disc << endl;

        if (payment) payment->pay();
        cout << "=====================\n";
    }
};

// ========== Store (Composition with Products) ==========

class Store {
    vector<Product*> products;  // Composition

public:
    ~Store() {
        for (Product* p : products) delete p;
    }

    void add(Product* p) { products.push_back(p); }

    Product* find(int id) {
        for (Product* p : products)
            if (p->getID() == id) return p;
        return nullptr;
    }

    vector<Product*>& getAll() { return products; }

    void displayAll() {
        if (products.empty()) { cout << "No products.\n"; return; }
        cout << "\n--- All Products ---\n";
        for (Product* p : products) cout << *p;
    }

    // File I/O: Save
    void saveToFile(string fname) {
        ofstream f(fname);
        if (!f) throw runtime_error("Can't open file.");
        f << products.size() << "\n";
        for (Product* p : products) p->save(f);
        cout << "Saved!\n";
    }

    // File I/O: Load
    void loadFromFile(string fname) {
        ifstream f(fname);
        if (!f) throw runtime_error("Can't open file.");

        for (Product* p : products) delete p;
        products.clear();

        int n; f >> n; f.ignore();

        for (int i = 0; i < n; i++) {
            string type; getline(f, type);
            int id, qty; string name; double price;
            f >> id; f.ignore();
            getline(f, name);
            f >> price >> qty; f.ignore();

            string extra; getline(f, extra);

            if (type == "Book")
                add(new Book(id, name, price, qty, extra));
            else if (type == "Device")
                add(new Device(id, name, price, qty, extra));
            else if (type == "Supply")
                add(new Supply(id, name, price, qty, extra));
        }
        cout << "Loaded!\n";
    }
};

// ========== Helper: Find by ID ==========

Customer* findCust(vector<Customer*>& list, int id) {
    for (Customer* c : list)
        if (c->getID() == id) return c;
    return nullptr;
}

Order* findOrder(vector<Order*>& list, int id) {
    for (Order* o : list)
        if (o->getID() == id) return o;
    return nullptr;
}

// ========== Main ==========

int main() {
    Store store;
    vector<Customer*> customers;
    vector<Order*> orders;
    int choice;

    do {
        cout << "\n===== SMART STORE =====\n"
             << "1.  Add Product\n"
             << "2.  Show Products\n"
             << "3.  Buy Product\n"
             << "4.  Add Stock (operator+)\n"
             << "5.  Compare Price (friend)\n"
             << "6.  Compare ID (operator==)\n"
             << "7.  Highest Price (template)\n"
             << "8.  Swap Products (template)\n"
             << "9.  Save to File\n"
             << "10. Load from File\n"
             << "11. Add Customer\n"
             << "12. Create Order\n"
             << "13. Add Item to Order\n"
             << "14. Set Payment\n"
             << "15. Print Invoice\n"
             << "16. Product Count (static)\n"
             << "0.  Exit\n"
             << "Choice: ";
        cin >> choice;

        try {
            if (choice == 1) {
                int type, id, qty; string name; double price;
                cout << "Type (1=Book, 2=Device, 3=Supply): "; cin >> type;
                cout << "ID: "; cin >> id; clearInput();
                cout << "Name: "; getline(cin, name);
                cout << "Price: "; cin >> price;
                cout << "Qty: "; cin >> qty; clearInput();

                string extra;
                if (type == 1) { cout << "Author: "; getline(cin, extra); store.add(new Book(id, name, price, qty, extra)); }
                else if (type == 2) { cout << "Brand: "; getline(cin, extra); store.add(new Device(id, name, price, qty, extra)); }
                else if (type == 3) { cout << "Material: "; getline(cin, extra); store.add(new Supply(id, name, price, qty, extra)); }
                else cout << "Invalid type.\n";
            }
            else if (choice == 2) { store.displayAll(); }
            else if (choice == 3) {
                int id, amt;
                cout << "Product ID: "; cin >> id;
                Product* p = store.find(id);
                if (!p) { cout << "Not found.\n"; continue; }
                cout << "Amount: "; cin >> amt;
                p->buy(amt);
                cout << "Done!\n";
            }
            else if (choice == 4) {
                int id, amt;
                cout << "Product ID: "; cin >> id;
                Product* p = store.find(id);
                if (!p) { cout << "Not found.\n"; continue; }
                cout << "Add amount: "; cin >> amt;
                *p + amt;
                cout << "Updated!\n";
            }
            else if (choice == 5) {
                int a, b;
                cout << "ID 1: "; cin >> a;
                cout << "ID 2: "; cin >> b;
                Product* p1 = store.find(a);
                Product* p2 = store.find(b);
                if (!p1 || !p2) { cout << "Not found.\n"; continue; }
                cout << "More expensive: " << moreExpensive(*p1, *p2).getName() << endl;
            }
            else if (choice == 6) {
                int a, b;
                cout << "ID 1: "; cin >> a;
                cout << "ID 2: "; cin >> b;
                Product* p1 = store.find(a);
                Product* p2 = store.find(b);
                if (!p1 || !p2) { cout << "Not found.\n"; continue; }
                cout << ((*p1 == *p2) ? "Same ID\n" : "Different ID\n");
            }
            else if (choice == 7) {
                Product* p = findHighest(store.getAll());
                cout << "Highest: " << p->getName() << " ($" << p->getPrice() << ")\n";
            }
            else if (choice == 8) {
                int a, b;
                cout << "Index 1: "; cin >> a;
                cout << "Index 2: "; cin >> b;
                auto& prods = store.getAll();
                if (a < 0 || b < 0 || a >= (int)prods.size() || b >= (int)prods.size())
                    cout << "Invalid index.\n";
                else { mySwap(prods[a], prods[b]); cout << "Swapped!\n"; }
            }
            else if (choice == 9) { store.saveToFile("products.txt"); }
            else if (choice == 10) { store.loadFromFile("products.txt"); }
            else if (choice == 11) {
                int type, id; string name;
                cout << "Type (1=Regular, 2=Premium): "; cin >> type;
                cout << "ID: "; cin >> id; clearInput();
                cout << "Name: "; getline(cin, name);
                if (type == 1) customers.push_back(new RegularCustomer(id, name));
                else if (type == 2) {
                    double rate;
                    cout << "Discount (e.g. 0.10): "; cin >> rate;
                    customers.push_back(new PremiumCustomer(id, name, rate));
                }
            }
            else if (choice == 12) {
                int oid, cid;
                cout << "Order ID: "; cin >> oid;
                cout << "Customer ID: "; cin >> cid;
                Customer* c = findCust(customers, cid);
                if (!c) { cout << "Customer not found.\n"; continue; }
                orders.push_back(new Order(oid, c));
                cout << "Order created!\n";
            }
            else if (choice == 13) {
                int oid, pid, qty;
                cout << "Order ID: "; cin >> oid;
                Order* o = findOrder(orders, oid);
                if (!o) { cout << "Order not found.\n"; continue; }
                cout << "Product ID: "; cin >> pid;
                Product* p = store.find(pid);
                if (!p) { cout << "Product not found.\n"; continue; }
                cout << "Qty: "; cin >> qty;
                o->addItem(p, qty);
                cout << "Added!\n";
            }
            else if (choice == 14) {
                int oid, type;
                cout << "Order ID: "; cin >> oid;
                Order* o = findOrder(orders, oid);
                if (!o) { cout << "Order not found.\n"; continue; }
                cout << "Payment (1=Cash, 2=Card): "; cin >> type;
                if (type == 1) o->setPayment(new CashPayment());
                else if (type == 2) {
                    string card; cout << "Card (16 digits): "; cin >> card;
                    o->setPayment(new CardPayment(card));
                }
            }
            else if (choice == 15) {
                int oid;
                cout << "Order ID: "; cin >> oid;
                Order* o = findOrder(orders, oid);
                if (!o) { cout << "Not found.\n"; continue; }
                o->printInvoice();
            }
            else if (choice == 16) {
                cout << "Total products: " << Product::getCount() << endl;
            }
        }
        catch (exception& e) {
            cout << "Error: " << e.what() << endl;
        }

    } while (choice != 0);

    for (Customer* c : customers) delete c;
    for (Order* o : orders) delete o;

    return 0;
}