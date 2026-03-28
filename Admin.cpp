#include "admin.h"
#include <iostream>
#include <limits>
using namespace std;

void Admin::Identity() const {
    cout << "\n=== ADMIN ===\n";
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "Email: " << eMail << endl;
    cout << "Share: " << shareAmount << endl;
}
string Admin::post() const {
    return "Admin";
}
// FOOD MENU
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
        case 1: menu.seeMenu(); break;
        case 2: menu.addMenu(); break;
        case 3: menu.updateMenuItem(); break;
        //case 4: menu.deleteMenuItem(); break;
        default: cout << "Invalid choice\n";
    }
}

// INVENTORY
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

// GAME CATALOGUE
void Admin::manageGameCatalogue(GameCatalogue& games) {
    int choice;

    cout << "\n--- GAME CATALOGUE ---\n";
    cout << "1. View Games\n";
    cout << "2. Add Game\n";
    cout << "3. Remove Game\n";
    cout << "Choice: ";
    cin >> choice;

    switch(choice) {
        case 1:
            games.viewAllGames();
            break;

        case 2: {
            int id;
            string name, genre, description, releaseDate;

            cout << "Enter ID: ";
            cin >> id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter Name: ";
            getline(cin, name);

            cout << "Enter Genre: ";
            getline(cin, genre);

            cout << "Enter Description: ";
            getline(cin, description);

            cout << "Enter Release Date: ";
            getline(cin, releaseDate);

            games.addGame(id, name, genre, description, releaseDate, this);
            break;
        }

        case 3: {
            int id;
            cout << "Enter Game ID to remove: ";
            cin >> id;
            games.removeGame(id, this);
            break;
        }

        default:
            cout << "Invalid choice\n";
    }
}

// RENTAL
void Admin::updateRentalPricing(Rental& rental) {
    rental.updatePricing();
}

// REGISTER
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
//cashpout
void Admin::cashOut(Register& reg) {
    double amount;
    string reason;

    cout << "\nCurrent Balance: " << reg.getTotalCash() << " BDT\n";

    cout << "Enter amount to withdraw: ";
    cin >> amount;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter reason: ";
    getline(cin, reason);

    reg.cashOut(amount, reason);

    cout << "Cash out completed.\n";
}
