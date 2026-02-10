
#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <string>
#include "Food_menu.h"
#include "Inventory.h"
using namespace std;

struct OrderItem {
    int menuId;
    int quantity;
};

class Order {
private:
    int orderId;
    vector<OrderItem> items;
    double totalAmount;
    string status; // pending / cooking / done

public:
    Order();
    void addItem(int menuId, int quantity);
    bool placeOrder(Inventory& inv);
    double getTotal() const;
    int getOrderId() const;
    string getStatus() const;
    vector<OrderItem> getItems() const;
};

#endif
