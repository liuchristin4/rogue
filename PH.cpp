#include "PH.h"
#include "playerCharacter.h"

// constructor
PH::PH(): Potion{-10} {}

// Decreases the health of PC by amt
void PH::passEffect(PlayerCharacter &c) {
    int amt = getAmt();
    if (c.getRace() == "Drow") {
        c.setHP(std::max((int)(c.getHP() + 1.5 * amt), 0));
    } else {
        c.setHP(std::max(c.getHP() + amt, 0));
    }
}
