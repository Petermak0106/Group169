# Group169_project
## Title: 169 Battle

## Introduction
This is a battle game of a fight between players. Players have to defend their bases not to be attacked, while at the same time they have to attack others' base. A player loses when all of his or her bases are destroyed. The last player who survived wins the game.

## Gameflow
1. Account
  - Every player owns an account. Players should first state the number of players (2-4) playing at the begining, and then login their accounts one by one. A player can accumulate exp. when he or she wins a battle. When a player reaches certain exp. , he or she will upgrade their level and gets money. Money are stored to the player's account which can be used to buy extra gadgets in the shop.

2. Battle
  - Each player will be initiated with 3 bases and 1 defender. The initial game points are set to 0 if the player do not use any extra gadget. Players can choose to throw a dice to obtain game points or to build weapons using their game points.
  - If a player choose to throw a dice, the player can choose which dice they want to throw. The point of dice is equal to the game points obtained by the player in the current round. Different dices with different combinations of points can be purchased in the shop.
  - If a player choose to use their game points, they can choose the following weapons.
  
    1. Defender. A protective cover to all bases.
    2. Battery. An attackive tool to destroy other's weapons or bases. Bases can be attacked only if there are no defender in the enemie side.
    3. Air fighter. An attacktive tool to destroy other's bases directly without the defence of the defender.
    4. Protective cover. A protective cover to protect one of the bases. It can endure harder attacks.
  
  - When a player loses all 3 bases, the player loses the game. The remaining player will continue the game until only 1 player suvived. The last surviver wins the game and gets money.

3. Shop
  - The shop consists of different items to be used in battles, which these products can be bought by money. The products include:
    1. Dices
    2. Pre-built Defender
    3. Pre-built Battery
    4. Extra game points

## Functions to be implemented
1. Loading players' account
  - Input the file containg players' game status.
2. Shop system
  - Read the money balance in player's account and items purchased. Return the money balance of a player after purchase.
3. Battle set up
  - Read the item used by players. Return the game set (number of defender and batteries).
4. Dice
  - Read the type of dice the player used. Return the dice points (a random point of the dice).
5. Battle
  - Read the attack command by the player. Return the action.
