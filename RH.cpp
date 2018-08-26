#include "RH.h"
#include "playerCharacter.h"
#include <algorithm>
#include <string>

// constructor
RH::RH(): Potion{10} {}

// Increases health of PC by amt up to max
void RH::passEffect(PlayerCharacter &pc) {
    int amt = getAmt();
    if (pc.getRace() == "Vampire") {
        pc.setHP(pc.getHP() + amt);
    }
    else if (pc.getRace() == "Drow") {
        pc.setHP(std::min((int)(pc.getHP() + 1.5 * amt), pc.getMaxHp()));
    } else {
        pc.setHP(std::min(pc.getHP() + amt, pc.getMaxHp()));
    }
}
