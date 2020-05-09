//shop.cpp
#include <iostream>
#include "shop.h"
#include "Account.h"
using namespace std;

void shop (Account *p1, Account *p2) {
    char shop_choice;
    ifstream fin;
    fin.open("shop.txt");
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();
    cout << "Enter your choice: ";
    cin >> shop_choice;
    cout << endl;
    while (shop_choice != '0') {
        if (shop_choice == '1') {
            cout << "Which player wants to purchase? Enter your username. (" << p1->name << "/ " << p2->name << "): ";
            string username;
            cin >> username;
            cout << endl;
            if (username == p1->name) {
                purchase(p1);
            }
            else if (username == p2->name) {
                purchase(p2);
            }
            else {
                cout << "Invalid input!" << endl;
            }
        }
        else {
            cout << "Invalid input!" << endl;
        }
        fin.open("shop.txt");
        line = "";
        while (getline(fin, line)) {
            cout << line << endl;
        }
        fin.close();
        cin >> shop_choice;
    }
    return;
}

