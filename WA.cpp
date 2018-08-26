#include "WA.h"
#include "playerCharacter.h"
#include <cmath>

// constructor
WA::WA(): Potion{-5} {}

// Decreases Attack of PC by amt (-5) up to 0 and sets the buffer of attack to its effect
void WA::passEffect(PlayerCharacter &c) {
    int amt = getAmt();

    if (c.getAtk() != 0){
        if (c.getRace() == "Drow"){ 
            amt = amt * 1.5;                    //all potions get maginified by 1.5 for Drow 
            int newAtk= std::max(c.getAtk() + amt, 0); //the Atk can never go below 0
            c.setAtk(newAtk);       
            int newBuffAtk= c.getBuffAtk() + amt;
            c.setBuffAtk(newBuffAtk);
        } else {
            int newAtk= std::max(c.getAtk() + amt, 0); //the Atk can never go below 0
            c.setAtk(newAtk);
            int newBuffAtk= c.getBuffAtk() + amt;
            c.setBuffAtk(newBuffAtk);
        }
    }
}
