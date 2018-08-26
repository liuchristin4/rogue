#ifndef _ELF_H_
#define _ELF_H_

#include "enemy.h"

class Shade;
class Vampire;
class Goblin;
class Character;


class Elf: public Enemy {
//    void doubleAttack(PlayerCharacter &c);
  public:
    Elf();
    void attack(Shade &pc) override;
    void attack(Vampire &pc) override;
    void attack(Troll &pc) override;
    void attack(Goblin &pc) override;
    void struckBy(Character &c) override;
};

#endif