#ifndef CC3K_FINAL_PROJECT_SMALL_H
#define CC3K_FINAL_PROJECT_SMALL_H

#include "treasure.h"

class PlayerCharacter;

class Small: public Treasure {
public:
    Small();
    void passEffect(PlayerCharacter &c) override;

};


#endif //CC3K_FINAL_PROJECT_SMALL_H
