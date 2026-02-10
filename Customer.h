#include<iostream>
#include"Food_menu.h"
using namespace std;

class customer{
private:
    float total_bill;
    float food_bill;
    float game_bill;

public:
    void Display_bill();
    void display_food_menu();
    void display_game_collection();
    void order_food();
    void reserve_game_zone();
};
