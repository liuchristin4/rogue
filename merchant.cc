#include "merchant.h"

Merchant::Merchant(): Enemy{30, 70, 5, "Merchant"},hostile{false} {}

void Merchant::setHostile(){
    hostile = true;
}
bool Merchant::isHostile(){
    return hostile;
}

void Merchant::struckBy(Character &c) {
    c.attack(*this);
}