#include<iostream>
#include "login.h"
using namespace std;

int main(){
    char choice;
    cout<<"1- Login"<<endl;
    cout<<"2- Sign-up"<<endl;
    cout<<"3- Forgot Password"<<endl;
    cout<<"4- Exit"<<endl;
    cin>>choice;

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
}
