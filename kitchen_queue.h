
#ifndef KITCHEN_QUEUE_H
#define KITCHEN_QUEUE_H

#include <queue>
#include "Order.h"
#include "AuthorizedPerson.h"
using namespace std;

class KitchenQueue {
private:
    queue<Order> pendingOrders;

public:
    KitchenQueue();
    Order deserialization_order(string s);
    OrderItem deserialization_item(string s);
    IngredientUsage deserialization_ingredients(string s);
    
    string serialization_order(Order o);
    string serialization_item(OrderItem i);
    string serialization_ingredients(IngredientUsage i);
    

    bool addOrder(Order order,Inventory &inv);
    bool hasOrders() const;
    Order& getNextOrder();
    void completeOrder(AuthorizedPerson* p);
    void completeAllOrders(AuthorizedPerson* p);
    ~KitchenQueue();
};

#endif
