#include "dragonhoard.h"
#include "playerCharacter.h"

// constructor
DragonHoard::DragonHoard(): Treasure{6} {}

// Increases gold points of PC by 6
void DragonHoard::passEffect(PlayerCharacter &pc) {
    pc.addGold(getAmt());
}
