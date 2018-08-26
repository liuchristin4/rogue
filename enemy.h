#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "character.h"

class Enemy: public Character{
    //Parent Class Character will initialize all the fields of Enemy
    public:
        Enemy(int Hp, int Atk, int Def, std::string race);
};



#endif

