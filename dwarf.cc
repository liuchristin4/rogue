#include "dwarf.h"

Dwarf::Dwarf(): Enemy{100, 20, 30, "Dwarf"} {};
    //will call the constructor of Character to set up the fields for Enemy
    //TODO check if we need to pass the name as a field

void Dwarf::struckBy(Character &c) {
    c.attack(*this);
}