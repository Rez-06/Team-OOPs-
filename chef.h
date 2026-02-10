
#ifndef CHEF_H
#define CHEF_H

#include "Kitchen_queue.h"
#include "Food_menu.h"
using namespace std;

class Chef {
public:
    void viewPendingOrders(KitchenQueue& queue);
    void viewRecipe(int menuId, Food_menu& menu);
    void completeOrder(KitchenQueue& queue);
};

#endif
