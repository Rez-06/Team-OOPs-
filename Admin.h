#ifndef ADMIN_H
#define ADMIN_H
#include "AuthorizedPerson.h"
#include "Food_menu.h"
#include "Inventory.h"
#include "Register.h"
#include "Game_catalogue.h"
#include "Rental.h"
using namespace std;

class Admin:public AuthorizedPerson{
private:
string shareAmount; ////10%,30%---etc 
public:
    Admin(string Name,int Id,string EMail,string Share):AuthorizedPerson(Name,Id,EMail),shareAmount(Share){}
    void Identity() const;///in identity must also print share amount along with other info's
    string post() const;////return Admin
    void manageFoodMenu(Food_menu& menu);
    void manageInventory(Inventory& inventory);

    void manageGameCatalogue(GameCatalogue& games);
    void updateRentalPricing(Rental& rental);

    void viewRegister(Register& reg);
    void cashOut(Register& reg);
};

#endif
