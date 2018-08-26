#include "BD.h"
#include "playerCharacter.h"

// constructor
BD::BD(): Potion{5} {}

// Increases magnitude of Defence of PC by amt
inline void BD::passEffect(PlayerCharacter &c) {
    int amt = getAmt();

    if (c.getRace() == "Drow"){
        amt = (int)(amt * 1.5); // All potions have 1.5 times effect on Drow
    }
    int newDef = c.getDef() + amt;
    c.setDef(newDef);
    int newBuffDef= c.getBuffDef() + amt;
    c.setBuffDef(newBuffDef);

}



