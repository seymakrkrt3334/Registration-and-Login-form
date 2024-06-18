
#include "Index.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Index::signup() {
    cout << "Enter your user name: ";
    getline(cin, username);
    cout << "Enter your email: ";
    getline(cin, email);
    cout << "Enter your password: ";
    getline(cin, password);

    file.open("database.txt", ios::out | ios::app);
    if (!file) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }
    file << username << "*" << email << "*" << password << endl;
    file.close();
}

void Index::login() {
    cout << "----------------LOG-IN-----------------" << endl;
    cout << "Enter your username: ";
    getline(cin, searchName);
    cout << "Enter your password: ";
    getline(cin, searchPass);

    file.open("database.txt", ios::in);
    if (!file) {
        cout << "Error opening file for reading!" << endl;
        return;
    }

    string line;
    bool found = false;
    while (getline(file, line)) {
        size_t pos1 = line.find('*');
        size_t pos2 = line.find('*', pos1 + 1);

        if (pos1 == string::npos || pos2 == string::npos) continue;

        username = line.substr(0, pos1);
        email = line.substr(pos1 + 1, pos2 - pos1 - 1);
        password = line.substr(pos2 + 1);

        if (username == searchName && password == searchPass) {
            cout << "Account login successful!" << endl;
            cout << "Username: " << username << endl;
            cout << "Password: " << password << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Invalid username or password." << endl;
    }

    file.close();
}

void Index::forget() {
    cout << "\nEnter your username: ";
    getline(cin, searchName);
    cout << "Enter your email address: ";
    getline(cin, searchEmail);

    file.open("database.txt", ios::in);
    if (!file) {
        cout << "Error opening file for reading!" << endl;
        return;
    }

    string line;
    bool found = false;
    while (getline(file, line)) {
        size_t pos1 = line.find('*');
        size_t pos2 = line.find('*', pos1 + 1);

        if (pos1 == string::npos || pos2 == string::npos) continue;

        username = line.substr(0, pos1);
        email = line.substr(pos1 + 1, pos2 - pos1 - 1);
        password = line.substr(pos2 + 1);

        if (username == searchName && email == searchEmail) {
            cout << "Account found..." << endl;
            cout << "Password: " << password << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Account not found..." << endl;
    }

    file.close();
}

