//
//  gameManager.h
//  IslandGame
//
//  Created by Alan Tony-Itoyah on 4/8/24.
//

#ifndef GameManager_h
#define GameManager_h

#include "player.h"
#include "ship.h"
#include <cstdlib>



//Class for game management
class GameManager{
public:
    //default constructor
    GameManager(Player* player);
    //destructor
    ~GameManager();
        
    void saveGame(Player& player);
    void loadGame(Player& player);
    
    void upgradeShip(int type);
    
    void triggerRandomEvent();
    
    Ship* getCurrentShip() const;
    void printCurrentShipInfo() const;
    
private:
    Player* player;
    Ship* currentShip;
};
#endif /* gameManager_h */
