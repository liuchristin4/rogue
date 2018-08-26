#ifndef CC3K_FINAL_PROJECT_DRAGONHOARD_H
#define CC3K_FINAL_PROJECT_DRAGONHOARD_H

#include "treasure.h"

class PlayerCharacter;


class DragonHoard: public Treasure {
public:
    DragonHoard();
    void passEffect(PlayerCharacter &c);

};


#endif //CC3K_FINAL_PROJECT_DRAGONHOARD_H
