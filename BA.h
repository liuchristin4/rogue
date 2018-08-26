#ifndef CC3K_FINAL_PROJECT_BA_H
#define CC3K_FINAL_PROJECT_BA_H

#include "potion.h"

class PlayerCharacter;

class BA: public Potion {
public:
    BA();
    void passEffect(PlayerCharacter &c) override;

};


#endif //CC3K_FINAL_PROJECT_BA_H
