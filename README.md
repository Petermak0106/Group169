# Group169_project
## Title: 169 Battle
### Group members: 
- Mak Tsz Shing (3035685914)
- Yeung Cheuk To Benedict (3035694692)

## Introduction
This is a battle game of a fight between two players. Players have to defend their bases not to be attacked, while at the same time they have to attack others' base. A player loses when all of his or her bases are destroyed. The last player who survived wins the game.

### We contain account_record.txt, gamerule.txt, shop.txt and temp.txt

## Gameflow
### 1. Account
  - Every player owns an account. Players should login their accounts one by one. A player can accumulate exp. when he or she wins a battle. When a player reaches certain exp. , he or she will upgrade their level and gets money. Money are stored to the player's account which can be used to buy extra gadgets in the shop.

### 2. Battle
  - Each player will be initiated with 3 bases and 1 defender. The initial game points are set to 0 if the player do not use any extra gadget. Players can choose to throw a dice to obtain game points or to build weapons using their game points.
  - If a player choose to throw a dice, the player can choose which dice they want to throw. The point of dice is equal to the game points obtained by the player in the current round. Different dices with different combinations of points can be purchased in the shop.
  - If a player choose to use their game points, they can choose the following weapons.
  
    #### 1. Defender
      - A protective cover to all bases.
    #### 2. Battery
      - An attackive tool to destroy other's weapons or bases. Bases can be attacked only if there are no defender in the enemie side.
    #### 3. Air fighter
      - An attacktive tool to destroy other's bases directly without the defence of the defender.
    #### 4. Protective cover
      - A protective cover to protect one of the bases. It can endure harder attacks.
  
  - When a player loses all 3 bases, the player loses the game. The remaining player will continue the game until only 1 player suvived. The last surviver wins the game and gets money.

### 3. Shop
  - The shop consists of different items to be used in battles, which these products can be bought by money. The products include:
    ##### 1. Dices
      - Default Dice: (combination: 1,2,3,4,5,6) (default)
      - Dice Pro: (combination: 1,1,1,1,5,10)
      - Dice Pro Max: (combination: 3,3,3,4,4,4)
    ##### 2. Pre-built Defender
      - Add extra defenders at the begining of the battle
    ##### 3. Pre-built Battery
      - Add extra battery at the begining of the battle
    ##### 4. Extra game points
      - Add extra defenders at the begining of the battle

## Functions included
#### 1. add_account
  - add accounts to the account list if a player is newly registered 
 #### 2. CheckItems
  - show items owned each players 
 #### 3. grow_account_list
  -we use dynamic array to store account informations. It grows the size of the dynamic array. Return a enlarged array with account informations 
 #### 4. load_account
  -we load account informations from a textfile into a dynamic array during runtime. Returns the number of accounts loaded
 ### 5. login_menu
  -Returns player's login option
 #### 6. purchase
  -allow players to purchase items. Return player's money and purchased items
 #### 7. RunBattle
  -For players to join battle. Returns winner's exp and money
 #### 8. search_account
  -search player's account information from the loaded dynamic list
 #### 9. SetBattlet
  - load player's pre-built items used before entering a battle
 #### 10. shop.cpp
  -introduction of shop items. Players can be directed to purchase function here
 #### 11. update.cpp
  -update player's account information after purchase and battle

### Data Structures
We use a text file to store all player's account information. When the programme begins, the dynamic array in the programme will load all account informations from the textfile. 

### Dynamic memory arrangement
We will use dynamic array to store all player's information. We also use pointers to represent accounts in functions.

### File Input/Output
We input and output files containing account information. Also, we use file output to show long texts, like shop list introduction and gamerule.

