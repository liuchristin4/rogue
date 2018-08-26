#ifndef _DROW_H_
#define _DROW_H_

#include "playerCharacter.h"


class Drow: public PlayerCharacter {
  
  public:
    Drow(); //constructor
    void struckBy(Character &c) override;

};

#endif 