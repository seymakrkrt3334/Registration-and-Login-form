

#ifndef TEMP_H
#define TEMP_h

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Temp {
    string userName, Email, password;
    string searchName, searchPass, searchEmail;
    fstream file;

public:
    void login();
    void signUP();
    void forgot();
};


#endif