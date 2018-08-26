#include "small.h"
#include "playerCharacter.h"

// constructor
Small::Small(): Treasure{1} {}

// Increases gold points of PC by 1
void Small::passEffect(PlayerCharacter &c) {
    int amt = getAmt();
    c.addGold(amt);
}
