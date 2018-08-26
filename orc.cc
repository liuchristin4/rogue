#include "orc.h"
#include "goblin.h"


Orc::Orc():Enemy{180, 30, 25, "Orc"}{};
    //will call the constructor of Character to set up the fields for Enemy
    //TODO check if we need to pass the name as a field

// Orc does double the damage to Goblins
void Orc::attack(Goblin &pc) {
    int pcHP = pc.getHP();
    int damage = (int)std::ceil((100.0/(100.0 + pc.getDef())) * getAtk());
    pc.setHP(std::max((int)(pcHP - 1.5 * damage), 0));
}

void Orc::struckBy(Character &c) {
    c.attack(*this);
}
