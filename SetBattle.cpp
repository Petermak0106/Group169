//SetBattle.cpp
#include <iostream>
#include "SetBattle.h"
#include "Account.h"
#include "Battle.h"
using namespace std;

void SetBattle (Account *player, Battle *participant) {
    int amount;
    participant->no_of_base = 3;
    while (player->no_of_defender >= 1) {
        cout << player->name << ", how many pre-built defender do u want to use in battle? Amount(0-" << player->no_of_defender << "): " << endl;
        cin >> amount;
        if (amount <= player->no_of_defender) {
            participant->no_of_defender = amount;
            break;
        }
        else {
            cout << "Invalid input!" << endl;
        }
    }
    while (player->no_of_battery >= 1) {
        cout << player->name << ", how many pre-built battery do u want to use in battle? Amount:(0-" << player->no_of_battery << "): " << endl;
        cin >> amount;
        if (amount <= player->no_of_battery) {
            participant->no_of_battery = amount;
            break;
        }
        else {
            cout << "Invalid input!" << endl;
        }
    }
    while (player->extra_gp >= 1) {
        cout << player->name << ", how many extra gamepoints do u want to use in battle? Amount:(0-" << player->extra_gp << "): " << endl;
        cin >> amount;
        if (amount <= player->extra_gp) {
            participant->gamepoints = amount;
            break;
        }
        else {
            cout << "Invalid input!" << endl;
        }
    }
    participant->no_of_airfighter = 0;
    participant->no_of_protective_cover = 0;
    participant->hp_protective_cover = 0;
}
