#include<iostream>
#include<fstream>
#include<cstring>
#include<limits>
#include "Inventory.h"
using namespace std;

void Inventory::addIngredient(){
    ofstream file("ingredient.dat",ios::binary | ios::app);
    if(!file){
        cout<<"File error\n";
        return;
    }
    Ingredient ing;


    cout<<"Enter ingredient ID: ";
    cin>>ing.id;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout<<"Enter ingredient name: ";
    cin.getline(ing.name,50);
    cout<<"Enter initial stock (gm/pcs): ";
    cin>>ing.stock;

    file.write(reinterpret_cast<char*>(&ing),sizeof(ing));
    file.close();

    cout<<"Ingredient added successfully\n";

}

void Inventory::refillIngredient(){
    fstream file("ingredient.dat",ios::binary | ios::in | ios::out);
    if(!file){
        cout<<"Inventory file not found\n";
        return;

    }

    int targetId;
    cout<<"Enter ingredient ID to refill: ";
    cin>>targetId;

    Ingredient ing;
    bool found= false;
    while(file.read(reinterpret_cast<char*>(&ing),sizeof(ing))){
        if(ing.id==targetId){
            double amount;
            cout<<"Enter refill amount: ";
            cin>>amount;

            ing.stock+=amount;

            file.seekp(-static_cast<int>(sizeof(ing)),ios::cur);
            file.write(reinterpret_cast<char*>(&ing),sizeof(ing));
            found=true;
            break;
        }
    }
    file.close();
    if(found)cout<<"Stock refilled\n";
    else cout<<"ingredient not found\n";


}


