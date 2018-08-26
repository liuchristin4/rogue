#include "BA.h"
#include "playerCharacter.h"


//constructor
BA::BA(): Potion{5} {}

// Increases magnitude of Attack of PC by amt
void BA::passEffect(PlayerCharacter &c) {
    int amt = getAmt();

    if (c.getRace() == "Drow") {
        amt = (int)(amt * 1.5); //all potions get maginified by 1.5 for Drow
    }
    int newAtk = c.getAtk() + amt;
    c.setAtk(newAtk);
    int newBuffAtk= c.getBuffAtk() + amt;
    c.setBuffAtk(newBuffAtk);


}
