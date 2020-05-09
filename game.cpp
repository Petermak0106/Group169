#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

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

struct Battle {
    int no_of_base;
    int no_of_defender;
    int no_of_battery;
    int gamepoints;
    int no_of_airfighter;
    int no_of_protective_cover;
    int hp_protective_cover;
    
};

void grow_account_list (Account * &ac, int &ac_list_size) {
    Account * ac_new = new Account[ac_list_size*2];

    for (int ac_list_index = 0; ac_list_index < ac_list_size; ac_list_index++) {
        ac_new[ac_list_index] = ac[ac_list_index];
    }

    delete [] ac;
    ac = ac_new;
    ac_list_size *= 2;
}

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

void print_account (Account ac[], int num_records) {
    for (int i = 0; i < num_records; i++) {
        cout << "Name: " << ac[i].name << endl;
        cout << "Level: " << ac[i].level << endl;
        cout << "Exp: " << ac[i].exp << endl;
        cout << "Money: " << ac[i].money << endl;
        cout << "Own dice 2? " << ac[i].own_dice2 << endl;
        cout << "Own dice 3? " << ac[i].own_dice3 << endl;
        cout << "No. of defender: " << ac[i].no_of_defender << endl;
        cout << "No. of battery: " << ac[i].no_of_battery << endl;
        cout << "Extra game points: " << ac[i].extra_gp << endl;
        cout << endl;
    }
}

char login_menu() {
    char login_choice;

    cout << "1. Register a new account." << endl;
    cout << "2. Login as existing account." << endl;
    cout << "0. Quit game. " << endl;
    cout << "Please enter your choice: ";

    //read user selection
    cin >> login_choice;
    return login_choice;
}

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

void shop (Account *p1, Account *p2) {
    char shop_choice;
    ifstream fin;
    fin.open("shop.txt");
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();
    cout << "Enter your choice: ";
    cin >> shop_choice;
    cout << endl;
    while (shop_choice != '0') {
        if (shop_choice == '1') {
            cout << "Which player wants to purchase? Enter your username. (" << p1->name << "/ " << p2->name << "): ";
            string username;
            cin >> username;
            cout << endl;
            if (username == p1->name) {
                purchase(p1);
            }
            else if (username == p2->name) {
                purchase(p2);
            }
            else {
                cout << "Invalid input!" << endl;
            }
        }
        else {
            cout << "Invalid input!" << endl;
        }
        fin.open("shop.txt");
        line = "";
        while (getline(fin, line)) {
            cout << line << endl;
        }
        fin.close();
        cin >> shop_choice;
    }
    return;
}

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

