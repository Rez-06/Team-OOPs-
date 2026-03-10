#include "customer.h"
#include <iostream>
using namespace std;

customer::customer() : total_bill(0), food_bill(0), game_bill(0) {}//constructor

void customer::Display_bill()
{
    total_bill = food_bill + game_bill;

    cout << "\n===== BILL SUMMARY =====\n";
    cout << "Food Bill: " << food_bill << endl;
    cout << "Game Bill: " << game_bill << endl;
    cout << "Total Bill: " << total_bill << endl;
}
void customer::display_food_menu()
{
    Food_menu menu;
    menu.seeMenu();
}
void customer::display_game_collection()
{
    GameCatalogue catalogue;
    catalogue.viewAllGames();
}
void customer::order_food()
{
    int id;
    double price;
    Food_menu menu;
    
    cout << "\nSelect food item ID: ";
    cin >> id;
    cout << "Enter price of selected item: ";
    cin >> price;
    food_bill += price;
    cout << "Food added to bill.\n";
}

void customer::reserve_game_zone()
{
    Rental rental;
    string timeSlot;
    int controllers;
    int minutes;

    cout << "\nEnter time slot: ";
    cin >> timeSlot;

    cout << "Controllers required: ";
    cin >> controllers;
    cout << "Duration (minutes): ";
    cin >> minutes;
    game_bill += rental.calculatePrice(controllers, minutes);
    cout << "Game zone reserved.\n";
}
