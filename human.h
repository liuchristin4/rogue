#ifndef _HUMAN_H_
#define _HUMAN_H_

#include "enemy.h"

class Human: public Enemy{
  
  public:
    Human();
    void struckBy(Character &c) override;
};

#endif