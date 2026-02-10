#include "passcode.h"
#include<iostream>
using namespace std;

pass::pass(): adminPass("admin123"), chefPass("chef345"),admin(false), chef(false) {}

void pass::isAdmin(string x){
    if(x==adminPass){
        admin=true; cout<<"Welcome Admin!"<<endl;
    } else cout<<"Failed attempt"<<endl;
}

void pass::isChef(string x){
    if(x==chefPass){ chef=true;
    cout<<"\n\nWelcome Chef!"<<endl;
    } else{ cout<<"Failed Attempt"<<endl; }
}

bool pass::isAdmin(){
    return (admin==true);
    }

bool pass::isChef(){
    return( chef==true);
    }

void pass::resetRoles() { admin = false; chef = false; }
