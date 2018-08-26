#include "cell.h"
#include "observer.h"
#include "subject.h"
#include "character.h"
#include "item.h"
#include "playerCharacter.h"
#include "merchant.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

Cell::Cell(int row, int col, char type, bool occupied):   //constructor
        row{row}, col{col}, type{type}, occupied{occupied} {} 


// Gets notification from neighbour
void Cell::notify(Cell &whoFrom, std::stringstream &out) {

    // Does not do anything if occupant is a floor tile
    if (getType() != '.') { return ; } 
    // Does not do anything if 
    if (!whoFrom.isOccupied()) { return ; } 

    // Case 1: the occupant is an enemy and the Cell notifying has a PC 
    if (getOccupant() == "Enemy") {
        
        if (whoFrom.getOccupant() == "PlayerCharacter") {
            //there is a 50% chance the Enemy does attack
            int attackFreq = rand() % 2; 
            //all enemies except for Merchant are hostile to PC
            if (character->getRace() != "Merchant") {
                if (attackFreq == 1) {
                    int damageToPC = (int)std::ceil((100.0/(100.0 + 
                    whoFrom.getCharacter()->getDef())) * character->getAtk());
                    whoFrom.getCharacter()->struckBy(*character); 
                    out << character->getRace() << " (Enemy) deals " 
                        << damageToPC << " damage to " 
                        << whoFrom.getCharacter()->getRace() 
                        << " ("  << whoFrom.getCharacter()->getHP() 
                        << " HP). ";
                }
            } 
            //Merchants will only attack if they are Hostile
            else if (dynamic_cast<Merchant *>(character)->isHostile()){
                    if (attackFreq == 1) { 
                        whoFrom.getCharacter()->struckBy(*character); 
                        out << character->getRace() << " struck " 
                        << whoFrom.getCharacter()->getRace() << " ";
                    }
            }

        }
    }

}

void Cell::notifyObservers(std::stringstream &out) {
    for (auto &o: observers){ o->notify(*this, out); }
}

//Accessor for occupant in Cell
std::string Cell::getOccupant() {
    return occupant;
}

// Checks if cell is occupied by any Character
bool Cell::isOccupied() {
    return occupied;
}

// Updates occupied status when character leaves the Cell
void Cell::leaveOccupant() {
    character = nullptr;
    occupied = false;
    occupant = ""; 
}

// Returns pointer to either an PC or Enemy
Character * Cell::getCharacter() {
    return character;
}

// updates type of occupant in cell when Character moves onto it
void Cell::setCharacter(std::string occ, Character *c) {
    character = c;
    occupant = occ;
    occupied = true;
}

// Returns pointer to either Potion or Treasure
std::shared_ptr<Item>Cell::getItem() { 
    return realItem; 
}

// Returns the Items type from Items enum
Items Cell::getEnumItem() { return item; }

// sets item to point at i
void Cell::setItem(std::shared_ptr<Item> i, Items it) {
    item = it;
    realItem = i;
}

// Returns the type of the cell
char Cell::getType() { return type; }

// Sets the type of the cell
void Cell::setType(char c) {
    type = c;
}

// returns which row cell is in
int Cell::getRow() { return row; }

// returns which col cell is in
int Cell::getCol() { return col; }

