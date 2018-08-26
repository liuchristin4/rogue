#ifndef _SHADE_H_
#define _SHADE_H_

#include "playerCharacter.h"

class Shade: public PlayerCharacter {

  public:
    Shade(); //constructor
    //no extra methods for now, will use all methods from the parent class PlayerCharacter 
    void struckBy(Character &c) override;
};

#endif 