#include "order.h"
#include<bits/stdc++.h>
using namespace std;
int Order::orderCount=0;
Order::Order(string Status="pending"):orderId(orderCount){
    totalAmount=0;
    status=Status;
    orderCount++;
}
void Order::addItem(MenuItem menuitem,int quantity){
    OrderItem i;
    i.item=menuitem;
    i.quantity=quantity;
    totalAmount+=((menuitem.price)*quantity);
    items.push_back(i); 
}
void Order::removeItem(MenuItem menuitem,int quantity){
    int i=0;
    int bulb=0;
    int previous_quantity;
    for(;i<items.size();i++){
        if(items[i].item.name==menuitem.name){
            previous_quantity=items[i].quantity;
            items[i].quantity-=quantity;
            bulb=1;
            break;
        }
    }
    if(bulb){
        double k;
        if(previous_quantity<quantity){
            k=previous_quantity*items[i].item.price;
        }
        else{
            k=quantity*items[i].item.price;
        }
        totalAmount-=k;
    }
    if(bulb && items[i].quantity<=0){
        items.erase(items.begin()+i);
    }
}
bool Order::IsOrderAcceptableThenDeductInventory(Inventory &inv){
    bool bulb=true;
    int k=0; 
    //double cost=0;
    for(;k<items.size();k++){
        if(inv.isAvailable(items[k].item,items[k].quantity)){
            inv.deductIngredients(items[k].item,items[k].quantity);
            //cost+=(items[k].item.price*items[k].quantity);
        }
        else{
            bulb=false;
        }
     }
     if(!bulb){
        for(int j=0;j<k;j++){
            inv.addIngredientAccordingToMakeParticularItem(items[j].item,items[j].quantity);
        }
        status="rejected";
        return bulb;
     }
     else{
        //totalAmount+=cost;
        return bulb;
     }     
}
double Order::getTotal() const{
    return totalAmount;
}
int Order::getOrderId() const{
    return orderId;
}
string Order::getStatus() const{
    return status; 
}
vector<OrderItem> Order::getItems() const{
    return items;
}
void Order::setStatus(const string Status){
    status=Status;
}
void Order::DisplayDetails() const{
   cout << "OrderId: " << getOrderId() << endl;
   cout << "Bill   : $$" << getTotal() << endl;
   cout << "Items  :" << endl;
   for(int i=0;i<items.size();i++){
      cout << i+1 << "." << items[i].item.name << "-----" << items[i].quantity << endl;
   }
   cout << "Status :"<< getStatus() << endl;   
} 
Order Order::operator+=(OrderItem order_item){
     addItem(order_item.item,order_item.quantity);
     return *this;
}
Order Order::operator-=(OrderItem order_item){
     removeItem(order_item.item,order_item.quantity);
     return *this;
}

