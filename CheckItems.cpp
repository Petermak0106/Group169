//CheckItems.cpp
#include <iostream>
#include "CheckItems.h"
#include "Account.h"
using namespace std;

void CheckItems (Account *p1, Account *p2) {
    cout << "----------------------" << endl;
    cout << p1->name << endl;
    if (p1->own_dice2 == true) {
        cout << "Dice Pro (Dice combination: 0,1,1,1,5,10): 1" << endl;
    }
    if (p1->own_dice3 == true) {
        cout << "Dice Pro Max (Dice Combination: 3,4): 1" << endl;
    }
    cout << "Number of pre-built defender: " << p1->no_of_defender << endl;
    cout << "Number of pre-built battery: " << p1->no_of_battery << endl;
    cout << "Number of extra game points: " << p1->extra_gp << endl;
    cout << "----------------------" << endl;

    cout << p2->name << endl;
    if (p2->own_dice2 == true) {
        cout << "Dice Pro (Dice combination: 0,1,1,1,5,10): 1" << endl;
    }
    if (p2->own_dice3 == true) {
        cout << "Dice Pro Max (Dice Combination: 3,4): 1" << endl;
    }
    cout << "Number of pre-built defender: " << p2->no_of_defender << endl;
    cout << "Number of pre-built battery: " << p2->no_of_battery << endl;
    cout << "Number of extra game points: " << p2->extra_gp << endl;
    cout << "----------------------" << endl;
}