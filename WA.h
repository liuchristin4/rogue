#ifndef CC3K_FINAL_PROJECT_WA_H
#define CC3K_FINAL_PROJECT_WA_H

#include "potion.h"

class PlayerCharacter;

class WA: public Potion {
public:
    WA();
    void passEffect(PlayerCharacter &c);
};


#endif //CC3K_FINAL_PROJECT_WA_H
