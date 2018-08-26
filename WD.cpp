#include "WD.h"
#include "playerCharacter.h"

// constructor
WD::WD(): Potion{-5} {}

// Decreases Defense of PC by amt up to 0 
void WD::passEffect(PlayerCharacter &c) {
    int amt = getAmt();
    
    if (c.getDef() != 0){
        if (c.getRace() == "Drow"){ 
            amt = amt * 1.5;                    //all potions get maginified by 1.5 for Drow 
            int newDef = std::max(c.getDef() + amt, 0); //the Def can never go below 0
            c.setDef(newDef);       
            int newBuffDef= c.getBuffDef() + amt; //TODO check 
            c.setBuffDef(newBuffDef);
        } else {
            int newDef= std::max(c.getDef() + amt, 0); //the Def can never go below 0
            c.setDef(newDef);
            int newBuffDef= c.getBuffDef() + amt;
            c.setBuffDef(newBuffDef);
        }
    }
}