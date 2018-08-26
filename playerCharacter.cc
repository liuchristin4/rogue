#include "playerCharacter.h"


//constructor, will call Character constructor since the PC will always start with 0 gold, buffAtk and buffDef so we create a default param por these
//row and column are set to 0 as well, floor will change this whenever it decides where to spawn this
PlayerCharacter::PlayerCharacter( int HP, int Def, int Atk, std::string race, int maxHp):
        Character{HP, Def, Atk, race}, maxHp{maxHp} {}

PlayerCharacter::~PlayerCharacter() = default;

// Returns how many points PC has
int PlayerCharacter::getGold() {
    return Gold;
}

// Increases the value of totalGold by moreGold
void PlayerCharacter::addGold(int moreGold) {
    int newGoldAmt = getGold() + moreGold;
    Gold = newGoldAmt;
}
// TODO: come back to this later

int PlayerCharacter::getMaxHp(){
    return maxHp;
}


// Moves PC one unit in direction d
void PlayerCharacter::move(std::string direction) {
    if (direction == "ne") {
        int newRow = getRow() - 1;
        int newCol = getCol() + 1;
        setRow(newRow);
        setCol(newCol);
    } else if (direction == "no") {
        int newRow = getRow() - 1;
        setRow(newRow);
    } else if (direction == "so") {
        int newRow = getRow() + 1;
        setRow(newRow);
    } else if (direction == "ea") {
        int newCol = getCol() + 1;
        setCol(newCol);
    } else if (direction == "we") {
        int newCol = getCol() - 1;
        setCol(newCol);
    } else if (direction == "nw") {
        int newRow = getRow() - 1;
        int newCol = getCol() - 1;
        setRow(newRow);
        setCol(newCol);
    } else if (direction == "se") {
        int newRow = getRow() + 1;
        int newCol = getCol() + 1;
        setRow(newRow);
        setCol(newCol);
    } else if (direction == "sw") {
        int newRow = getRow() + 1;
        int newCol = getCol() - 1;
        setRow(newRow);
        setCol(newCol);
    }
}

int PlayerCharacter::getBuffAtk(){
    return buffAtk;
}

void PlayerCharacter::setBuffAtk(int amt){
    buffAtk = amt;
}

int PlayerCharacter::getBuffDef(){
    return buffDef;
}

void PlayerCharacter::setBuffDef(int amt){
    buffDef = amt;
}