#include "login.h"
#include <iostream>
using namespace std;

void temp::login(){
    cout<<"--------LOGIN---------";
    cout<<"Enter Your User Name ::";
    cin.ignore();
    getline(cin,searchName);
    cout<<"Enter Your Password ::";
    getline(cin,searchPass);
    file.open("loginData.txt",ios::in);
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,password,'\n');
    bool log=false;
    while(!file.eof()){
        if(userName==searchName){
            if(password==searchPass){
                cout<<"\nAccount Login Successful...";
                cout<<"\nUsername ::"<<userName<<endl;
                cout<<"\nEmail ::"<<Email<<endl;
                log=true;
                break;
            }
        }
        getline(file,userName,'*');
        getline(file,Email,'*');
        getline(file,password,'\n');
    }
    if(log==false)cout<<"Login Attempt Failed"<<endl;
    file.close();


}

void temp::signUP(){
    cout<<"Enter your User Name ::";
    cin.ignore();
    getline(cin,userName);
    cout<<"Enter Your Email Address ::";
    getline(cin,Email);
    cout<<"Enter Your Password ::";
    getline(cin,password);

    file.open("loginData.txt",ios :: out | ios :: app);
    file<<userName<<"*"<<Email<<"*"<<password<<endl;
    file.close();

}

void temp::forgot(){
     cout<<"\nEnter Your User Name ::";
     cin.ignore();
     getline(cin,searchName);
     cout<<"\nEnter Your Email Address ::";
     getline(cin,searchEmail);

     file.open("loginData.txt",ios::in);
     getline(file,userName,'*');
     getline(file,Email,'*');
     getline(file,password,'\n');
     bool found=false;
     while(!file.eof()){
        if(userName==searchName){
            if(Email==searchEmail){
                cout<<"\nAccount Found..!"<<endl;
                cout<<"Your Password :: "<<password<<endl;
                file.close();
                file.open("loginData.txt",ios :: out | ios :: app);
                file<<searchName<<"*"<<searchEmail<<"*"<<password<<endl;
                file.close();
                found=true;
            }

        }
        getline(file,userName,'*');
        getline(file,Email,'*');
        getline(file,password,'\n');
     }
     if(found!=true)cout<<"\nNot found...";


}
