#include "kitchen_queue.h"
#include "AuthorizedPerson.h"
#include<bits/stdc++.h>
using namespace std;
bool KitchenQueue::addOrder(Order order,Inventory &inv){
    
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
KitchenQueue::KitchenQueue(){
     ifstream file("Kitchen_queue.txt");
     string line;
     int order_count=-1;
     int item_count=-1;
     int ingredient_count=-1;
     vector<Order> ord;
     while(getline(file,line)){
        if(line[0]=='+'){
            Order o("pending");
            o=deserialization_order(line);
            order_count++;
            ord.push_back(o);
            item_count=-1;
            ingredient_count=-1;
        }
        if(line[0]=='#'){
            OrderItem i;
            i=deserialization_item(line);
            ord[order_count]+=i;
            item_count++;
            ingredient_count=-1;
        }
        if(line[0]=='&'){
            IngredientUsage i;
            i=deserialization_ingredients(line);
            ingredient_count++;
            vector<OrderItem> oi;
            oi=ord[order_count].getItems();
            oi[item_count].item.ingredients[ingredient_count]=i;
            for(int i=0;i<oi.size();i++){
                ord[order_count].setItem(oi[i],i);
            }
        }
     }
     for(int i=0;i<ord.size();i++){
        pendingOrders.push(ord[i]);
     }
}
KitchenQueue::~KitchenQueue(){
   ofstream file("Kitchen_queue.txt");
   while(!pendingOrders.empty()){
        Order o("pending");
        o=pendingOrders.front();
        string s1=serialization_order(o);
        file << s1 << endl;
        vector<OrderItem> oic;
        oic=o.getItems();
        for(int i=0;i<oic.size();i++){
            string s2=serialization_item(oic[i]);
            file << s2 << endl;
            for(int j=0;j<oic[i].item.ingredientCount;j++){
                string s3=serialization_ingredients(oic[i].item.ingredients[j]);
                file << s3 << endl;
            }
        }
        pendingOrders.pop();
   }
   file.close();
} 
string KitchenQueue::serialization_order(Order o){
     string s="";
     s="+"+to_string(o.getOrderId())+"*"+to_string(o.getTotal())+"*"+o.getStatus()+"*";
     return s;
}
string KitchenQueue::serialization_item(OrderItem i){
    string s="";
    s="#"+to_string(i.quantity)+"*"+to_string(i.item.id)+"*"+to_string(i.item.ingredientCount)+"*"+i.item.name+"*"+to_string(i.item.price)+"*"+i.item.recipe+"*";
    return s;
}
string KitchenQueue::serialization_ingredients(IngredientUsage i){
    string s;
    s="&"+to_string(i.ingredientID)+"*"+to_string(i.amount)+"*";
    return s;
}
Order KitchenQueue::deserialization_order(string s){
    Order o("pending");
    int count=0;
    for(int i=1;i<s.size();i++){
        string temp="";
        while(i<s.size() && s[i]!='*'){
            temp+=s[i];
            i++;
        }
        if(count==0){
            o.setOrderId(stoi(temp));
        }
        if(count==1){
           o.setTotal(stod(temp));
        }
        if(count==2){
            o.setStatus(temp);
        }
        count++;
    }
    return o;
}
OrderItem KitchenQueue::deserialization_item(string s){
    OrderItem oi;
    int count=0;
    for(int i=1;i<s.size();i++){
        string temp="";
        while(i<s.size() && s[i]!='*'){
            temp+=s[i];
            i++;
        }
        if(count==0){
           oi.quantity=stoi(temp);   
        }
        if(count==1){
            oi.item.id=stoi(temp);
        }
        if(count==2){
            oi.item.ingredientCount=stoi(temp);
        }
        if(count==3){
            for(int j=0;j<temp.size();j++){
                oi.item.name[j]=temp[j];
            }
        }
        if(count==4){
            oi.item.price=stod(temp);
        }
        if(count==5){
            for(int j=0;j<temp.size();j++){
                oi.item.recipe[j]=temp[j];
            }
        }
        count++;
    }
    return oi;
}
IngredientUsage KitchenQueue::deserialization_ingredients(string s){
    IngredientUsage ig;
    int count=0;
    for(int i=1;i<s.size();i++){
        string temp="";
        while(i<s.size() && s[i]!='*'){
            temp+=s[i];
            i++;
        }
        if(count==0){
            ig.ingredientID=stoi(temp);
        }
        if(count==1){
           ig.amount=stod(temp);
        }
        count++;
    }
    return ig;
}