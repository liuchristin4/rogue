#ifndef _MERCHANT_H_
#define _MERCHANT_H_

#include "enemy.h"

class Merchant: public Enemy{
    bool hostile;

  public:
    Merchant();
    void setHostile();
    bool isHostile();
    void struckBy(Character &c) override;
};

#endif