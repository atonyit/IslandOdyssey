//
//  Events.hpp
//  IslandGame
//
//  Created by Alan Tony-Itoyah on 4/13/24.
//

#ifndef Events_hpp
#define Events_hpp

#include "ship.h"

//Percentage of each happening
const double _STORM = 0.19;
const double _FOG = 0.18;
const double PIRATE_ATTACK = 0.20;
const double _TREASURE = 0.20;
const double _KRAKEN = 0.11;
const double _MAELSTROM = 0.11;


class Events{
public:
    virtual void execute(Ship& ship) = 0;
};

//Classes dedicated to weather changes

//First one is a storm/heavy waves weather change
class StormWeather : public Events {
public:
    void execute(Ship& ship) override;
};
//Second one is a fog weather change

class FogWeather : public Events {
public:
    void execute(Ship& ship) override;
};
//A deadly vortex

class Maelstrom : public Events {
public:
    void execute(Ship& ship) override;
};


//Class dedicated to pirate attacks

class PirateAttack : public Events {
public:
    void execute(Ship& ship) override;
};

//Class finding treasure afloat on the way to the island

class Treasure : public Events {
public:
    void execute(Ship& ship) override;
};

//Class dedicated to special event kraken - might be instant death if unlucky

class Kraken : public Events {
public:
    void execute(Ship& ship) override;
};

#endif /* Events_hpp */
