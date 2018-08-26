#ifndef _ORC_H_
#define _ORC_H_

#include "enemy.h"

class Goblin;

class Orc: public Enemy {
  
  public:
    Orc();
    void attack(Goblin &pc) override;
    void struckBy(Character &c) override;
};

#endif