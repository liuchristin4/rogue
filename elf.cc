#include "elf.h"
#include <cmath>
#include "character.h"
#include "shade.h"
#include "troll.h"
#include "goblin.h"
#include "vampire.h"

Elf::Elf(): Enemy{140, 30, 10, "Elf"} {};
    //will call the constructor of Character to set up the fields for Enemy

void Elf::attack(Shade &pc) {
    int pcHP = pc.getHP();
    int damage = (int)std::ceil((100.0/(100.0 + pc.getDef())) * 2 * getAtk());
    pc.setHP(std::max(pcHP - damage, 0));
}

void Elf::attack(Vampire &pc) {
    int pcHP = pc.getHP();
    int damage = (int)std::ceil((100.0/(100.0 + pc.getDef())) * 2 * getAtk());
    pc.setHP(std::max(pcHP - damage, 0));
}

void Elf::attack(Troll &pc) {
    int pcHP = pc.getHP();
    int damage = (int)std::ceil((100.0/(100.0 + pc.getDef())) * 2 * getAtk());
    pc.setHP(std::max(pcHP - damage, 0));
}

void Elf::attack(Goblin &pc) {
    int pcHP = pc.getHP();
    int damage = (int)std::ceil((100.0/(100.0 + pc.getDef())) * 2 * getAtk());
    pc.setHP(std::max(pcHP - damage, 0));
}

void Elf::struckBy(Character &c) {
    c.attack(*this);
}