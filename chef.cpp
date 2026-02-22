#include "chef.h"
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
static void showRecipeById(int menuId) {
    ifstream file("menu.dat", ios::binary);
    if (!file) {
        cout << "No menu found\n";
        return;
    }
    MenuItem item;
    bool found = false;
    while (file.read(reinterpret_cast<char*>(&item), sizeof(item))) {
        if (item.id == menuId) {
            cout << "\nFood: " << item.name << "\n";
            cout << "Price: " << item.price << " BDT\n";
            cout << "\n--Recipe--\n";
            cout << item.recipe << "\n";
            cout << "\n---Ingredients used---\n";
            for (int i = 0; i < item.ingredientCount; i++) {
                cout << "Ingredient ID: " << item.ingredients[i].ingredientID
                     << " | Amount: " << item.ingredients[i].amount << "\n";
            }
            found = true;
            break;
        }
    }
    file.close();
    if (!found) cout << "Food item not found\n";
}
void Chef::Identity() const {
    cout << "\n====== Chef Profile ======\n";
    cout << "Name : " << name << "\n";
    cout << "ID   : " << id << "\n";
    cout << "Email: " << eMail << "\n";
    cout << "Join : " << joinDate << "\n";
}
string Chef::post() const {
    return "chef";
}
void Chef::viewPendingOrders(KitchenQueue& queue) {
    if (!queue.hasOrders()) {
        cout << "No pending orders.\n";
        return;
    }
    cout << "\nPending order (next in queue):\n";
    Order& o = queue.getNextOrder();
    o.DisplayDetails();
}
void Chef::viewRecipe(int menuId, Food_menu&) {
    showRecipeById(menuId);
}
void Chef::completeOrder(KitchenQueue& queue) {
    queue.completeOrder(this);
}