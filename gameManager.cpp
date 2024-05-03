//
//  gameManager.cpp
//  IslandGame
//
//  Created by Alan Tony-Itoyah on 4/8/24.
//
//  Implementation of GameManager class, responsible for managing the game state,
//  contains logic for managing game events based on randomized probabilities,
//  upgrading player ships, and saving/loading game progress. 

#include "gameManager.h"
#include "Events.hpp"
#include "player.h"
#include "ship.h"
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

GameManager::GameManager(Player* player) : player(player), currentShip(new BaseShip(player)){}
    
GameManager::~GameManager(){
    delete currentShip;
}

Ship* GameManager::getCurrentShip() const{
    return currentShip;
}

//Trigger random events
void GameManager::triggerRandomEvent(){
    double eventChance = (static_cast<double>(rand()) / RAND_MAX); //find random probability
    
    if(eventChance < _STORM){
        StormWeather().execute(*currentShip);
    }else if(eventChance < (_FOG + _STORM)){
        FogWeather().execute(*currentShip);
    }else if(eventChance < (PIRATE_ATTACK + _FOG + _STORM)){
        PirateAttack().execute(*currentShip);
    }else if(eventChance < (_TREASURE + PIRATE_ATTACK + _FOG + _STORM)){
        Treasure().execute(*currentShip);
    }else if(eventChance < (_KRAKEN + _TREASURE + PIRATE_ATTACK + _FOG + _STORM)){
        Kraken().execute(*currentShip);
    }else if(eventChance <= (_MAELSTROM + _KRAKEN + _TREASURE + PIRATE_ATTACK + _FOG + _STORM )){
        Maelstrom().execute(*currentShip);
    }else{
        cout << "Looks like it'll be a calm ride to our destination!" << endl;
    }
}


//Way to upgrade ships
void GameManager::upgradeShip(int type){
    int cost = 0;
    switch (type) {
        case 1:
            cost = 300;
            break;
            //Cost for ScoutShip
        case 2:
            cost = 500;
            break;
            // Cost for GalleonShip
        case 3:
            cost = 700;
            break;
            // Cost for SubmarineShip
        default:
            cout << "Unknown ship" << endl;
            return;
    }
    
    if (player->getMoney() >= cost) {
        delete currentShip; // Delete the old ship
        currentShip = Ship::createShip(type, player); //create new ship
        
        //if the ship is made successfully
        if(currentShip != nullptr){
            player->setMoney(player->getMoney() - cost);
            cout << "Ship upgraded successfully!" << endl;
        }
        else{
            cout << "Error: Upgrade failed" << endl;
        }
    }
    else{
        cout << "Not enough gold to upgrade. Need " << cost << " gold." << endl;
    }
}


void GameManager::printCurrentShipInfo() const {
    currentShip->printShipInfo();
}
    
// Save game function
void GameManager::saveGame(Player& player) {
    ofstream saveFile("savegame.txt");

    if (!saveFile.is_open()) {
        cout << "Error: unable to save file." << endl;
        return;
    }

    // Save player data
    saveFile << "Money: " << player.getMoney() << endl;
    saveFile << "Health: " << player.getHealth() << endl;

    // Save ship type as an integer
    saveFile << "ShipType: " << static_cast<int>(currentShip->getShipType()) << endl;

    saveFile.close();
    cout << "Progress saved!" << endl;
}

// Load game function
void GameManager::loadGame(Player& player) {
    ifstream saveFile("savegame.txt");

    if (!saveFile.is_open()) {
        cout << "Error: no saved game found, try again or start new game." << endl;
        return;
    }

    string line;
    int savedMoney, savedHealth;
    int savedShipType; // Store ship type as an integer

    while (getline(saveFile, line)) {
        stringstream ss(line);
        string key;
        int value;

        getline(ss, key, ':');
        ss >> value;

        if (key == "Money") 
            savedMoney = value;
        if (key == "Health") 
            savedHealth = value;
        if (key == "ShipType") 
            savedShipType = value;
    }

    // Apply loaded data, minus 100 since the player is initalized with a 100 to start
    player.setMoney(savedMoney - 100);
    player.setHealth(savedHealth - 100);

    // Ensure valid ship type and create new ship
    try {
//        type = static_cast<ShipType>(savedShipType);
        delete currentShip;
        currentShip = Ship::createShip(savedShipType, &player);
    } catch (...) {
        cout << "Error: Invalid ship type in save file." << endl;
        return;
    }

    saveFile.close();
    cout << "Saved progress loaded!" << endl;
}
