#ifndef CC3K_FINAL_PROJECT_NORMAL_H
#define CC3K_FINAL_PROJECT_NORMAL_H


#include "treasure.h"

class PlayerCharacter;

class Normal: public Treasure {

public:
    Normal();
    void passEffect(PlayerCharacter &c) override;

};

#endif //CC3K_FINAL_PROJECT_NORMAL_H
