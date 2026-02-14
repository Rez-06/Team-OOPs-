
#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <string>
#include "Food_menu.h"
#include "Inventory.h"
using namespace std;

struct OrderItem {
    MenuItem item;
    int quantity;
};

class Order {
private:
    const int orderId;
    vector<OrderItem> items;
    double totalAmount;///cost
    string status; // pending / cooking / done /rejected
    static int orderCount;
public:
    Order(string Status);
    void addItem(MenuItem menuitem,int quantity);
    void removeItem(MenuItem menuitem,int quantity);
    //bool placeOrder(Inventory& inv);
    bool IsOrderAcceptableThenDeductInventory(Inventory &inv);
    double getTotal() const;
    int getOrderId() const;
    string getStatus() const;
    vector<OrderItem> getItems() const;//this is useless
    void setStatus(const string Status);
    void DisplayDetails() const;
    Order operator+=(OrderItem order_item);
    Order operator-=(OrderItem order_item);
};

#endif
