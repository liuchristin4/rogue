#include "drow.h"
#include <cmath>

Drow::Drow():PlayerCharacter{150, 25, 15, "Drow", 150} {}
    //using MIL to define all fields, including const maxHP

void Drow::struckBy(Character &c) {
    c.attack(*this);
}
