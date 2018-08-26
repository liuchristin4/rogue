#include "dragon.h"

Dragon::Dragon(): Enemy{150, 20, 20, "Dragon"} {};
    //will call the constructor of Character to set up the fields for Enemy
    //TODO check if we need to pass the name as a field

void Dragon::struckBy(Character &c) {
    c.attack(*this);
}