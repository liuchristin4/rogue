#ifndef _DRAGON_H_
#define _DRAGON_H_

#include "enemy.h"

class Dragon: public Enemy{
    // TODO: add the special fields to dragon later
public:
    Dragon();
    void struckBy(Character &c) override;
};

#endif