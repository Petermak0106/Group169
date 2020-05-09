//update.cpp
#include <iostream>
#include <fstream>
#include <strings>
#include "update.h"
#include "Account.h"
using namespace std;

void update (Account *player) {
    while (player->exp >= player->level * player->level) {
        player->exp -= player->level * player->level;
        cout << "Congratulations, " << player->name << ". Your are upgraded from " << player->level << " to " << player->level+1 << "!" << endl;
        player->level++;
        player->money += 500;
    }
    ifstream fin;
    fin.open("account_record.txt");
    ofstream fout;
    fout.open("temp.txt");
    string line_account_record;
    while (getline(fin, line_account_record)) {
        if (line_account_record.find(player->name) != string::npos) {
            continue;
        }
        else {
            fout << line_account_record << endl;
        }
    }
    fout << player->name << " " << player->level << " " << player->exp << " " << player->money << " " << player->own_dice2 << " " << player->own_dice3 << " " << player->no_of_defender << " " << player->no_of_battery << " " << player->extra_gp << endl;
    fin.close();
    fout.close();

    fout.open("account_record.txt");
    fout.close();

    fout.open("account_record.txt");
    fin.open("temp.txt");
    string line_temp;
    while (getline(fin, line_temp)) {
        fout << line_temp << endl;
    }
    fout.close();
    fin.close();
    
    fout.open("temp.txt");
    fout.close();
}