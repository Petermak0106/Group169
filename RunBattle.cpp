//RunBattle.cpp
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include "RunBattle.h"
#include "Account.h"
#include "Battle.h"
using namespace std;

void RunBattle (Account *p1, Account *p2, Battle *b1, Battle *b2) {
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