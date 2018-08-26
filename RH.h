#ifndef CC3K_FINAL_PROJECT_RH_H
#define CC3K_FINAL_PROJECT_RH_H

#include "potion.h"

class PlayerCharacter;

class RH: public Potion {
public:
    RH();
    void passEffect(PlayerCharacter &c) override;
};


#endif //CC3K_FINAL_PROJECT_RH_H
