#ifndef CC3K_FINAL_PROJECT_WD_H
#define CC3K_FINAL_PROJECT_WD_H

#include "potion.h"

class PlayerCharacter;

class WD: public Potion {
public:
    WD();
    void passEffect(PlayerCharacter &c);
};


#endif //CC3K_FINAL_PROJECT_WD_H
