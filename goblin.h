#ifndef _GOBLIN_H_
#define _GOBLIN_H_

#include "playerCharacter.h"

class Goblin: public PlayerCharacter{
  
  public:
    Goblin(); //constructor
    //TODO gets 5 gold for every slain enemy this will get called from above
    //no extra methods for now, will use all methods from the parent class PlayerCharacter 
    void struckBy(Character &c) override;
};

#endif 