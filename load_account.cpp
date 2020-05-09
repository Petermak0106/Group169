//load_account.cpp
#include <iostream>
#include <string>
#include <fstream>
#include "load_account.h"
#include "Account.h"
using namespace std;

int load_account (Account * &ac, int &ac_list_size) {
    ifstream fin;
    fin.open("account_record.txt");
    int line_count = 0;
    string line;

    //extract an account from a line
    while (fin >> ac[line_count].name >> ac[line_count].level >> ac[line_count].exp >> ac[line_count].money >> ac[line_count].own_dice2 >> ac[line_count].own_dice3 >> ac[line_count].no_of_defender >> ac[line_count].no_of_battery >> ac[line_count].extra_gp) {
        if (line_count >= ac_list_size-1) {
            grow_account_list(ac, ac_list_size);
        }
        line_count++;
    }
    fin.close();
    return line_count;
}