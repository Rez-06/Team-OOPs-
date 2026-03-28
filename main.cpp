#include<iostream>
#include "login.h"
#include "Admin.h"
#include "Customer.h"
#include "kitchen_queue.h"
#include "order.h"
#include "chef.h"
using namespace std;
void goodbuy(AuthorizedPerson *a){
    if(a->post()=="chef"){
        cout << "Good bye Chef" << endl;
    }
    else if(a->post()=="Admin"){
        cout << "Good bye Admin" << endl;
    }
}
int main(){

    temp obj;
    Food_menu fm;
    Inventory iv;
    GameCatalogue gc;
    Rental rn;
    Register reg;
    KitchenQueue kq;
    Order tempo("pending");
    while(true){
        char choice;
        cout<<"====Welcome to XOR Gaming Cafe===="<<endl;
        cout<<"\n\n\n1- Login"<<endl; cout<<"2- Sign-up"<<endl;
        cout<<"3- Forgot Password"<<endl; cout<<"4- Exit\n\n\n"<<endl;
        cin>>choice; cin.ignore();
        switch(choice){
            case '1':
                obj.login();
                break;
            case '2':
                obj.signUP();
                break;
            case '3':
                obj.forgot();
                break;
            case '4':
                return 0;
                break;
            default:
                cout<<"Invalid input"<<endl;
                break;
        }
        if(choice=='4')break; 
        if(obj.isLoggedIn()==true)break;
    }
    int bulb=1;
    while(true){
        AuthorizedPerson *ath;
        if(obj.isAdmin()){
            Admin a(obj.getName(),obj.getId(),obj.getEmail(),obj.getShare());
            ath=&a;
            if(bulb){
                a.Identity();
                bulb=0;
            }
            char choice;
            cout << "====Choose command====" << endl;
            cout << "1-Food Menu\n2-Inventory \n3-Game Ctalogue\n4-Update Rental Price\n5-Register View\n6-Cash Out $$\n7-exit" <<endl;
            cout << "Command: ";
            cin >> choice;
            if(choice=='7'){
                    goodbuy(ath);
                    break;
            }
            switch(choice){
                case '1':
                    a.manageFoodMenu(fm);
                    break;
                case '2':
                    a.manageInventory(iv);
                    break;
                case '3':
                    a.manageGameCatalogue(gc);
                    break;
                case '4':
                    a.updateRentalPricing(rn);
                    break;
                case '5':
                    a.viewRegister(reg);
                    break;
                case '6':
                    a.cashOut(reg);
                    break;
                case '7':
                    break;
                default:
                    cout<<"Invalid input"<<endl;
                    break;
            }
        }
        else if(obj.IsCustomer()){
            customer c;
            cout << "====Welcome to XOR====" << endl;
            cout << "====Choose command====" << endl;
            cout << "1.Display Food Menu\n2.Display Bill\n3.Display Game Collection\n4.Oeder Food\n5.Reserve Game Zone\n6.Exit\n7.See Order Detail\n";
            char choice;
            cin >> choice;
            if(choice=='6'){
                cout << "====Do come again====" << endl;
                break;
            }
            switch(choice){
                case '1':
                    c.display_food_menu();
                    break;
                case '2':
                    c.Display_bill();
                    break;
                case '3':
                    c.display_game_collection();
                    break;
                case '4':
                    while(true){  
                        c.order_food();
                        
                        tempo=c.getOrder();
                        if(kq.addOrder(tempo,iv)){
                            reg.addTransaction("Food","food money",c.getFoodBill());
                            break;
                        }
                        else{
                            int desition;
                            cout << "command:\n1-Change Order\n2-See Order details\n3-Exit\n";
                            cin >> desition;
                            if(desition==1){
                                c.copyOrder(tempo);
                                continue;
                            }
                            else if(desition==2){
                                c.order_detail();
                                continue;
                            }
                            else{
                                c.copyOrder(tempo);
                                break;
                            }
                        }
                    }
                    break;
                case '5':
                    c.reserve_game_zone();
                    break;
                case '7':
                     c.order_detail();
                     break;
                default:
                    cout<<"Invalid input"<<endl;
                    break;
            }

        }
        else if(obj.isChef()){
            
            cout << "Welcome chef\n";
            cout << "Choose command: \n1-view pending orders\n2-view recipe\n3-complete order\n4-exit\n";
            char choice;
            cin >> choice;
            Chef c(obj.getName(),obj.getId(),obj.getEmail(),obj.getJoinDate());
            if(choice==4){
                cout << "Goodbye chef\n";
                break;
            }
            switch(choice){
                case '1':
                   c.viewPendingOrders(kq);
                   break;
                case '2':
                   cout << "Enter menu id\n";
                   int id;
                   cin >> id;
                   c.viewRecipe(id,fm);
                   break;
                case '3':
                   c.completeOrder(kq);
                   break;
                case '4':
                   break;
                default:
                   cout<<"Invalid input"<<endl;
                    break;
                 
            }
        }
    }
   
}
