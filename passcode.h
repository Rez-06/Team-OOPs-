#ifndef PASSCODE_H

#define PASSCODE_H
#include <string>
using namespace std;

class pass {
    private:
        const string adminPass;
        const string chefPass;
        bool admin;
        bool chef;
    public:
        pass();
        void isAdmin(string x);
        void isChef(string x);
        bool isAdmin();
        bool isChef();
        void resetRoles();
};

#endif
