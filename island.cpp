//
//  island.cpp
//  IslandGame
//
//  Created by Alan Tony-Itoyah on 4/13/24.
//

#include "island.hpp"
#include "player.h"
#include "ship.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Island::Island(const string& name, const string& description, int amountOfTreasure, double chanceOfAttack, int fuelRequired) : name(name), description(description), amountOfTreasure(amountOfTreasure), chanceOfAttack(chanceOfAttack), fuelRequired(fuelRequired) {}

Island::~Island() {}


DesertIsland::DesertIsland() : Island("Desert Island", " A dry, waterless and hot domain... Look, you're already sweating.", 125, 0.4, 30){}
DesertIsland::~DesertIsland() {}


void DesertIsland::explore(Ship &ship){
    cout << "Exploring the desert island."  << description << endl;
    
    //generate random number
    double eventProbability = static_cast<double>(rand())/ RAND_MAX;
    
    if(eventProbability < chanceOfAttack){
        cout << "As you further explore the desert.. danger awaits." << endl;
        
        if(rand() % 2){
            cout << "Extreme heat leads to exhaustion and dehydration." << endl;
            ship.getPlayer() -> receiveDamage(20);
            cout << "You take 20 damage!" << endl;

        }
        if(rand() % 2){
            cout << "Quicksand steals your supplies!" << endl;
            ship.getPlayer() -> decreaseMoney(70);
            cout << "Player lost 70 coins!" << endl;
        }
    } else{
        cout << "You were lucky... this time. The desert has been navigated without any incendents." << endl;
    }
    
    ship.getPlayer() -> increaseMoney(amountOfTreasure);
    cout << "Hidden in the sand, you find a chest containing 125 gold." << endl;
    cout << "Desert Island was fully explored... continue your journey." << endl;
}


ForestIsland::ForestIsland() : Island("Forest Island", " Dense forest and bushes, wild animals living within.. let's not make them angry...", 150, 0.4, 35){}
ForestIsland::~ForestIsland() {}


void ForestIsland::explore(Ship &ship){
    cout << "Exploring the Forest island." << description << endl;
    
    //generate random number
    double eventProbability = static_cast<double>(rand())/ RAND_MAX;
    
    if(eventProbability < chanceOfAttack){
        cout << "As you further explore the desert.. danger awaits." << endl;
        
        if(rand() % 2){
            cout << "The crew encounters hostile Gorillas!" << endl;
            ship.receiveDamage(40);
            ship.getPlayer() -> receiveDamage(40);
            cout << "All members of the crew take 40 damage before escaping!" << endl;
        }
        if(rand() % 2){
            cout << "Oh no, is that a bear?" << endl;
            ship.getPlayer() -> decreaseMoney(70);
            cout << "While running, 70 gold is lost!" << endl;
        }
    }else{
        cout << "You were lucky... this time. The forest has been navigated without any incendents." << endl;
    }
    
    ship.getPlayer() -> increaseMoney(amountOfTreasure);
    cout << "Hidden in the sand, you find a chest containing 150 gold." << endl;
    cout << "Forest Island was fully explored... continue your journey." << endl;
}

//Initialization
SwampIsland::SwampIsland() : Island("Swamp Island", " Muddy lands and the wild life here seem angry... ", 175, 0.4, 40){}
SwampIsland::~SwampIsland() {}


void SwampIsland::explore(Ship &ship){
    cout << "Exploring the swamp island." << description << endl;
    
    //generate random number
    double eventProbability = static_cast<double>(rand())/ RAND_MAX;
    
    if(eventProbability < chanceOfAttack){
        cout << "As you go deeper through the swamp.. danger awaits." << endl;
        
        if(rand() % 2){
            cout << "Swampy mud sucks some of the players supplies!" << endl;
            ship.getPlayer() -> decreaseMoney(65);
            cout << "65 coins lost!" << endl;
        }
        if(rand() % 2){
            cout << "Oh no! Hostile beetles swarm the group!" << endl;
            ship.getPlayer() -> receiveDamage(40);
            cout << "You take 40 damage before they're killed!" << endl;
        }
    } else{
        cout << "You were lucky... this time. The swamp has been navigated without any incendents." << endl;
    }
    
    ship.getPlayer() -> increaseMoney(amountOfTreasure);
    cout << "Among the mud, you find a chest containing 175 gold." << endl;
    cout << "Swamp Island was fully explored... continue your journey." << endl;
}



SnowTundraIsland::SnowTundraIsland() : Island("Snow Tundra Island", " Biting cold that's hard for any explorer to navigate... however there seems to be more treasure here than on most...!", 200, 0.4, 45){}
SnowTundraIsland::~SnowTundraIsland() {}


void SnowTundraIsland::explore(Ship &ship){
    cout << "Exploring the Snowy Tundra island." << description << endl;
    
    double eventProbability = static_cast<double>(rand())/ RAND_MAX;
    
    if(eventProbability < chanceOfAttack){
        cout << "As you go deeper through the snow.. danger awaits." << endl;
        
        if(rand() % 2){
            cout << "The extreme cold leads to frostbite." << endl;
            ship.getPlayer() -> receiveDamage(35);
            cout << "Player took 35 damage." << endl;
        }
        if(rand() % 2){
            cout << "A heavy bag of supplies falls through ice and is lost forever!" << endl;
            ship.getPlayer() -> decreaseMoney(40);
            cout << "40 gold is lost!" << endl;
        }if(rand() % 2){
            cout << "The ship is damaged by a blizzard!" << endl;
            ship.receiveDamage(60);
            cout << "60 damage dealt to ship!" << endl;
        }
    }else{
        cout << "You were lucky... this time. The snow tundra has been navigated without any incendents." << endl;
    }
    
    ship.getPlayer() -> increaseMoney(amountOfTreasure);
    cout << "Among the mud, you find a chest containing 200 gold." << endl;
    cout << "Snow Tundra was fully explored... continue your journey." << endl;
}





NetherIsland::NetherIsland() : Island("Nether Island", " A mysterious, ancient Island. The dangerous are plenty but so are the rewards... Beware of the wither", 1000, 0.6, 65){}
NetherIsland::~NetherIsland() {}


void NetherIsland::explore(Ship &ship){
    cout << "Exploring the Nether island." << description << endl;
    
    double eventProbability = static_cast<double>(rand())/ RAND_MAX;
    
    if(eventProbability < chanceOfAttack){
        if(rand() % 2){
            cout << "A blaze throws fireballs!" << endl;
            ship.getPlayer() -> receiveDamage(60);
            cout << "Player took 60 damage!" << endl;
        }
    } else if (eventProbability < 0.4){
        cout << "A wither appears and curses you, stealing your fate." << endl;
        ship.getPlayer() -> endGame();
    }
    
    cout << "With the nether now fully explored... your journey is complete." << endl;
    
    ship.getPlayer() -> increaseMoney(amountOfTreasure);
    cout << "You find the most ancient of treasures. All who came before you have failed and been forgotten by histroy..." << endl;
    cout << "Player earns 1000 gold!" << endl;
    cout << "You Win!" << endl;

    
}
