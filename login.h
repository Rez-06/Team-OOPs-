#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class temp{
    string userName,Email,password;
    fstream file;
    string searchName,searchPass,searchEmail;
public:
    void login();
    void signUP();
    void forgot();
}obj;
