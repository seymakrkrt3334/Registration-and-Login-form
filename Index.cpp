#ifndef INDEX_H
#define INDEX_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Index {
private:
    string username;
    string email; // email �yesinin do�ru tan�mlanmas�
    string password;
    string searchName;
    string searchEmail;
    string searchPass;
    fstream file;

public:
    void signup();
    void login();
    void forget();
};

#endif 
