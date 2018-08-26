#ifndef CC3K_FINAL_PROJECT_MERCHANTHOARD_H
#define CC3K_FINAL_PROJECT_MERCHANTHOARD_H

#include "treasure.h"

class PlayerCharacter;

class MerchantHoard: public Treasure{
    
public:
    MerchantHoard();
    void passEffect(PlayerCharacter &c) override;

};


#endif //CC3K_FINAL_PROJECT_MERCHANTHOARD_H
