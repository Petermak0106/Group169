//grow_account_list.cpp
#include <iostream>
#include "grow_account_list.h"
#include "Account.h"
using namespace std;

void grow_account_list (Account * &ac, int &ac_list_size) {
    Account * ac_new = new Account[ac_list_size*2];

    for (int ac_list_index = 0; ac_list_index < ac_list_size; ac_list_index++) {
        ac_new[ac_list_index] = ac[ac_list_index];
    }

    delete [] ac;
    ac = ac_new;
    ac_list_size *= 2;
    return;
}