#include "shade.h"

Shade::Shade(): PlayerCharacter{125, 25, 25, "Shade", 125} {};
    //using MIL to define all fields, including const maxHP

void Shade::struckBy(Character &c) {
    c.attack(*this);
}