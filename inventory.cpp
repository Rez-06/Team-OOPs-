
#include<iostream>
#include<fstream>
#include<cstring>
#include<limits>
#include "Inventory.h"

using namespace std;

void Inventory::addIngredient(){
    ifstream check("ingredient.dat", ios::binary);

    Ingredient ing, temp;
    cout<<"Enter ingredient ID: ";
    cin>>ing.id;

    //  Duplicate ID check
    while(check.read(reinterpret_cast<char*>(&temp), sizeof(temp))){
        if(temp.id == ing.id){
            cout<<"ID already exists!\n";
            check.close();
            return;
        }
    }
    check.close();

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout<<"Enter ingredient name: ";
    cin.getline(ing.name,50);

    cout<<"Enter initial stock (gm/pcs): ";
    cin>>ing.stock;

    ofstream file("ingredient.dat", ios::binary | ios::app);
    if(!file){
        cout<<"File error\n";
        return;
    }

    file.write(reinterpret_cast<char*>(&ing), sizeof(ing));
    file.close();

    cout<<"Ingredient added successfully\n";
}

void Inventory::refillIngredient(){
    fstream file("ingredient.dat", ios::binary | ios::in | ios::out);
    if(!file){
        cout<<"Inventory file not found\n";
        return;
    }

    int targetId;
    cout<<"Enter ingredient ID to refill: ";
    cin>>targetId;

    Ingredient ing;
    bool found = false;

    while(file.read(reinterpret_cast<char*>(&ing), sizeof(ing))){
        if(ing.id == targetId){
            double amount;
            cout<<"Enter refill amount: ";
            cin>>amount;

            ing.stock += amount;

            file.seekp(-static_cast<streamoff>(sizeof(ing)), ios::cur);
            file.write(reinterpret_cast<char*>(&ing), sizeof(ing));

            found = true;
            break;
        }
    }

    file.close();

    if(found) cout<<"Stock refilled\n";
    else cout<<"Ingredient not found\n";
}

void Inventory::viewInventory(){
    ifstream file("ingredient.dat", ios::binary);
    if(!file){
        cout<<"No inventory found\n";
        return;
    }

    Ingredient ing;
    cout<<"\n==== Inventory ====\n";

    while(file.read(reinterpret_cast<char*>(&ing), sizeof(ing))){
        cout<<"ID: "<<ing.id
            <<" | Name: "<<ing.name
            <<" | Stock: "<<ing.stock<<"\n";
    }

    file.close();
}

void Inventory::updateIngredient(){
    fstream file("ingredient.dat", ios::binary | ios::in | ios::out);
    if(!file){
        cout<<"File error\n";
        return;
    }

    int targetId;
    cout<<"Enter ingredient ID to update: ";
    cin>>targetId;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Ingredient ing;
    bool found = false;

    while(file.read(reinterpret_cast<char*>(&ing), sizeof(ing))){
        if(ing.id == targetId){
            cout<<"Enter new name: ";
            cin.getline(ing.name,50);

            cout<<"Enter new stock: ";
            cin>>ing.stock;

            file.seekp(-static_cast<streamoff>(sizeof(ing)), ios::cur);
            file.write(reinterpret_cast<char*>(&ing), sizeof(ing));

            found = true;
            break;
        }
    }

    file.close();

    if(found) cout<<"Ingredient updated\n";
    else cout<<"Ingredient not found\n";
}

bool Inventory::isAvailable(const MenuItem& item, int quantity){
    ifstream file("ingredient.dat", ios::binary);
    if(!file) return false;

    for(int i = 0; i < item.ingredientCount; i++){
        Ingredient ing;
        bool found = false;

        file.clear();
        file.seekg(0);

        while(file.read(reinterpret_cast<char*>(&ing), sizeof(ing))){
            if(ing.id == item.ingredients[i].ingredientID){
                if(ing.stock < item.ingredients[i].amount * quantity){
                    file.close();
                    return false;
                }
                found = true;
                break;
            }
        }

        if(!found){
            file.close();
            return false;
        }
    }

    file.close();
    return true;
}

void Inventory::deductIngredients(const MenuItem& item, int qty){
    fstream file("ingredient.dat", ios::binary | ios::in | ios::out);
    if(!file) return;

    for(int i = 0; i < item.ingredientCount; i++){
        Ingredient ing;

        file.clear();
        file.seekg(0);

        while(file.read(reinterpret_cast<char*>(&ing), sizeof(ing))){
            if(ing.id == item.ingredients[i].ingredientID){
                ing.stock -= item.ingredients[i].amount * qty;

                file.seekp(-static_cast<streamoff>(sizeof(ing)), ios::cur);
                file.write(reinterpret_cast<char*>(&ing), sizeof(ing));
                break;
            }
        }
    }

    file.close();
}

// Optional helper (you can modify later)
void Inventory::addIngredientAccordingToMakeParticularItem(const MenuItem& item, int qty){
    fstream file("ingredient.dat", ios::binary | ios::in | ios::out);
    if(!file) return;

    for(int i = 0; i < item.ingredientCount; i++){
        Ingredient ing;

        file.clear();
        file.seekg(0);

        while(file.read(reinterpret_cast<char*>(&ing), sizeof(ing))){
            if(ing.id == item.ingredients[i].ingredientID){
                ing.stock += item.ingredients[i].amount * qty;

                file.seekp(-static_cast<streamoff>(sizeof(ing)), ios::cur);
                file.write(reinterpret_cast<char*>(&ing), sizeof(ing));
                break;
            }
        }
    }

    file.close();
}
