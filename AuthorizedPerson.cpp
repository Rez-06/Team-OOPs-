#include "AuthorizedPerson.h"
#include <iostream>
using namespace std;

class Admin : public AuthorizedPerson {
//admin
public:
    Admin(string Name, int Id, string Email)
        : AuthorizedPerson(Name, Id, Email) {}

    void Identity() const override {
        cout << "Role: Admin" << endl;
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Email: " << eMail << endl;
    }

    string post() const override {
        return "Admin";
    }
};
//customer
class Customer : public AuthorizedPerson {
public:
    Customer(string Name, int Id, string Email)
        : AuthorizedPerson(Name, Id, Email) {}
        
    void Identity() const override {
        cout << "Role: Customer" << endl;
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Email: " << eMail << endl;
    }
    string post() const override {
        return "Customer";
    }
};
