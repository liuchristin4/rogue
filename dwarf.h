#ifndef _DWARF_H_
#define _DWARF_H_

#include "enemy.h"

class Dwarf: public Enemy{
  
  public:
    Dwarf();
    void struckBy(Character &c) override;
};

#endif