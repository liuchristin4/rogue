#include "character.h"
#include "human.h"
#include "elf.h"
#include "merchant.h"
#include "dragon.h"
#include "dwarf.h"
#include "orc.h"
#include "halfling.h"
#include "goblin.h"
#include "drow.h"
#include "shade.h"
#include "vampire.h"
#include "troll.h"
#include <cmath>

Character::Character(int HP, int Atk, int Def, const std::string race):
        HP{HP}, Atk{Atk}, Def{Def}, race{race} {}

// returns the health points of the character
int Character::getHP() {
    return HP;
}

// update value of HP
void Character::setHP(int newHP) {
    HP = newHP;
}

// returns the attack ability of the character
int Character::getAtk() {
    return Atk;
}

// update the value of Atk
void Character::setAtk(int newAtk) {
    Atk = newAtk;
}

// returns the defense ability of the character
int Character::getDef() {
    return Def;
}

// update the value of Def
void Character::setDef(int newDef) {
    Def = newDef;
}

// gets the Name of the Character
std::string Character::getRace() {
    return race;
}


//Accessors for row and column 
int Character::getRow(){
    return row;
}

int Character::getCol(){
    return col;
}


//Setter for row and column when PC moves
void Character::setRow(int newRow){
    row = newRow;
}

void Character::setCol(int newCol){
    col = newCol;
}


// Character attacks Human
void Character::attack(Human &e) {
    int characterHP = e.getHP();
    int damage = (int)std::ceil((100.0/(100.0 + e.getDef())) * getAtk());
    e.setHP(std::max(characterHP - damage, 0));
}

// Character attacks Dwarf
void Character::attack(Dwarf &e) {
    int characterHP = e.getHP();
    int damage = (int)std::ceil((100.0/(100.0 + e.getDef())) * getAtk());
    e.setHP(std::max(characterHP - damage, 0));
}

// Character attacks Elf
void Character::attack(Elf &e) {
    int characterHP = e.getHP();
    int damage = (int)std::ceil((100.0/(100.0 + e.getDef())) * getAtk());
    e.setHP(std::max(characterHP - damage, 0));
}

//Character attacks Orc
void Character::attack(Orc &e) {
    int characterHP = e.getHP();
    int damage = (int)std::ceil((100.0/(100.0 + e.getDef())) * getAtk());
    e.setHP(std::max(characterHP - damage, 0));
}

// Character attacks Merchant
void Character::attack(Merchant &e) {
    int characterHP = e.getHP();
    int damage = (int)std::ceil((100.0/(100.0 + e.getDef())) * getAtk());
    e.setHP(std::max(characterHP - damage, 0));
}

// Character attacks Dragon
void Character::attack(Dragon &e) {
    int characterHP = e.getHP();
    int damage = (int)std::ceil((100.0/(100.0 + e.getDef())) * getAtk());
    e.setHP(std::max(characterHP - damage, 0));
}

// Character attacks Hafling, PC has a 50% of missing
void Character::attack(Halfling &e) {
    int hit = rand() % 2;
    if (hit) {
        int characterHP = e.getHP();
        int damage = (int)std::ceil((100.0/(100.0 + e.getDef())) * getAtk());
        e.setHP(std::max(characterHP - damage, 0));
    }
}

// Character attacks Shade
void Character::attack(Shade &pc) {
    int characterHP = pc.getHP();
    int damage = (int)std::ceil((100.0/(100.0 + pc.getDef())) * getAtk());
    pc.setHP(std::max(characterHP - damage, 0));
}

// Character attacks Drow
void Character::attack(Drow &pc) {
    int characterHP = pc.getHP();
    int damage = (int)std::ceil((100.0/(100.0 + pc.getDef())) * getAtk());
    pc.setHP(std::max(characterHP - damage, 0));
}

// Character attacks Vampire
void Character::attack(Vampire &pc) {
    int characterHP = pc.getHP();
    int damage = (int)std::ceil((100.0/(100.0 + pc.getDef())) * getAtk());
    pc.setHP(std::max(characterHP - damage, 0));
}

// Character attacks Troll
void Character::attack(Troll &pc) {
    int characterHP = pc.getHP();
    int damage = (int)std::ceil((100.0/(100.0 + pc.getDef())) * getAtk());
    pc.setHP(std::max(characterHP - damage, 0));
}

// Character attacks Goblin
void Character::attack(Goblin &pc) {
    int characterHP = pc.getHP();
    int damage = (int)std::ceil((100.0/(100.0 + pc.getDef())) * getAtk());
    pc.setHP(std::max(characterHP - damage, 0));
}