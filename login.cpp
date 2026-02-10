#include "login.h"
#include "passcode.h"
#include <iostream>
#include <cstdlib>
using namespace std;
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    }
    bool temp::isLoggedIn(){
        return (loggedIn==true);
    }
    void temp::login(){
        cout<<"--------LOGIN---------";
        cout<<"\nEnter Your User Name ::";
        getline(cin,searchName);
        cout<<"Enter Your Password ::";
        getline(cin,searchPass);
        file.open("loginData.txt",ios::in);
        loggedIn =false;
        while (getline(file, userName, '*')) {
            getline(file, Email, '*');
        getline(file, password);
        if (userName == searchName && password == searchPass) {
            clearScreen();
            cout << "\nAccount Login Successful...";
            cout << "\nUsername ::" << userName;
            cout << "\nEmail ::" << Email << endl;
            loggedIn = true; resetRoles();
            while(true){
                cout<<"\n\nSelect Mode"<<endl;
                cout<<"1. Admin"<<endl;
                cout<<"2. Chef"<<endl;
                cout<<"3. Customer"<<endl;
                char mode; cin>>mode;
                cin.ignore();
                bool isCustomer=false;
                string temp;
                switch(mode){
                    case '1':
                        cout<<"Admin key::";
                        getline(cin,temp);
                        isAdmin(temp);

                        break;
                    case '2':
                        cout<<"Chef key::";
                        getline(cin,temp);
                        isChef(temp);
                        break;
                    case '3':
                        cout<<"\n\t\tWelcome "<<userName<<" to XOR Gaming Cafe"<<endl;
                        isCustomer=true;
                        break;
                    default:
                        cout<<"Invalid"<<endl;
                        break;
                }
                if(isAdmin()==true || isChef()==true || isCustomer==true)break;
            }
            break;
        }
    }
    if(loggedIn==false)cout<<"Login Attempt Failed"<<endl;
    file.close();
}
void temp::signUP(){
    cout<<"Enter your User Name ::";
    getline(cin,userName);
    cout<<"Enter Your Email Address ::";
    getline(cin,Email);
    cout<<"Enter Your Password ::";
    getline(cin,password);
    file.open("loginData.txt",ios :: out | ios :: app);
    file<<userName<<"*"<<Email<<"*"<<password<<endl;
    file.close();
    clearScreen();
    cout<<"Sign Up successful"<<endl;
    }
void temp::forgot(){
    cout<<"\nEnter Your User Name ::";
    getline(cin,searchName);
    cout<<"\nEnter Your Email Address ::";
    getline(cin,searchEmail);
    file.open("loginData.txt",ios::in);
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,password,'\n');
    bool found=false;
    while (getline(file, userName, '*')) {
        getline(file, Email, '*');
        getline(file, password);
        if (userName == searchName && Email == searchEmail) {
            clearScreen();
            cout << "\nAccount Found..!\n";
            cout << "Your Password :: " << password << endl;
            file.close();
            file.open("loginData.txt", ios::out | ios::app);
            if (file) {
                file << searchName << "*" << searchEmail << "*" << password << endl;
                file.close(); cout << "Info appended successfully!\n";
                }
                found = true;
                break;
        }
    }
    if(found!=true){ clearScreen(); cout<<"\nNot found..."; file.close(); }
}
