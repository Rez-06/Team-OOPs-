
#include <iostream>
#include <fstream>
#include <limits>
#include "customer.h"
using namespace std;

customer::customer():o("pending"){
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

void customer::add_item_to_order()
{
    Food_menu menu;
    //menu.seeMenu();
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
            o.addItem(item,1);
            break;
        }
    }
    if(!found){
        cout << "Food not found\n";
    }

    file.close();
}
void customer::remove_item_from_order(int itemId,int quantity){
    vector<OrderItem> Oi;
    Oi=o.getItems();
    for(int i=0;i<Oi.size();i++){
        if(Oi[i].item.id==itemId){
            o.removeItem(Oi[i].item,quantity);
            food_bill=o.getTotal();
            total_bill=food_bill+game_bill;
            break;
        }
    }
}
void customer::order_food(){
    Food_menu fm;
    while(true){ 
    fm.seeMenu();
    cout << "commands\n1-view Ordered Items\n2-Add item to order\n3-Remove item from order\n4-Go Back\n";
    char choice;
    cin >> choice;
    if(choice=='4'){
        break;
    }
    switch(choice){
        case '1':
            o.DisplayDetails();
            break;
        case '2':
            add_item_to_order();
            break;
        case '3':
            int id;
            cout << "Please enter item ID: ";
            cin >> id;
            cout << "Enter quantity: ";
            int quantity;
            cin >> quantity; 
            remove_item_from_order(id,quantity);
            break;
        default:
            cout<<"Invalid input"<<endl;
            break;
    }
   }
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
Order customer::getOrder() const{
     return o;
}
void customer::copyOrder(const Order orr){
    o=orr;
}
void customer::order_detail() const{
    o.DisplayDetails();
}
float customer::getFoodBill() const{
    return food_bill;
}
float customer::getGameBill() const{
    return game_bill;
}
float customer::getTotalBill() const{
    return total_bill;
}