#ifndef _CHARACTER_H
#define _CHARACTER_H

#include <string>
#include <time.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>

class Merchant;
class Human;
class Dwarf;
class Elf;
class Orc;
class Dragon;
class Halfling;
class Shade;
class Drow;
class Vampire;
class Troll;
class Goblin;


class Character {
    
    int HP;
    int Atk;
    int Def;
    std::string race;
    int row = 0;
    int col = 0;

public:

    Character(int HP, int Atk, int Def, const std::string race);
    //virtual ~Character() = 0; TODOOOOO 
    int getHP();                                                 
    void setHP(int newHP);                                           
    int getAtk();                                                
    void setAtk(int newAtk);                                       
    int getDef();                                                
    void setDef(int newDef);                                     
    std::string getRace();
    virtual void struckBy(Character &c)=0;
    int getRow();
    int getCol();
    void setRow(int newRow);
    void setCol(int newCol);
    virtual void attack(Human &e);
    virtual void attack(Dwarf &e);
    virtual void attack(Elf &e);
    virtual void attack(Orc &e);
    virtual void attack(Merchant &e);
    virtual void attack(Dragon &e);
    virtual void attack(Halfling &e);
    virtual void attack(Shade &pc);
    virtual void attack(Drow &pc);
    virtual void attack(Vampire &pc);
    virtual void attack(Troll &pc);
    virtual void attack(Goblin &pc);
};

#endif //CC3K_FINAL_PROJECT_CHARACTER_H