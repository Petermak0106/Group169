//login_menu.cpp
#include <iostream>
#include "login_menu.h"
using namespace std;

char login_menu() {
    char login_choice;

    cout << "1. Register a new account." << endl;
    cout << "2. Login as existing account." << endl;
    cout << "0. Quit game. " << endl;
    cout << "Please enter your choice: ";

    //read user selection
    cin >> login_choice;
    return login_choice;

}
