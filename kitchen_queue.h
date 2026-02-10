
#ifndef KITCHEN_QUEUE_H
#define KITCHEN_QUEUE_H

#include <queue>
#include "Order.h"
using namespace std;

class KitchenQueue {
private:
    queue<Order> pendingOrders;

public:
    void addOrder(const Order& order);
    bool hasOrders() const;
    Order getNextOrder();
    void completeOrder();
};

#endif
