#ifndef CHEF_H
#define CHEF_H
#include "AuthorizedPerson.h"
#include "Kitchen_queue.h"
#include "Food_menu.h"
using namespace std;

class Chef:public AuthorizedPerson{
private:
string joinDate;
public:
    Chef(string Name,int Id,string EMail,string JoinDate):AuthorizedPerson(Name,Id,EMail),joinDate(JoinDate){

    }
    void Identity() const;
    string post() const;///return chef
    void viewPendingOrders(KitchenQueue& queue);
    void viewRecipe(int menuId, Food_menu& menu);
    void completeOrder(KitchenQueue& queue);
};

#endif
