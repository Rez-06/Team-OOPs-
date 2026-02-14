
#ifndef KITCHEN_QUEUE_H
#define KITCHEN_QUEUE_H

#include <queue>
#include "Order.h"
using namespace std;

class KitchenQueue {
private:
    queue<Order> pendingOrders;

public:
    bool addOrder(Order& order,Inventory &inv);
    bool hasOrders() const;
    Order& getNextOrder();
    void completeOrder(AuthorizedPerson* p);
    void completeAllOrders(AuthorizedPerson* p);
};

#endif
