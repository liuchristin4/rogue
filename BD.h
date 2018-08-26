#ifndef CC3K_FINAL_PROJECT_BD_H
#define CC3K_FINAL_PROJECT_BD_H

#include "potion.h"

class PlayerCharacter;

class BD: public Potion {
public:
    BD();
    void passEffect(PlayerCharacter &c) override;
};


#endif //CC3K_FINAL_PROJECT_BD_H
