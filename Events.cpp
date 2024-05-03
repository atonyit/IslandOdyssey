//
//  Events.cpp
//  IslandGame
//
//  Created by Alan Tony-Itoyah on 4/13/24.
//

#include "Events.hpp"
#include "ship.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void StormWeather::execute(Ship &ship){
    double eventChance = static_cast<double>(rand()) / RAND_MAX;
    
    if(eventChance < _STORM){ //used to determine likelyhood of event occuring
        cout << "There seems to be a sudden change in weather... " << endl;
        cout << "Strong winds and waves attack the ship, affecting the time it takes to reach the island!" << endl;
        ship.setShipFuel(ship.getShipFuel() - 30);
        cout << "Fuel is reduced by 30! " << endl;
        ship.receiveDamage(45);
        cout << "Ship takes 45 damage!" << endl;
        
        ship.checkShipEndGame();
    }
}


void FogWeather::execute(Ship &ship){ //used to determine likelyhood of event occuring
    double eventChance = static_cast<double>(rand()) / RAND_MAX;
    
    if(eventChance < _FOG){
        cout << "A thick fog that none can see through appears... " << endl;
        cout << "You get lost, multiplying the fuel used to get to your destination. " << endl;
        ship.setShipFuel(ship.getShipFuel() - 15);
        cout << "Fuel is reduced by 15! " << endl;
        
        ship.checkShipEndGame();
    }
}



void Maelstrom::execute(Ship &ship){
    double eventChance = static_cast<double>(rand()) / RAND_MAX;
    
    if(eventChance < _MAELSTROM){ //used to determine likelyhood of maelstrom (ocean whirlpool) occuring
        cout << "Does anyone know why we're moving towards that whirlpool... " << endl;
        cout << "WAIT.. A MAELSTROM! " << endl;
        ship.receiveDamage(100); //Ship takes damage from whirlpool
        ship.getPlayer() -> receiveDamage(70); //Player takes damage from whirlpool
        
        cout << "The ship took 100 damage and the player took 70 damage! " << endl;
        //if the Maelstrom's damage kills the player or breaks the ship, game over message displayed
        if(ship.getShipHealth() <= 0){
            cout << "The ship couldn't escape the Maelstrom. You and your crew sank with the ship!" << endl;
            ship.getPlayer() -> endGame();
        }
        if((ship.getPlayer() -> getHealth()) <= 0){
            cout << "The Maelstrom killed the player! " << endl;
            ship.getPlayer() -> endGame();
        }
    }
}



void PirateAttack::execute(Ship &ship){
    double eventChance = static_cast<double>(rand()) / RAND_MAX;
    
    if(eventChance < PIRATE_ATTACK){ //used to determine likelyhood of pirate attack occuring
        cout << "Oh no! Are those pirates?! " << endl;
        ship.receiveDamage(50); //Ship takes damage from pirate attack
        ship.getPlayer() -> decreaseMoney(50); //Player loses money from pirate attack
        cout << "The pirates attack the ship and rob you! " << endl;
    }
    
    if(ship.getShipHealth() <= 0){
        cout << "We can't go on after that attack Captin!" << endl;
        ship.getPlayer() -> endGame();
    }
}


void Treasure::execute(Ship &ship){
    double eventChance = static_cast<double>(rand()) / RAND_MAX;
    
    if(eventChance < _TREASURE){ //used to determine likelyhood of treasure found occuring
        cout << "Treasure discovered afloat! " << endl;
        ship.getPlayer() -> increaseMoney(100); //100 gold coins found and added to players inventory
        cout << "Gold increased by 100! " << endl;
    }
}


void Kraken::execute(Ship &ship){
    double eventChance = static_cast<double>(rand()) / RAND_MAX;
    
    if(eventChance < _KRAKEN){ //used to determine likelyhood of kraken event occuring
    cout << "Legends say there is a monster of enormous size somewhere in these waters... WAIT, it's right there! " << endl;
    //100 damage taken to the ship and player
    ship.receiveDamage(100);
    ship.getPlayer() -> receiveDamage(70);
        
    //if the kraken's damage kills the player or breaks the ship, game over message displayed
    cout << "The ship took 100 damage and the player took 70 damage! " << endl;
        if(ship.getShipHealth() <= 0){
            cout << "The ship couldn't escape the Kraken's attacks! You and your crew sank with the ship!" << endl;
            ship.getPlayer() -> endGame();
        }
        if((ship.getPlayer() -> getHealth()) <= 0){
            cout << "The Kraken killed the player! " << endl;
            ship.getPlayer() -> endGame();
        }
    }
}
