#include "normal.h"
#include "playerCharacter.h"

// constructor
Normal::Normal(): Treasure{2} {}

// Increases gold points of PC by 2
void Normal::passEffect(PlayerCharacter &c) {
    int amt = getAmt();
    c.addGold(amt);
}