void battle (Account *p1, Account *p2, Battle *b1, Battle *b2) {
    Account *winner;
    cout << "Battle start!" << endl;
    srand (time(NULL));
    bool end_game = false;
    char action;
    int dice1[] = {1,2,3,4,5,6};
    int dice2[] = {0,1,5,10,1,1};
    int dice3[] = {3,3,3,4,4,4};
    bool turn_done = false;
    while (end_game == false) {
        while (turn_done == false && end_game == false) {
            cout << "----------------------" << endl;
            cout << p1->name << endl;
            cout << "No. of bases: " << b1->no_of_base << endl;
            cout << "No. of defenders: " << b1->no_of_defender << endl;
            cout << "No. of protective cover: " << b1->no_of_protective_cover << ", Total HP: " << b1->hp_protective_cover << endl;
            cout << "No. of batteries: " << b1->no_of_battery << endl;
            cout << "No. of air figheter: " << b1->no_of_airfighter << endl;
            cout << "No. of gamepoints: " << b1->gamepoints << endl;
            cout << "-----" << endl;
            cout << p2->name << endl;
            cout << "No. of bases: " << b2->no_of_base << endl;
            cout << "No. of defenders: " << b2->no_of_defender << endl;
            cout << "No. of protective cover: " << b2->no_of_protective_cover << ", Total HP: " << b2->hp_protective_cover << endl;
            cout << "No. of batteries: " << b2->no_of_battery << endl;
            cout << "No. of air figheter: " << b2->no_of_airfighter << endl;
            cout << "No. of gamepoints: " << b2->gamepoints << endl;
            cout << "----------------------" << endl;
            cout << "Action:" << endl;
            cout << "1. Roll a dice" << endl;
            cout << "2. Build a defender (HP:1, 2 gamepoints)" << endl;
            cout << "3. Build a batery / Attack (Attack:1, 5 gamepoints)" << endl;
            cout << "4. Launch an airfighter (Attack: 2, 20 gamepoints)" << endl;
            cout << "5. Build a protective cover (HP:2, 10 gamepoints)" << endl;
            cout << "0. Quit battle" << endl;
            cout << p1->name << ", Chose your action: ";
            cin >> action;
            cout << endl;
            while (action != '0') {
                switch (action) {
                    case '1':
                        char dice_choice;
                        cout << "1. Default Dice: {1,2,3,4,5,6}" << endl;
                        if (p1->own_dice2 == true) {
                            cout << "2. Dice Pro: {0,1,1,1,5,10}" << endl;
                        }
                        if (p1->own_dice3 == true) {
                            cout << "3. Dice Pro Max: {3,3,3,4,4,4}" << endl;
                        }
                        cout << "Choose the dice to roll: ";
                        cin >> dice_choice;
                        cout << endl;
                        if (dice_choice == '1') {
                            int dice_point = rand()%6;
                            b1->gamepoints += dice1[dice_point];
                            cout << "----------------------" << endl;
                            cout << "You got " << dice1[dice_point] << " gamepoints!" << endl;
                            turn_done = true;
                        }
                        else if (dice_choice == '2') {
                            if (p1->own_dice2 == false) {
                                cout << "You do not own Dice Pro!" << endl;
                            }
                            else {
                                int dice_point = rand()%6;
                                b1->gamepoints += dice2[dice_point];
                                cout << "----------------------" << endl;
                                cout << "You got " << dice2[dice_point] << " gamepoints!" << endl;
                                turn_done = true;
                            }
                        }
                        else if (dice_choice == '3') {
                            if (p1->own_dice3 == false) {
                                cout << "You do not own Dice Pro Max!" << endl;
                            }
                            else {
                                int dice_point = rand()%6;
                                b1->gamepoints += dice3[dice_point];
                                cout << "----------------------" << endl;
                                cout << "You got " << dice3[dice_point] << " gamepoints!" << endl;
                                turn_done = true;
                            }
                        }
                        break;
                        
                    case '2':
                        if (b1->gamepoints < 2) {
                            cout << "----------------------" << endl;
                            cout << b1->gamepoints << endl;
                            cout << "Not enough gamepoints!" << endl;
                        }
                        else {
                            b1->gamepoints -= 2;
                            b1->no_of_defender++;
                            cout << "----------------------" << endl;
                            cout << "You now have " << b1->no_of_defender << " defender." << endl;
                            turn_done = true;
                        }
                        break;
                        
                    case '3':
                        if (b1->gamepoints < 5) {
                            cout << "----------------------" << endl;
                            cout << b1->gamepoints << endl;
                            cout << "Not enough gamepoints!" << endl;
                        }
                        else {
                            b1->gamepoints -= 5;
                            if (b1->no_of_battery == 0) {
                                b1->no_of_battery++;
                                cout << "----------------------" << endl;
                                cout << "You have built a battery!" << endl;
                            }
                            else if (b2->no_of_defender >= 1) {
                                b2->no_of_defender--;
                                cout << "----------------------" << endl;
                                cout << "You have damaged " << p2->name << "'s defender!" << endl;
                            }
                            else if (b2->no_of_protective_cover >= 1) {
                                b2->hp_protective_cover--;
                                if (b2->hp_protective_cover % 2 == 0) {
                                    b2->no_of_protective_cover--;
                                    cout << "----------------------" << endl;
                                    cout << "You have destroyed " << p2->name << "'s protective cover!" << endl;
                                }
                                else {
                                    cout << "----------------------" << endl;
                                    cout << "You have damaged " << p2->name << "'s protective cover by 1 HP!" << endl;
                                }
                            }
                            else {
                                b2->no_of_base--;
                                if (b2->no_of_base == 0) {
                                    cout << "----------------------" << endl;
                                    cout << "All bases of " << p2->name << " are destroyed! " << p1->name << " has won the battle!" << endl;
                                    turn_done = true;
                                    end_game = true;
                                    winner = p1;
                                }
                                else {
                                    cout << "----------------------" << endl;
                                    cout << "You have destroyed one of " << p2->name << "'s base!" << endl;
                                }
                            }
                            turn_done = true;
                        }
                        break;
                        
                    case '4':
                        if (b1->gamepoints <= 20) {
                            cout << "----------------------" << endl;
                            cout << b1->gamepoints << endl;
                            cout << "Not engout gamepoints!" << endl;
                        }
                        else {
                            b1->gamepoints -= 20;
                            if (b2->no_of_airfighter == 0) {
                                b2->no_of_airfighter++;
                                cout << "----------------------" << endl;
                                cout << "You have called an air fighter." << endl;
                            }
                            else if (b2->no_of_protective_cover >= 1) {
                                b2->no_of_protective_cover--;
                                b2->hp_protective_cover -= 2;
                                cout << "----------------------" << endl;
                                cout << "Your airfighter has destroyed " << p2->name << "'s protective cover!" << endl;
                            }
                            else {
                                b2->no_of_base--;
                                if (b2->no_of_base == 0) {
                                    cout << "----------------------" << endl;
                                    cout << "All bases of " << p2->name << " are destroyed! " << p1->name << " has won the battle!" << endl;
                                    turn_done = true;
                                    end_game = true;
                                    winner = p1;
                                    break;
                                }
                                else {
                                    cout << "----------------------" << endl;
                                    cout << "You have destroyed one of " << p2->name << "'s base!" << endl;
                                }
                            }
                            turn_done = true;
                        }
                        break;
                    
                    case '5':
                        if (b1->gamepoints < 10) {
                            cout << "----------------------" << endl;
                            cout << "Not enough gamepoints!" << endl;
                            break;
                        }
                        else {
                            b1->gamepoints -= 10;
                            b1->no_of_protective_cover++;
                            b1->hp_protective_cover += 2;
                            cout << "----------------------" << endl;
                            cout << "You now have " << b1->no_of_protective_cover << " protective cover. Total HP: " << b1->hp_protective_cover << endl;
                            turn_done = true;
                        }
                        break;

                    default:
                        cout << "----------------------" << endl;
                        cout << "Invalid input!" << endl;
                        cout << "----------------------" << endl;
                    
                }
                if (turn_done == true)  {
                    break;
                }
                else if (turn_done == false) {
                    cout << p1->name << ", Chose your action: ";
                    cin >> action;
                    cout << endl;
                    break;
                }
            }
        }
        turn_done = false;
        while (turn_done == false && end_game == false) {
            cout << "----------------------" << endl;
            cout << p2->name << endl;
            cout << "No. of bases: " << b2->no_of_base << endl;
            cout << "No. of defenders: " << b2->no_of_defender << endl;
            cout << "No. of protective cover: " << b2->no_of_protective_cover << ", Total HP: " << b2->hp_protective_cover << endl;
            cout << "No. of batteries: " << b2->no_of_battery << endl;
            cout << "No. of air figheter: " << b2->no_of_airfighter << endl;
            cout << "No. of gamepoints: " << b2->gamepoints << endl;
            cout << "-----" << endl;
            cout << p1->name << endl;
            cout << "No. of bases: " << b1->no_of_base << endl;
            cout << "No. of defenders: " << b1->no_of_defender << endl;
            cout << "No. of protective cover: " << b1->no_of_protective_cover << ", Total HP: " << b1->hp_protective_cover << endl;
            cout << "No. of batteries: " << b1->no_of_battery << endl;
            cout << "No. of air figheter: " << b1->no_of_airfighter << endl;
            cout << "No. of gamepoints: " << b1->gamepoints << endl;
            cout << "----------------------" << endl;
            cout << "Action:" << endl;
            cout << "1. Roll a dice" << endl;
            cout << "2. Build a defender (HP:1, 2 gamepoints)" << endl;
            cout << "3. Build a batery / Attack (Attack:1, 5 gamepoints)" << endl;
            cout << "4. Launch an airfighter (Attack: 2, 20 gamepoints)" << endl;
            cout << "5. Build a protective cover (HP:2, 10 gamepoints)" << endl;
            cout << "0. Quit battle" << endl;
            cout << p2->name << ", Chose your action: ";
            cin >> action;
            cout << endl;
            while (action != '0') {
                switch (action) {
                    case '1':
                        char dice_choice;
                        cout << "1. Default Dice: {1,2,3,4,5,6}" << endl;
                        if (p2->own_dice2 == true) {
                            cout << "2. Dice Pro: {0,1,1,1,5,10}" << endl;
                        }
                        if (p2->own_dice3 == true) {
                            cout << "3. Dice Pro Max: {3,3,3,4,4,4}" << endl;
                        }
                        cout << "Choose the dice to roll: ";
                        cin >> dice_choice;
                        cout << endl;
                        if (dice_choice == '1') {
                            int dice_point = rand()%6;
                            b2->gamepoints += dice1[dice_point];
                            cout << "----------------------" << endl;
                            cout << "You got " << dice1[dice_point] << " gamepoints!" << endl;
                            turn_done = true;
                        }
                        else if (dice_choice == '2') {
                            if (p2->own_dice2 == false) {
                                cout << "You do not own Dice Pro!" << endl;
                            }
                            else {
                                int dice_point = rand()%6;
                                b2->gamepoints += dice2[dice_point];
                                cout << "----------------------" << endl;
                                cout << "You got " << dice2[dice_point] << " gamepoints!" << endl;
                                turn_done = true;
                            }
                        }
                        else if (dice_choice == '3') {
                            if (p2->own_dice3 == false) {
                                cout << "You do not own Dice Pro Max!" << endl;
                            }
                            else {
                                int dice_point = rand()%6;
                                b2->gamepoints += dice3[dice_point];
                                cout << "----------------------" << endl;
                                cout << "You got " << dice3[dice_point] << " gamepoints!" << endl;
                                turn_done = true;
                            }
                        }
                        break;
                        
                    case '2':
                        if (b2->gamepoints < 2) {
                            cout << "----------------------" << endl;
                            cout << b1->gamepoints << endl;
                            cout << "Not enough gamepoints!" << endl;
                        }
                        else {
                            b2->gamepoints -= 2;
                            b2->no_of_defender++;
                            cout << "----------------------" << endl;
                            cout << "You now have " << b2->no_of_defender << " defender." << endl;
                            turn_done = true;
                        }
                        break;
                        
                    case '3':
                        if (b2->gamepoints < 5) {
                            cout << "----------------------" << endl;
                            cout << b2->gamepoints << endl;
                            cout << "Not enough gamepoints!" << endl;
                        }
                        else {
                            b2->gamepoints -= 5;
                            if (b2->no_of_battery == 0) {
                                b2->no_of_battery++;
                                cout << "----------------------" << endl;
                                cout << "You have built a battery!" << endl;
                            }
                            else if (b1->no_of_defender >= 1) {
                                b1->no_of_defender--;
                                cout << "----------------------" << endl;
                                cout << "You have damaged " << p1->name << "'s defender!" << endl;
                            }
                            else if (b1->no_of_protective_cover >= 1) {
                                b1->hp_protective_cover--;
                                if (b1->hp_protective_cover % 2 == 0) {
                                    b1->no_of_protective_cover--;
                                    cout << "----------------------" << endl;
                                    cout << "You have destroyed " << p1->name << "'s protective cover!" << endl;
                                }
                                else {
                                    cout << "----------------------" << endl;
                                    cout << "You have damaged " << p1->name << "'s protective cover by 1 HP!" << endl;
                                }
                            }
                            else {
                                b1->no_of_base--;
                                if (b2->no_of_base == 0) {
                                    cout << "----------------------" << endl;
                                    cout << "All bases of " << p1->name << " are destroyed! " << p2->name << " has won the battle!" << endl;
                                    turn_done = true;
                                    end_game = true;
                                    winner = p1;
                                }
                                else {
                                    cout << "----------------------" << endl;
                                    cout << "You have destroyed one of " << p1->name << "'s base!" << endl;
                                }
                            }
                            turn_done = true;
                        }
                        break;
                        
                    case '4':
                        if (b2->gamepoints <= 20) {
                            cout << "----------------------" << endl;
                            cout << b2->gamepoints << endl;
                            cout << "Not engout gamepoints!" << endl;
                        }
                        else {
                            b2->gamepoints -= 20;
                            if (b2->no_of_airfighter == 0) {
                                b2->no_of_airfighter++;
                                cout << "----------------------" << endl;
                                cout << "You have called an air fighter." << endl;
                            }
                            else if (b1->no_of_protective_cover >= 1) {
                                b1->no_of_protective_cover--;
                                b1->hp_protective_cover -= 2;
                                cout << "----------------------" << endl;
                                cout << "Your airfighter has destroyed " << p2->name << "'s protective cover!" << endl;
                            }
                            else {
                                b1->no_of_base--;
                                if (b1->no_of_base == 0) {
                                    cout << "----------------------" << endl;
                                    cout << "All bases of " << p1->name << " are destroyed! " << p2->name << " has won the battle!" << endl;
                                    end_game = true;
                                    turn_done = true;
                                    winner = p1;
                                    break;
                                }
                                else {
                                    cout << "----------------------" << endl;
                                    cout << "You have destroyed one of " << p1->name << "'s base!" << endl;
                                }
                            }
                            turn_done = true;
                        }
                        break;
                    
                    case '5':
                        if (b2->gamepoints < 10) {
                            cout << "----------------------" << endl;
                            cout << "Not enough gamepoints!" << endl;
                            break;
                        }
                        else {
                            b2->gamepoints -= 10;
                            b2->no_of_protective_cover++;
                            b2->hp_protective_cover += 2;
                            cout << "----------------------" << endl;
                            cout << "You now have " << b2->no_of_protective_cover << " protective cover. Total HP: " << b2->hp_protective_cover << endl;
                            turn_done = true;
                        }
                        break;

                    default:
                        cout << "----------------------" << endl;
                        cout << "Invalid input!" << endl;
                        cout << "----------------------" << endl;
                    
                }
                if (turn_done == true)  {
                    break;
                }
                else if (turn_done == false) {
                    cout << p2->name << ", Chose your action: ";
                    cin >> action;
                    cout << endl;
                    break;
                }
            }
            if (action == '0') {
                cout << "Quit battle." << endl;
                return;
            }
        }
        turn_done = false;
    }
    if (winner == p1) {
        p1->exp += 60;
        p1->money += 200;
    }
    else if (winner == p2) {
        p2->exp += 60;
        p2->money += 200;
    }
    return;
}

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
                battle(&p1, &p2, &b1, &b2);
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
