#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<iostream>
#include"Food_menu.h"
#include"game_catalogue.h"
#include"rental.h"
#include "Register.h"
#include "kitchen_queue.h"
#include "order.h"
using namespace std;

class customer{
private:
    float total_bill;
    float food_bill;
    float game_bill;
    Order o;
public:
    customer();
    void Display_bill();
    void display_food_menu();
    void display_game_collection();
    void add_item_to_order();
    void remove_item_from_order(int itemId,int quantity);
    void order_food();
    void reserve_game_zone();
    Order getOrder() const;
    void copyOrder(const Order orr);
    void order_detail() const;
    float getFoodBill() const;
    float getGameBill() const;
    float getTotalBill() const;
};
#endif


