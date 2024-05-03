//
//  island.hpp
//  IslandGame
//
//  Created by Alan Tony-Itoyah on 4/13/24.
//

#ifndef island_hpp
#define island_hpp

#include "ship.h"
#include <iostream>
using namespace std;

class Island{
public:
    Island(const string& name, const string& description, int amountOfTreasure, double chanceOfAttack, int fuelRequired);
    virtual ~Island();
    
    virtual void explore(Ship& ship) = 0;
    
protected:
    string name;
    string description;
    int amountOfTreasure;
    double chanceOfAttack;
    int fuelRequired;

};

//got from different minecraft domains lol
class DesertIsland : public Island{
public:
    DesertIsland();
    ~DesertIsland () override;
    void explore(Ship& ship) override;
};

class ForestIsland : public Island{
public:
    ForestIsland();
    ~ForestIsland () override;
    void explore(Ship& ship) override;
};

class SwampIsland : public Island{
public:
    SwampIsland();
    ~SwampIsland () override;
    void explore(Ship& ship) override;
};

class SnowTundraIsland : public Island{
public:
    SnowTundraIsland();
    ~SnowTundraIsland () override;
    void explore(Ship& ship) override;
};

class NetherIsland : public Island{
public:
    NetherIsland();
    ~NetherIsland () override;
    void explore(Ship& ship) override;
};



#endif /* island_hpp */
