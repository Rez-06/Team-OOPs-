#include "kitchen_queue.h"
#include "AuthorizedPerson.h"
#include<bits/stdc++.h>
using namespace std;
bool KitchenQueue::addOrder(Order& order,Inventory &inv){
    if(order.IsOrderAcceptableThenDeductInventory(inv)){
        pendingOrders.push(order);
        cout << "Order Accepted.!!!" << endl;
        return true;
    }
    else{
        cout << "Not enough resources." << endl;
        return false;
    }
}
bool KitchenQueue:: hasOrders() const{
    return  !(pendingOrders.empty());
}
Order& KitchenQueue:: getNextOrder(){
    if(hasOrders()){
        return pendingOrders.front();
    }
    else{
        cout << "You don't have any order.Still called orderNext.Error!!!"<< endl; 
    }
}
void KitchenQueue::completeOrder(AuthorizedPerson* p){
   if(p->post()=="chef"){
        if(hasOrders()){
        Order o=getNextOrder();
        pendingOrders.pop();
        cout << "Started cooking orderID:" << o.getOrderId() << endl;
        o.setStatus("Cooking");
        o.DisplayDetails();
        /////simulation
        cout << "Finished cooking orderID:" << o.getOrderId() << endl;
        o.setStatus("Complete");
        o.DisplayDetails();
        }
    }
    else{
        cout << p->post() << " can not cook" << endl;
    }
}
void KitchenQueue::completeAllOrders(AuthorizedPerson* p){
    if(p->post()=="chef"){
     while(hasOrders()){
        completeOrder(p);
     }
    }
    else{
       cout << p->post() << " can not cook" << endl;
    }
}
