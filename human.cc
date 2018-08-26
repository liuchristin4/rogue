#include "human.h"

Human::Human(): Enemy{140, 20, 20, "Human"} {};
    //will call the constructor of Character to set up the fields for Enemy
    //TODO check if we need to pass the name as a field

void Human::struckBy(Character &c) {
    c.attack(*this);
}