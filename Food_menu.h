#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;



struct IngredientUsage{
    int ingredientID;
    double amount;
};

struct MenuItem{
    int id;
    char name[50];
    double price;

    char recipe[300];
    IngredientUsage ingredients[20];
    int ingredientCount;
};

class Food_menu{
private:
    int generateId();
public:
    void addMenu();
    void seeMenu();
    void updateMenuItem();
    void deleteMenuItem();
    void searchByName();
    void searchByPriceRange();
    void viewRecipe();
};
