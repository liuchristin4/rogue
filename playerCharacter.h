#ifndef _PLAYER_CHARACTER_H_
#define _PLAYER_CHARACTER_H_

#include "character.h"
#include <string>


class PlayerCharacter: public Character {

    int Gold = 0;
    const int maxHp;
    int buffAtk = 0;
    int buffDef = 0;

public:

    PlayerCharacter(int HP, int Def, int Atk, std::string race, int maxHP);
    virtual ~PlayerCharacter() = 0;
    int getGold();
    void addGold(int amount);
    int getMaxHp();
    void move(std::string direction);
    int getBuffAtk();
    void setBuffAtk(int amt);
    int getBuffDef();
    void setBuffDef(int amt);

};


#endif 