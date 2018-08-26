#ifndef CC3K_FINAL_PROJECT_PH_H
#define CC3K_FINAL_PROJECT_PH_H

#include "potion.h"

class PlayerCharacter;

class PH: public Potion  {
public:
    PH();
    void passEffect(PlayerCharacter &c) override;
};


#endif //CC3K_FINAL_PROJECT_PH_H
