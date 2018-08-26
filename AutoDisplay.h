#ifndef _AUTO_DISPLAY_H_
#define _AUTO_DISPLAY_H_

#include <iostream>
#include <iomanip>
#include <sstream>
#include "playerCharacter.h"

class AutoDisplay{
public:
    void printOptions();
    void printStats(PlayerCharacter &pc, int floor, std::stringstream &out);
};

// Prints opening screen allowing user to choose with player character
// to set for the game
void AutoDisplay::printOptions(){
    std::cout << "Please choose a race" << std::endl;
    std::cout << "s - Shade" << std::endl;
    std::cout << "d - Drow" << std::endl;
    std::cout << "v - Vampire" << std::endl;
    std::cout << "g - Goblin" << std::endl;
    std::cout << "t - Troll" << std::endl;
}


// Display of player character's stats and action as the game gets played
void AutoDisplay::printStats(PlayerCharacter &pc, int level, std::stringstream &out){
    std::cout << "Race: " << pc.getRace() << " Gold: " << pc.getGold()
              << std::setw(57) << "Floor: " << level << std::endl;
    std::cout << "HP: " << pc.getHP() << std::endl;
    std::cout << "Atk: " << pc.getAtk() << std::endl;
    std::cout << "Def: " << pc.getDef() << std::endl;
    std::cout << "Action: ";
    std::cout << out.str() << std::endl; //TODO: UPDATE
}

#endif