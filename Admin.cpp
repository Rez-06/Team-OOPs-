#include "admin.h"
#include <iostream>
#include<exception>

using namespace std;

void Admin::Identity() const {
    cout << "\n=== ADMIN ===\n";
    cout << "Name: " << getName() << endl;
    cout << "ID: " << getId() << endl;
    cout << "Email: " << getEmail() << endl;
    cout << "Share: " << shareAmount << endl;
}

string Admin::post() const {
    return "Admin";
}
//food
void Admin::manageFoodMenu(Food_menu& menu) {
    int choice;

    cout << "\n--- FOOD MENU MANAGEMENT ---\n";
    cout << "1. Display Menu\n";
    cout << "2. Add Item\n";
    cout << "3. Update Item\n";
    cout << "4. Delete Item\n";
    cout << "Choice: ";
    cin >> choice;

    switch(choice) {
        case 1: menu.displayMenu(); break;
        case 2: menu.addItem(); break;
        case 3: menu.updateItem(); break;
        case 4: menu.deleteItem(); break;
        default: cout << "Invalid choice\n";
    }
}
//inventry
void Admin::manageInventory(Inventory& inventory) {
    int choice;

    cout << "\n--- INVENTORY MANAGEMENT ---\n";
    cout << "1. View Inventory\n";
    cout << "2. Add Ingredient\n";
    cout << "3. Refill Stock\n";
    cout << "Choice: ";
    cin >> choice;

    switch(choice) {
        case 1: inventory.viewInventory(); break;
        case 2: inventory.addIngredient(); break;
        case 3: inventory.refillIngredient(); break;
        default: cout << "Invalid choice\n";
    }
}
//game
void Admin::manageGameCatalogue(GameCatalogue& games) {
    int choice;

    cout << "\n--- GAME CATALOGUE ---\n";
    cout << "1. View Games\n";
    cout << "2. Add Game\n";
    cout << "3. Remove Game\n";
    cout << "4. Update Price\n";
    cout << "Choice: ";
    cin >> choice;

    switch(choice) {
        case 1: games.viewAllGames(); break;
        case 2: games.addGame(); break;
        case 3: games.removeGame(); break;
        case 4: games.updateGamePrice(); break;
        default: cout << "Invalid choice\n";
    }
}
//rental
void Admin::updateRentalPricing(Rental& rental) {
    rental.updatePricing();
}

//register
void Admin::viewRegister(Register& reg) {
    int choice;

    cout << "\n--- FINANCIAL REGISTER ---\n";
    cout << "1. Transaction History\n";
    cout << "2. Income Summary\n";
    cout << "3. Best Selling Food\n";
    cout << "4. Most Rented Game\n";
    cout << "Choice: ";
    cin >> choice;

    switch(choice) {
        case 1: reg.viewHistory(); break;
        case 2: reg.showIncomeSummary(); break;
        case 3: reg.showBestSellingFood(); break;
        case 4: reg.showMostRentedGame(); break;
        default: cout << "Invalid choice\n";
    }
}
//cash
void Admin::cashOut(Register& reg) {

    double amount;
    string reason;

    cout << "\nCurrent Balance: " << reg.getTotalCash() << " BDT\n";

    cout << "Amount to withdraw: ";
    cin >> amount;

    cin.ignore();
    cout << "Reason: ";
    getline(cin, reason);

    try {
        reg.cashOut(amount, reason);
        cout << "Cash out successful.\n";
    }
    catch(const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}
