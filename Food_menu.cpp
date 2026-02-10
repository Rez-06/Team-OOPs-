#include<iostream>
#include<fstream>
#include<cstring>
#include "Food_menu.h"
#include<limits>
using namespace std;

int Food_menu::generateId(){
   ifstream file("menu.dat",ios::binary);
   if(!file)return 1;

   MenuItem item;
   file.seekg(0, ios::end);

   if(file.tellg() < (streampos)sizeof(item)){
    file.close();
    return 1;
   }

   file.seekg(-static_cast<int>(sizeof(item)), ios::end);
   file.read(reinterpret_cast<char*>(&item), sizeof(item));
   file.close();

   return item.id+1;

}

void Food_menu::addMenu(){
    ofstream file("menu.dat",ios::binary | ios::app);
    if(!file){
        cout<<"File error\n";
        return;
    }
    MenuItem item;
    item.id=generateId();

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout<< "Enter food name: ";
    cin.getline(item.name, 50);

    cout<<"Enter price: ";
    cin>>item.price;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    cout<<"Enter recipe (max 4-5 lines):\n";
    cin.getline(item.recipe,300);
    item.ingredientCount=0;

    char choice;
    do{
        cout<<"Add ingredient? (y/n): ";
        cin>>choice;

        if(choice=='y'){
            cout<<"Ingredient ID: ";
            cin >> item.ingredients[item.ingredientCount].ingredientID;

            cout<< "Amount needed(gm or pcs): ";
            cin>>item.ingredients[item.ingredientCount].amount;

            item.ingredientCount++;
        }
    }while(choice == 'y' && item.ingredientCount < 20);

    file.write(reinterpret_cast<char*>(&item), sizeof(item));
    file.close();

    cout<<"Item added successfully. Id="<<item.id<<"\n";
}

void Food_menu::seeMenu(){
    ifstream file("menu.dat",ios::binary);
    if(!file){
        cout<<"No menu found\n";
        return;
    }

    MenuItem item;
    cout<<"\n\t\t====Menu====\n";
    while(file.read((char*)&item,sizeof(item))){
        cout<<"ID: "<<item.id
            <<" | Name: "<<item.name
            <<" | Price: "<<item.price<<" BDT\n";
    }
    file.close();
}

void Food_menu::updateMenuItem(){
    fstream file("menu.dat",ios::binary | ios::in | ios::out);
    if(!file){
        cout<<"File error\n";
        return;
    }

    int targetId;
    cout<<"Enter ID to update: ";
    cin>>targetId;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    MenuItem item;
    bool found = false;

    while(file.read(reinterpret_cast<char*>(&item), sizeof(item))){
        if(item.id == targetId){
            cout<<"Enter new name: ";
            cin.getline(item.name,50);

            cout<<"Enter new price: ";
            cin>>item.price;

            file.seekp(-static_cast<int>(sizeof(item)), ios::cur);
            file.write(reinterpret_cast<char*>(&item), sizeof(item));

            found=true;
            break;
        }
    }
    file.close();
    if(found) cout<< "Item updated\n";
    else cout<<"Item not found\n";
}

void Food_menu::viewRecipe(){
    ifstream file("menu.dat", ios::binary);
    if(!file){
        cout<<"No menu food\n";
        return;
    }

    int targetId;
    cout<<"Enter food ID: ";
    cin>> targetId;

    MenuItem item;
    bool found = false;

    while(file.read(reinterpret_cast<char*>(&item),sizeof(item))){
        if(item.id==targetId){
            cout<<"\nFood: "<<item.name<<"\n";
            cout<<"Price: "<<item.price<<" BDT\n";

            cout<<"\n--Recipe--\n";
            cout<<item.recipe<<endl;
            cout<<"\n---Ingredients used---\n";
            for(int i=0;i<item.ingredientCount;i++){
                cout<<"Ingredient ID: "
                    <<item.ingredients[i].ingredientID
                    <<" | Amount: "
                    <<item.ingredients[i].amount<<endl;
            }
            found=true;
            break;
        }
    }
    file.close();
    if(!found)cout<<"Food item not found\n";
}
