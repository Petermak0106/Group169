//Account.cpp
#include <iostream>
#include "Account.h"

using namespace std;

struct Account {
    string name;
    int level;
    int exp;
    int money;
    bool own_dice2;
    bool own_dice3;
    int no_of_defender;
    int no_of_battery;
    int extra_gp;
};