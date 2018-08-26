#ifndef _CELL_H_
#define _CELL_H_

#include <string>
#include <memory>
#include <sstream>
#include "subject.h"
#include "observer.h"

class Character;
class Item;

class PlayerCharacter;

enum class Items { RH, BA, BD, PH, WA, WD, NH, SH, MH, DH, None};

class Cell: public Subject, public Observer{
    const int row, col;
    char type;
    bool occupied;
    Character *character;
    Items item = Items::None;
    std::shared_ptr<Item> realItem;
    std::string occupant; 

public:
    Cell(int row, int col, char type, bool occupied);
    void notifyObservers(std::stringstream &out) override;
    void notify(Cell &whoFrom, std::stringstream &out) override;
    std::string getOccupant();
    bool isOccupied();
    void leaveOccupant();
    Character *getCharacter();
    void setCharacter(std::string occ, Character *c);
    std::shared_ptr<Item>getItem();
    Items getEnumItem();
    void setItem(std::shared_ptr<Item>i, Items it);
    char getType(); // get the type (i.e. #, |, -, ., ...etc.)
    void setType(char c);
    int getRow();
    int getCol();

};

#endif
