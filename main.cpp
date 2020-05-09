//main.cpp
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "main.h"
#include "Account.h"
#include "Battle.h"
#include "add_account.h"
#include "RunBattle.h"
#include "CheckItems.h"
#include "grow_account_list.h"
#include "load_account_list.h"
#include "login_menu.h"
#include "purchase.h"
#include "search_account.h"
#include "SetBattle.h"
#include "shop.h"
#include "update.h"

using namespace std;

int main() {
    int ac_list_size = 2, num_records = 0;
    Account *account = new Account[ac_list_size];
    num_records = load_account(account, ac_list_size);
    //print_account(account, num_records);
    Account p1, p2;
    cout << "*************************" << endl;
    cout << "* Welcome to 169 Battle *" << endl;
    cout << "*************************" << endl;
    cout << endl;

    cout << "Login to player 1." << endl;
    char login_choice_p1 = login_menu();
    while (login_choice_p1 != '0') {
        if (login_choice_p1 == '1') {
            p1 = add_account(account, num_records);
            cout << "Logged in as " << p1.name << endl;;
            break;
        } 
        else if (login_choice_p1 == '2') {
            p1 = search_account(account, num_records);
            cout << "Logged in as " << p1.name << endl;
            break;
        }
        else {
            cout << "Invalid input!" << endl;
        }
        login_choice_p1 = login_menu();
    }
    cout << endl;

    char login_choice_p2;
    if (login_choice_p1 != '0') {
        cout << "Login to player 2." << endl;
        login_choice_p2 = login_menu();
        while (login_choice_p2 != '0') {
            if (login_choice_p2 == '1') {
                p2 = add_account(account, num_records);
                if (p2.name == p1.name) {
                    cout << "Same account is not allowed!" << endl;
                    continue;
                }
                else {
                    cout << "Logged in as " << p2.name << endl;
                    break;
                }
            } 
            else if (login_choice_p2 == '2') {
                p2 = search_account(account, num_records);
                if (p2.name == p1.name) {
                    cout << "Same account is not allowed!" << endl;
                    continue;
                }
                else {
                    cout << "Logged in as " << p2.name << endl;
                    break;
                }
            } 
            else {
                cout << "Invalid input!" << endl;
            }
            login_choice_p2 = login_menu();
        }
    }

    //main menu
    if (login_choice_p1 != '0' && login_choice_p2 != '0') {
        cout << endl;
        char main_menu_choice;
        while (main_menu_choice != '0') {
            update (&p1);
            update (&p2);
            cout << "*******************" << endl;
            cout << "*    Main menu    *" << endl;
            cout << "*******************" << endl;
            cout << left;
            cout << setw(10) << p1.name << " Level: " << setw(5) << p1.level << " Exp: " << setw(10) << p1.exp << endl;
            cout << setw(10) << p2.name << " Level: " << setw(5) << p2.level << " Exp: " << setw(10) << p2.exp << endl;
            cout << "1. Start a battle." << endl;
            cout << "2. Check items" << endl;
            cout << "3. Shop." << endl;
            cout << "4. Display game rules" << endl;
            cout << "0. Quit game." << endl;
            cout << "Please enter your choice: ";
            cin >> main_menu_choice;
            cout << endl;
        
            if (main_menu_choice == '2') {
                CheckItems(&p1, &p2);
                continue;
            }
            if (main_menu_choice == '3') {
                shop(&p1, &p2);
                continue;
            }
            if (main_menu_choice == '0') {
                break;
            }
            if (main_menu_choice == '1') {
                Battle b1, b2;
                SetBattle(&p1, &b1);
                SetBattle(&p2, &b2);
                RunBattle(&p1, &p2, &b1, &b2);
                continue;
            }
            if (main_menu_choice == '4') {
                ifstream fout;
                fout.open("gamerule.txt");
                string line;
                while (getline(fout, line)) {
                    cout << line << endl;
                }
                fout.close();
                continue;
            }
            else {
                cout << "Invalid input!" << endl;
                
            }
        }
    }
    cout << "Quit 169 Battle. Bye Bye!" << endl;
}
