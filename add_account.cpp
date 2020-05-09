//add_account.cpp
#include <iostream>
#include <string>
#include <fstream>
#include "add_account.h"
#include "Account.h"
using namespace std;

Account add_account (Account ac[], int num_records) {
    ifstream fin;
    fin.open("account_record.txt");
    ofstream fout;
    fout.open("account_record.txt", ios::app);
    Account player;
    string name, existed_name;
    cout << "Enter your name: ";
    cin >> name;
    while (1) {
        bool name_repeated = false;
        for (int i = 0; i < num_records; i++) {
            existed_name = ac[i].name;
            if (name == existed_name) {
                cout << "Account already existed!" << endl;
                name_repeated = true;
            }
        }
        if (name_repeated == false) {
            player.name = name;
            player.level = 1;
            player.exp = 0;
            player.money = 1000;
            player.own_dice2 = false;
            player.own_dice3 = false;
            player.no_of_defender = 0;
            player.no_of_battery = 0;
            player.extra_gp = 0;
            fout << player.name << " " << player.level << " " << player.exp << " " << player.money << " " << player.own_dice2 << " " << player.own_dice3 << " " << player.no_of_defender << " " << player.no_of_battery << " " << player.extra_gp << endl;
            fin.close();
            fout.close();
            break;
        }
        if (name_repeated == true) {
            cout << "Enter your name: ";
            cin >> name;
            cout << endl;
        }
    }
    return player;
}
