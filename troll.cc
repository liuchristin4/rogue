#include "troll.h"

Troll::Troll():PlayerCharacter{120, 25, 15, "Troll", 120}{};
    //using MIL to define all fields, including const maxHP

void Troll::struckBy(Character &c) {
    c.attack(*this);
}