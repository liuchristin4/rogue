#ifndef _TROLL_H_
#define _TROLL_H_

#include "playerCharacter.h"

class Troll: public PlayerCharacter {
  
  public:
    Troll(); //constructor
    //TODO will gain 5 HP every turn (done from floor)
    void struckBy(Character &c) override;
};

#endif 