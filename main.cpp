#include<iostream>
#include<string>
#include<fstream>
#include "Temp.h"
using namespace std;

int main() {
	Temp obj;
	char choice;
	cout << "1)Log-in" << endl;
	cout << "2)sign-up" << endl;
	cout << "3)Forget Password" <<endl;
	cout << "4)Exit" << endl;

	switch (choice) {
	case '1':
		cin.ignore();
		obj.login();
	case '2':
		cin.ignore();
		obj.signUP();
	case '3':
		cin.ignore();
		obj.forgot();
	case '4':
		return 0;
		break;

	default:
		cout << "your choice is invalid!!!" << endl;
	}

}
