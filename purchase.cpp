//purchase.cpp
#include <iostream>
#include "purchase.h"
#include "Account.h"
using namespace std;

void purchase (Account *player) {
    cout << "Hello! " << player->name << ". You have $" << player->money << ". What item do u want to buy? Enter 0 to quit." << endl;
    cout << "1. Dice Pro ($500/1)" << endl;
    cout << "2. Dice Pro Max ($500/1)" << endl;
    cout << "3. Pre-built defender ($200/1)" << endl;
    cout << "4. Pre-built battery ($200/1)" << endl;
    cout << "5. Extra gamepoints ($100/1)" << endl;
    cout << "0. Quit" << endl;
    cout << "Item: ";
    char item_choice;
    int amount;
    cin >> item_choice;
    switch (item_choice) {
        case '1':
            if (player->own_dice2 == 1) {
                cout << "You already own Dice Pro!" << endl;
            }
            else {
                if (player->money < 500) {
                    cout << "You have no enough money!" << endl;
                }
                else {
                    player->money -= 500;
                    player->own_dice2 = true;
                    cout << "You have bought Dice Pro successfully!" << endl;
                    cout << "Money left: " << player->money << endl;;
                }
            }
            cout << endl;
            break;

        case '2':
            if (player->own_dice3 == 1) {
                cout << "You already own Dice Pro Max!" << endl;
            }
            else {
                if (player->money < 500) {
                    cout << "You have no enough money!" << endl;
                }
                else {
                    player->money -= 500;
                    player->own_dice2 = true;
                    cout << "You have bought Dice Pro Max successfully!" << endl;
                    cout << "Money left: " << player->money << endl;
                }
            }
            cout << endl;
            break;

        case '3':
            cout << "How many pre-built defender you want to purchase? Amount: ";
            cin >> amount;
            if (player->money < amount * 200) {
                cout << "You have no enough money!" << endl;
            }
            else {
                player->money -= amount * 200;
                player->no_of_defender += amount;
                cout << "You now have " << player->no_of_defender << "Pre-built defender." << endl;
                cout << "Money left: " << player->money << endl;;
            }
            cout << endl;
            break;

        case '4':
            cout << "How many pre-built battery you want to purchase? Amount: ";
            cin >> amount;
            if (player->money < amount * 200) {
                cout << "You have no enough money!" << endl;
            }
            else {
                player->money -= amount * 200;
                player->no_of_battery += amount;
                cout << "You now have " << player->no_of_battery << "Pre-built battery." << endl;
                cout << "Money left: " << player->money << endl;;
            }
            cout << endl;
            break;

        case '5':
            cout << "How many extra gamepoints you want to purchase? Amount: ";
            cin >> amount;
            if (player->money < amount * 100) {
                cout << "You have no enough money!" << endl;
            }
            else {
                player->money -= amount * 100;
                player->extra_gp += amount;
                cout << "You now have " << player->extra_gp << "Extra gamepoints." << endl;
                cout << "Money left: " << player->money << endl;;
            }
            cout << endl;
            break;

        case '0':
            return;
        
        default:
            cout << "Invalid input!" << endl;
            cout << endl;
            break;
    }
    return;
}
