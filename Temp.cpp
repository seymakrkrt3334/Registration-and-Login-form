#include "Temp.h"

void Temp::signUP() {
    cout << "\nEnter Your User Name :: ";
    cin.ignore(); // Önceki inputlarý temizler
    getline(cin, userName);
    cout << "Enter Your Email Address :: ";
    getline(cin, Email);
    cout << "Enter Your Password :: ";
    getline(cin, password);

    file.open("loginData.txt", ios::out | ios::app);
    if (!file) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }
    file << userName << "*" << Email << "*" << password << endl;
    file.close();
}

void Temp::login() {
    cout << "----------LOGIN---------" << endl;
    cout << "Enter Your User Name :: ";
    cin.ignore(); // Önceki inputlarý temizler
    getline(cin, searchName);
    cout << "Enter Your Password :: ";
    getline(cin, searchPass);

    file.open("loginData.txt", ios::in);
    if (!file) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }
    string line;
    bool found = false;
    while (getline(file, line)) {
        size_t pos1 = line.find('*');
        size_t pos2 = line.find('*', pos1 + 1);

        if (pos1 == string::npos || pos2 == string::npos) continue;

        userName = line.substr(0, pos1);
        Email = line.substr(pos1 + 1, pos2 - pos1 - 1);
        password = line.substr(pos2 + 1);

        if (userName == searchName && password == searchPass) {
            cout << "\nAccount Login Successful...!" << endl;
            cout << "Username :: " << userName << endl;
            cout << "Email :: " << Email << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Invalid username or password." << endl;
    }

    file.close();
}

void Temp::forgot() {
    cout << "\nEnter Your UserName :: ";
    cin.ignore(); // Önceki inputlarý temizler
    getline(cin, searchName);
    cout << "Enter Your Email Address :: ";
    getline(cin, searchEmail);

    file.open("loginData.txt", ios::in);
    if (!file) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }
    string line;
    bool found = false;
    while (getline(file, line)) {
        size_t pos1 = line.find('*');
        size_t pos2 = line.find('*', pos1 + 1);

        if (pos1 == string::npos || pos2 == string::npos) continue;

        userName = line.substr(0, pos1);
        Email = line.substr(pos1 + 1, pos2 - pos1 - 1);
        password = line.substr(pos2 + 1);

        if (userName == searchName && Email == searchEmail) {
            cout << "\nAccount Found...!" << endl;
            cout << "Your Password :: " << password << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Account not found...!" << endl;
    }

    file.close();
}
