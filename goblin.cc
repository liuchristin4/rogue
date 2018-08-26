#include "goblin.h"

Goblin::Goblin(): PlayerCharacter{110, 15, 20, "Goblin", 110} {};
    //using MIL to define all fields, including const maxHP

void Goblin::struckBy(Character &c) {
    c.attack(*this);
}