#ifndef INVENTORY_H
#define INVENTORY_H

#include "Food_menu.h"
using namespace std;

struct Ingredient {
    int id;
    char name[50];
    double stock;
};

class Inventory {
public:
    void addIngredient();
    void refillIngredient();
    void viewInventory();
    void updateIngredient();
    bool isAvailable(const MenuItem& item,int quantity);///Order.cpp needs the quentity
    void deductIngredients(const MenuItem& item, int qty);
    void addIngredientAccordingToMakeParticularItem(const MenuItem& item, int qty);///This required for order.cpp calculation
};

#endif
