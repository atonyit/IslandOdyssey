//
//  player.cpp
//  IslandGame
//
//  Created by Alan Tony-Itoyah on 4/8/24.
//

#include "player.h"
#include <iostream>

using namespace std;


    Player::Player(int startingMoney, int startingDamage, int startingHealth)
        : money(startingMoney), damage(startingDamage), health(startingHealth) {}
    
//Implemented all the "get" member functions
    int Player::getMoney(){
        return money;
    }
    int Player::getHealth(){
        return health;
    }
 

//Implemented all the "set" member functions
    void Player::setMoney(int moneyAmount){
        money += moneyAmount;
    }
    void Player::setDamage(int damageAmount){
        damage += damageAmount;
    }
    void Player::setHealth(int healthAmount){
        health += healthAmount;
    }

//Implemented all the different player's game member function
    void Player::endGame(){
        cout << "Game over!" << endl;
        exit(0);
    }
    void Player::receiveDamage(int amount){
        health -= amount;
        if(health <= 0){
            cout << "Your injuries are fatal... only death awaits!" << endl;
            health = 0;
            endGame();
        }
    }
    void Player::increaseMoney(int amount){
        money+=amount;
    }
    void Player::decreaseMoney(int amount){
        money-=amount;

    }
    void Player::increaseDamage(int amount){
        damage+=amount;

    }


    //Implenetation of a display for the players information
    void Player::printPlayerInfo(){
        cout << "Money: " << getMoney() << endl;
        cout << "Health: " << getHealth() << endl;
    }
    
