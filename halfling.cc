#include "halfling.h"
#include "character.h"

Halfling::Halfling(): Enemy{100, 15, 20, "Halfling"} {};
    //will call the constructor of Character to set up the fields for Enemy
    //TODO check if we need to pass the name as a field

void Halfling::struckBy(Character &c) {
    c.attack(*this);
}