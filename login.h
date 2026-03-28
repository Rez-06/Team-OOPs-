#ifndef LOGIN_H

#define LOGIN_H
#include <iostream>
#include <fstream>
#include <string>
#include "passcode.h"
using namespace std;

class temp : public pass {
    string userName, Email, password;
    fstream file;
    string searchName, searchPass, searchEmail;
    bool loggedIn;
    bool isCustomer=false;
    int id;
    string share;
    string joinDate;
    public:
        bool isLoggedIn();
        void login();
        void signUP();
        void forgot();
        bool IsCustomer() const;
        int getId() const;
        string getShare() const;
        string getJoinDate() const;
        string getEmail() const;
        string getName() const;
};
#endif
