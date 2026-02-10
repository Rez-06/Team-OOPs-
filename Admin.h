#ifndef ADMIN_H
#define ADMIN_H

#include "Food_menu.h"
#include "Inventory.h"
#include "Register.h"
#include "Game_catalogue.h"
#include "Rental.h"
using namespace std;

class Admin {
public:
    void manageFoodMenu(Food_menu& menu);
    void manageInventory(Inventory& inventory);

    void manageGameCatalogue(GameCatalogue& games);
    void updateRentalPricing(Rental& rental);

    void viewRegister(Register& reg);
    void cashOut(Register& reg);
};

#endif
