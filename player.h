//
//  player.h
//  IslandGame
//
//  Created by Alan Tony-Itoyah on 4/8/24.
//

#ifndef player_h
#define player_h

class Player{
    public:
    //Constructor
    Player() : money(100), damage(0), health(100) {}
    
    Player(int startingMoney, int startingDamage, int startingHealth);
    
    //get
    int getMoney();
    int getHealth();
    
    //set
    void setMoney(int moneyAmount);
    void setDamage(int damageAmount);
    void setHealth(int healthAmount);
    
    //game functions
    void endGame();
    void receiveDamage(int amount);
    void increaseMoney(int amount);
    void decreaseMoney(int amount);
    void increaseDamage(int amount);
    
    //Print the players current stats
    void printPlayerInfo();
    
    private:
        int money;
        int damage;
        int health;
    
};


#endif /* player_h */
