#include "vampire.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "dragon.h"
#include "halfling.h"

Vampire::Vampire():PlayerCharacter{50, 25, 25, "Vampire", 500}{};  //Vampire does not have a max hp
    //using MIL to define all fields, including const maxHP

// Vampires gain 5HP per successful attack

void Vampire::attack(Human &e) {
    int eHP = e.getHP();
    int damage = std::ceil((100.0/(100.0 + e.getDef())) * getAtk());
    e.setHP(std::max(eHP - damage, 0));
    setHP(getHP() + 5);
}

//Vampire is allergic to Dwarfs if it attacks it will loose 5 HP,
// it also gains 5 HP every succesfull attack (which is always)
void Vampire::attack(Dwarf &e) {
    int eHP = e.getHP();
    int damage = std::ceil((100.0/(100.0 + e.getDef())) * getAtk());
    e.setHP(std::max(eHP - damage, 0));
    setHP(getHP() - 5);
}

void Vampire::attack(Elf &e) {
    int eHP = e.getHP();
    int damage = std::ceil((100.0/(100.0 + e.getDef())) * getAtk());
    e.setHP(std::max(eHP - damage, 0));
    setHP(getHP() + 5);
}

void Vampire::attack(Orc &e) {
    int eHP = e.getHP();
    int damage = std::ceil((100.0/(100.0 + e.getDef())) * getAtk());
    e.setHP(std::max(eHP - damage, 0));
    setHP(getHP() + 5);
}

void Vampire::attack(Merchant &e) {
    int eHP = e.getHP();
    int damage = std::ceil((100.0/(100.0 + e.getDef())) * getAtk());
    e.setHP(std::max(eHP - damage, 0));
    setHP(getHP() + 5);
}

void Vampire::attack(Dragon &e) {
    int eHP = e.getHP();
    int damage = std::ceil((100.0/(100.0 + e.getDef())) * getAtk());
    e.setHP(std::max(eHP - damage, 0));
    setHP(getHP() + 5);
}

void Vampire::attack(Halfling &e) {
    int eHP = e.getHP();
    int damage = std::ceil((100.0/(100.0 + e.getDef())) * getAtk());
    e.setHP(std::max(eHP - damage, 0));
    setHP(getHP() + 5);
}

void Vampire::struckBy(Character &c) {
    c.attack(*this);
}

