//search_account.cpp
#include <iostream>
#include <string>
#include <sstream>
#include "search_account.h"
#include "Account.h"

using namespace std;

Account search_account(Account ac[], int num_records) {
    Account player;
    string username;
    cout << "Please enter username: ";
    cin >> username;

    while (1) {
        bool account_existed = false;
        for (int i = 0; i < num_records; i++) {
            string name = ac[i].name;

            if (name.find(username) != string::npos){
                account_existed = true;
                player.name = ac[i].name;
                player.level = ac[i].level;
                player.exp = ac[i].exp;
                player.money = ac[i].money;
                player.own_dice2 = ac[i].own_dice2;
                player.own_dice3 = ac[i].own_dice3;
                player.no_of_defender = ac[i].no_of_defender;
                player.no_of_battery = ac[i].no_of_battery;
                player.extra_gp = ac[i].extra_gp;
                return player;
                break;
            }
        }

        if (account_existed == false) {
            char choice = login_menu();
            if (choice == '1') {
                player = add_account(ac, num_records);
                break;
            }
            else if (choice == '2') {
                player = search_account(ac, num_records);
                break;
            }
            else {
                cout << "Invalid input!" << endl;
            }
        }
    }
    return player;
}