#ifndef  AUTHORIZED_PERSON_H
#define AUTHORIZED_PERSON_H
#include<bits/stdc++.h>
using namespace std;
class AuthorizedPerson{
    protected:
    string name;
    int id;
    string eMail;
    public:
    AuthorizedPerson(string Name,int Id,string EMail):name(Name),id(Id),eMail(EMail){

    }
    virtual void Identity() const=0;
    virtual string post() const=0;
    virtual ~AuthorizedPerson(){}
};


#endif