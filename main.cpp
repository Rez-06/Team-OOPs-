#include<iostream>
#include "login.h"
using namespace std;



int main(){
    temp obj;
    while(true){
        char choice;
        cout<<"\n\n\n1- Login"<<endl;
        cout<<"2- Sign-up"<<endl;
        cout<<"3- Forgot Password"<<endl;
        cout<<"4- Exit\n\n\n"<<endl;
        cin>>choice;
        cin.ignore();
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
    }

}
