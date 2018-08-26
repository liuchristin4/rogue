#include "MerchantHoard.h"
#include "playerCharacter.h"

// constructor
MerchantHoard::MerchantHoard(): Treasure{4} {}

// Increases gold points of PC by 4
void MerchantHoard::passEffect(PlayerCharacter &c) {
    int amt = getAmt();
    c.addGold(amt);
}
