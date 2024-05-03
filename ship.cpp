//
//  ship.cpp
//  IslandGame
//
//  Created by Alan Tony-Itoyah on 4/8/24.
//

#include "ship.h"
#include "player.h"
#include <iostream>

using namespace std;

Ship::Ship(int maxCrewSize, int shipHealth, int shipFuel, int speed, Player* player) : maxCrewSize(maxCrewSize), currentCrewSize(maxCrewSize), shipHealth(shipHealth), shipFuel(shipFuel), speed(speed), player(player) {}

//get
int Ship::getMaxCrewSize() const{
    return maxCrewSize;
}
int Ship::getCurrentCrewSize() const{
    return currentCrewSize;
}
int Ship::getShipHealth() const{
    return shipHealth;
}
int Ship::getShipFuel() const{
    return shipFuel;
}
int Ship::getSpeed() const{
    return speed;
}

//getPlayer with pointer
Player* Ship::getPlayer() const {
    return player;
}

//set
void Ship::setCurrentCrewSize(int size){
    currentCrewSize = size;
}
void Ship::setShipHealth(int health){
    shipHealth = health;
}
void Ship::setShipFuel(int fuel){
    shipFuel = fuel;
}
void Ship::setSpeed(int fast){
    speed = fast;
}

Ship* Ship::createShip(int type, Player* player){
    if(type == 0){
        return new BaseShip(player);
    } else if(type == 1){
        return new ScoutShip(player);
    }else if(type == 2){
        return new GalleonShip(player);
    }else if(type == 3){
        return new SubmarineShip(player);
    }else{
        cout << "Invalid ship selected" << endl;
        return nullptr;
    }
}

//for random events damaging ship
void Ship::receiveDamage(int damage){
    shipHealth -= damage;
    if(shipHealth <= 0){
        cout << "The ship has been destroyed!" << endl;
        player->endGame();
    }
}

void Ship::checkShipEndGame(){
    if(shipFuel <= 0){
        cout << "Ship cannot go on! Ship is lost at sea!" << endl;
        player->endGame();
    }
    if(shipHealth <= 0){
        cout << "The ship is too damaged! It can't go on!" << endl;
        player->endGame();
    }
}

//Prints the current ship info
void Ship::printShipInfo() const{
    cout << "Max Crew: " << getMaxCrewSize() << endl;
    cout << "Crew Size: " << getCurrentCrewSize() << endl;
    cout << "Health: " << getShipHealth() << endl;
    cout << "Fuel: " << getShipFuel() << endl;
    cout << "Speed: " << getSpeed() << endl;
}

//Base Ship
void BaseShip::travel(){
    //Check the fuel before trying to travel
    if(getShipFuel() < 10) {
        cout << "Not enough fuel for travel!" << endl;
        checkShipEndGame();
        return;
    }
    else{
        setShipFuel(getShipFuel() - 20);
        cout << "Scot Ship is sailing. Fuel remaining: " << getShipFuel() << endl;
    }
}

void BaseShip::specialAbility(){
        cout << "Base Ship has no special ability." << endl;
    }



//Scout Ship
void ScoutShip::travel(){
    //Check the fuel before trying to travel
    if(getShipFuel() < 20) {
        cout << "Not enough fuel for travel!" << endl;
        checkShipEndGame();
        return;
    }
    else{
        setShipFuel(getShipFuel() - 20);
        cout << "Scot Ship is sailing. Fuel remaining: " << getShipFuel() << endl;
    }
}

void ScoutShip::specialAbility(){
    if(getShipFuel() < 20){
        cout << "Not enough fuel for special ability!" << endl;
        return;
    }
    else{
        setShipFuel(getShipFuel() - 25);
        player -> setMoney(50);
        cout << "Scout Ship special ability activated! Increasing treasure odds through scouting." << endl;
    }
}

//Submarine Ship
void SubmarineShip::travel(){
    //Check the fuel before trying to travel
    if(getShipFuel() < 30) {
        cout << "Not enough fuel for travel!" << endl;
        checkShipEndGame();
        return;
    }
    else{
        setShipFuel(getShipFuel() - 30);
        cout << "Submarine is traveling. Fuel remaining: " << getShipFuel() << endl;
    }
}

void SubmarineShip::specialAbility(){
    if(getShipFuel() < 20){
        cout << "Not enough fuel for special ability!" << endl;
        return;
    }
        else {
            setShipFuel(getShipFuel() - 30);
            setShipHealth(getShipHealth() + 50); // Health Increase
            cout << "Submarine special ability activated! Ship health reserves increased! " << endl;
            
    }
}

//Galleon Ship
void GalleonShip::travel(){
    //Check the fuel before trying to travel
    if(getShipFuel() < 40) {
        cout << "Not enough fuel for travel!" << endl;
        checkShipEndGame();
        return;
    }
    else{
        setShipFuel(getShipFuel() - 40);
        cout << "Galleon Ship is sailing. Fuel remaining: " << getShipFuel() << endl;
    }
}


void GalleonShip::specialAbility(){
    if(getShipFuel() < 20){
        cout << "Not enough fuel for special ability!" << endl;
        return;
    }
    else{
      setShipFuel(getShipFuel() - 50);
      setShipHealth(getShipHealth() + 30); // Health Increase
      player -> setHealth(30);
      cout << "Galleon Ship special ability activated! 30 Health is returned to the crew!" << endl;
  }
}
