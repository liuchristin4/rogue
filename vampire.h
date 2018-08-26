#ifndef _VAMPIRE_H_
#define _VAMPIRE_H_

#include "playerCharacter.h"

class Human;
class Dwarf;
class Elf;
class Orc;
class Merchant;
class Dragon;
class Halfling;
class Character;

class Vampire: public PlayerCharacter {
  
  public:
    Vampire(); //constructor
    void attack(Human &e) override;
    void attack(Dwarf &e) override;
    void attack(Elf &e) override;
    void attack(Orc &e) override;
    void attack(Merchant &e) override;
    void attack(Dragon &e) override;
    void attack(Halfling &e) override;
    void struckBy(Character &c) override;
};

#endif 