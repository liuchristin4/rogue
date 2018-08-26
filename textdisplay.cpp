#include "textdisplay.h"
#include "cell.h"
#include "character.h"

TextDisplay::~TextDisplay(){}

TextDisplay::TextDisplay() {
    theDisplay.resize(row);
    for (auto &i: theDisplay) {
        i.resize(col);
    }
}

// constructs the correct char floor type that corresponds to the cell
void TextDisplay::buildFloor(Cell &whoBuild) {
    theDisplay[whoBuild.getRow()][whoBuild.getCol()] = whoBuild.getType();
}

// Updates the position of all the characters and items on the display
void TextDisplay::notify(Cell &whoNotified, std::stringstream &out) {

    Items i = whoNotified.getEnumItem();
    
    // if it's the PC
    if (whoNotified.getOccupant() == "PlayerCharacter") {
        theDisplay[whoNotified.getRow()][whoNotified.getCol()] = '@';
    }
    // if it is an Enemy
    else if (whoNotified.getOccupant() == "Enemy")  {
        if (whoNotified.getCharacter()->getRace() == "Human") {
            theDisplay[whoNotified.getRow()][whoNotified.getCol()] = 'H';
        } else if (whoNotified.getCharacter()->getRace() == "Dwarf") {
            theDisplay[whoNotified.getRow()][whoNotified.getCol()] = 'W';
        } else if (whoNotified.getCharacter()->getRace() == "Elf") {
            theDisplay[whoNotified.getRow()][whoNotified.getCol()] = 'E';
        } else if (whoNotified.getCharacter()->getRace() == "Orc") {
            theDisplay[whoNotified.getRow()][whoNotified.getCol()] = 'O';
        } else if (whoNotified.getCharacter()->getRace() == "Merchant") {
            theDisplay[whoNotified.getRow()][whoNotified.getCol()] = 'M';
        } else if (whoNotified.getCharacter()->getRace() == "Dragon") {
            theDisplay[whoNotified.getRow()][whoNotified.getCol()] = 'D';
        } else {
            theDisplay[whoNotified.getRow()][whoNotified.getCol()] = 'L';
        }
    }
       
    // if it is a potion
    else if ((int)i >= 0 && (int)i <= 5) {
        theDisplay[whoNotified.getRow()][whoNotified.getCol()] = 'P';
    }

    // if it is a treasure
    else if ((int)i >= 6 && (int)i <= 9) {
        theDisplay[whoNotified.getRow()][whoNotified.getCol()] = 'G';
    }
    
    // if it's the Stairs
    else if (whoNotified.getType() == '\\') {
        theDisplay[whoNotified.getRow()][whoNotified.getCol()] = '\\';
    }

    // else reset cell to floor tile 
    else { 
        theDisplay[whoNotified.getRow()][whoNotified.getCol()] = whoNotified.getType(); 
    }
     
}

std::ostream &operator<<(std::ostream &out, const TextDisplay &td) {
    for (auto &row: td.theDisplay) {
        for (auto c: row) {
            out << c;
        }
        out << std::endl;
    }
    return out;
}
