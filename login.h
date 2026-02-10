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
    public:
        bool isLoggedIn();
        void login();
        void signUP();
        void forgot();
};
#endif
