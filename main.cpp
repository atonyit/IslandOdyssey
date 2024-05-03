//
//  main.cpp
//  IslandGame
//
//  Created by Alan Tony-Itoyah on 4/8/24.
//

#include "player.h"
#include "gameManager.h"
#include "Events.hpp"
#include "island.hpp"
#include "ship.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;


int main(){
    
    srand(static_cast<unsigned int>(time(0)));

    cout << "Welcome to the Island Exploration game" << endl;
    
    //creating a new player and printing his info
    Player player;
    player.printPlayerInfo();
    
    //Printing info of default Scout Ship
    GameManager gameManager(&player);
    gameManager.printCurrentShipInfo();
    
    bool running = true;
    int choice;

        while (running) {
            cout << "Choose an option:" << endl;
            cout << "1. Explore an Island" << endl;
            cout << "2. Use Ship Special Ability" << endl;
            cout << "3. Print Stats" << endl;
            cout << "4. Upgrade Ship" << endl;
            cout << "5. Save Game" << endl;
            cout << "6. Load Game" << endl;
            cout << "7. Exit" << endl;
            cout << "Enter your choice: " << endl;
            cin >> choice;

            switch (choice) {
                case 1: {
                    //random events
                    gameManager.triggerRandomEvent();
                    
                    int islandChoice;
                    cout << "Select an Island to explore:" << endl;
                    cout << "1. Desert Island" << endl;
                    cout << "2. Forest Island" << endl;
                    cout << "3. Swamp Island" << endl;
                    cout << "4. Snow Tundra Island" << endl;
                    cout << "5. Nether Island" << endl;
                    cout << "Enter your choice: " << endl;
                    cin >> islandChoice;

                    Island* island = nullptr;
                    switch (islandChoice) {
                        case 1:
                            island = new DesertIsland();
                            break;
                        case 2:
                            island = new ForestIsland();
                            break;
                        case 3:
                            island = new SwampIsland();
                            break;
                        case 4:
                            island = new SnowTundraIsland();
                            break;
                        case 5:
                            island = new NetherIsland();
                            break;
                        default:
                            cout << "Invalid choice, returning to main menu." << endl;
                            continue;
                    }

                    if (island) {
                        island->explore(*gameManager.getCurrentShip());
                        delete island;
                    }
                    break;
                }
                case 2: {
                    // Ship Special Ability
                    cout << "Attempting activation!" << endl;
                    gameManager.getCurrentShip() -> specialAbility();
                    break;
                }
                case 3: {
                    // Print Stats
                    int choice;
                    cout << "Available Options:" << endl;
                    cout << "1. Player Information" << endl;
                    cout << "2. Ship Information" << endl;
                    cout << "Enter Choice: " << endl;
                    cin >> choice;
                    
                    if(choice == 1){
                        player.printPlayerInfo();
                    }
                    else if(choice == 2){
                        gameManager.printCurrentShipInfo();
                    }
                    else{
                        cout << "Invalid Choice, returning to main menu." << endl;
                        continue;
                    }
                    break;
                }
                case 4: {
                    // Upgrade the ship
                    int shipType;
                    cout << "Available Ships for Upgrade:" << endl;
                    cout << "1. Scout Ship (Cost: 300)" << endl;
                    cout << "2. Galleon Ship (Cost: 500)" << endl;
                    cout << "3. Submarine Ship (Cost: 700)" << endl;
                    cout << "Enter the ship type you wish to upgrade to: ";
                    cin >> shipType;
                    gameManager.upgradeShip(shipType);
                    break;
                }
                case 5:
                    // Save the game
                    gameManager.saveGame(player);
                    break;
                case 6:
                    // Load a saved game
                    gameManager.loadGame(player);
                    break;
                case 7:
                    // Exit the game
                    int choice;
                    cout << "Available Options:" << endl;
                    cout << "Are you sure you want to exit the game? Press 1 if sure." << endl;
                    cout << "Press any other number to continue playing." << endl;
                    cin >> choice;
                    
                    if(choice == 1){
                        running = false;
                        break;
                    }
                    else{
                        break;
                    }
                    
                default:
                    cout << "Invalid choice, please try again" << endl;
            }
        }
        
        return 0;
}
