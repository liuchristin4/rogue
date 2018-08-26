#ifndef _HALFLING_H_
#define _HALFLING_H_

#include "enemy.h"

class Halfling: public Enemy {
  
  public:
    Halfling();
    void struckBy(Character &c) override;
};

#endif