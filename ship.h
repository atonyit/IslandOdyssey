//
//  ship.h
//  IslandGame
//
//  Created by Alan Tony-Itoyah on 4/8/24.
//

#ifndef ship_h
#define ship_h

#include "player.h"

class Ship{
public:
    Ship(int maxCrewSize, int shipHealth, int shipFuel, int speed, Player* player);
    virtual ~Ship() {}
    
    
    virtual int getShipType() const = 0;
    static Ship* createShip(int type, Player* player);
    
    
    int getMaxCrewSize() const;
    int getCurrentCrewSize() const;
    int getShipHealth() const;
    int getShipFuel() const;
    int getSpeed() const;
    
    
    Player* getPlayer() const;
    
    
    void setCurrentCrewSize(int size);
    void setShipHealth(int health);
    void setShipFuel(int fuel);
    void setSpeed(int fast);
    
    
    void receiveDamage(int damage);
    void checkShipEndGame();
    
    // Travel method for the ship
    virtual void travel() = 0;
    // Special ability for the ship
    virtual void specialAbility() = 0;
    
    //To upgrade /print ship information
    void printShipInfo() const;
    
protected:
    int maxCrewSize;
    int currentCrewSize;
    int shipHealth;
    int shipFuel;
    int speed;
    Player* player;
};



//Derived ships from main class
class BaseShip : public Ship {
public:
    BaseShip(Player* player) : Ship(15, 100, 100, 2, player) {}
    int getShipType() const override {return 0;}
    void travel() override;
    void specialAbility() override;
};


class ScoutShip : public Ship {
public:
    ScoutShip(Player* player) : Ship(35, 200, 200, 3, player) {}
    int getShipType() const override {return 1;}
    void travel() override;
    void specialAbility() override;

};


class GalleonShip : public Ship{
public:
    GalleonShip(Player* player) : Ship(100, 250, 250, 2, player) {}
    int getShipType() const override {return 2;}
    void travel() override;
    void specialAbility() override;
};


class SubmarineShip : public Ship {
public:
    SubmarineShip(Player* player) : Ship(15, 300, 390, 7, player) {}
    int getShipType() const override {return 3;}
    void travel() override;
    void specialAbility() override;
};



#endif /* ship_h */
