#include "customer.h"
#include "Register.h"
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

customer::customer()
{
    total_bill = 0;
    food_bill = 0;
    game_bill = 0;
}

void customer::Display_bill()
{
    total_bill = food_bill + game_bill;

    cout << "\n===== BILL SUMMARY =====\n";
    cout << "Food Bill: " << food_bill << " BDT\n";
    cout << "Game Bill: " << game_bill << " BDT\n";
    cout << "Total Bill: " << total_bill << " BDT\n";
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
    Food_menu menu;
    menu.seeMenu();

    ifstream file("menu.dat", ios::binary);
    if(!file){
        cout << "Menu not available\n";
        return;
    }

    int id;
    cout << "\nEnter food ID: ";
    cin >> id;

    MenuItem item;
    bool found = false;

    while(file.read((char*)&item, sizeof(item))){
        if(item.id == id){
            food_bill += item.price;
            cout << "Added: " << item.name << " | Price: " << item.price << " BDT\n";
            found = true;
            break;
        }
    }

    if(!found){
        cout << "Food not found\n";
    }

    file.close();
}

void customer::reserve_game_zone()
{
    Rental rental;
    Register reg;

    string timeSlot;
    int controllers;
    int minutes;

    cout << "\nEnter time slot: ";
    cin.ignore();
    getline(cin, timeSlot);

    cout << "Controllers: ";
    cin >> controllers;

    cout << "Duration (30 or 60): ";
    cin >> minutes;

    try{
        rental.bookSlot(timeSlot, controllers, minutes, reg);
        game_bill += rental.calculatePrice(controllers, minutes);
    }
    catch(exception &e){
        cout << "Error: " << e.what() << endl;
    }
}
