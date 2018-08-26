#include "floor.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <utility>
#include "normal.h"
#include "small.h"
#include "dragonhoard.h"
#include "BA.h"
#include "BD.h"
#include "WD.h"
#include "WA.h"
#include "PH.h"
#include "RH.h"
#include "dwarf.h"
#include "orc.h"
#include "halfling.h"
#include "human.h"
#include "merchant.h"
#include "elf.h"
#include "dragon.h"
#include "textdisplay.h"
#include "cell.h"
#include "item.h"
#include "enemy.h"
#include "coordinate.h"
#include "playerCharacter.h"

//Input operator overload to read in the floor from a file 
std::istream &operator>>(std::istream &in, Floor &f){
  std::vector<Cell> row;

  for (int r = 0; r < f.maxRows; ++r) {
      f.theFloor.emplace_back(row);
      for (int c = 0; c < f.maxCols; ++c){
        f.theFloor[r].emplace_back(r,c,'.',false); //creates floor of cells ??
      }
  } 

  char character;
  int i = 0;
  while (in.get(character)){
      int r = i / f.maxCols;
      int c = i - r * f.maxCols;
    if (character != '\n') {
      f.theFloor[r % f.maxRows][c % f.maxCols].setType(character);
      i++;
    } 
  }
  return in;
}

//Generates a new (x,y) chamber coordinate when called
int Floor::genRandCoord(int &r, int &c){
  srand(time(NULL));
  int chamber;
  (void)chamber;

  do{ 
    chamber = rand() % 5; //chooses a random chamber (0-4)
    
    if (chamber == 0){ //r:3-6 | c:3-29 (top left)
      r = rand() % 3 + 3;
      c = rand() % 26 + 3;

    } else if (chamber == 1){ //r:3-13 | c:39-76 (top right)
      r = rand() % 10 + 3;
      if (r <= 4){
        c = rand() % 23 + 39;
      } else if (r == 5){
        c = rand() % 31 + 39;
      } else if (r == 6){
        c = rand() % 34 + 39;
      } else { //r:7-12
        c = rand() % 15 + 61;
      }

    } else if (chamber == 2){ //r:10-12 | c:38-49 (middle)
      r = rand() % 3 + 10;
      c = rand() % 12 + 38;

    } else if (chamber == 3){ // (bottom left)
      r = rand() % 7 + 15;
      c = rand() % 21 + 4;

    } else { // (bottom right)
      r = rand() % 6 + 16;
      if (r <= 18){
        c = rand() % 11 + 65;
      } else {
        c = rand() % 39 + 37;
      }
    }
  } while (std::find(taken.begin(), taken.end(), std::make_pair(r,c)) 
            != taken.end()); //re-generate if coordinate already taken

  taken.emplace_back(std::make_pair(r,c)); //add new coord to list of taken
  return chamber; //return chamber the generated coordinate is in
}

// Spawns PC and returns and int representing the chamber
// PC is spawned in (to ensure the stairs be in a different chamber)
int Floor::spawnPC(PlayerCharacter &pc, std::stringstream &out){
  int r = 0;
  int c = 0;
  int chamber = genRandCoord(r,c);
  
  //Give the pc spawned in main a position on the floor
  pc.setRow(r);
  pc.setCol(c);
  theFloor[r][c].setCharacter("PlayerCharacter", &pc);
  theFloor[r][c].notifyObservers(out);
  return chamber;
}

// Spawns stairs, makes sure the stair is not in the same chamber
// as the PC
void Floor::spawnStairs(int PCchamber, std::stringstream &out){
  int chamber;
  int r = 0;
  int c = 0;
  do { //generate a coordinate in a different chamber than PC
    chamber = genRandCoord(r,c);
  } while (chamber == PCchamber);
  theFloor[r][c].setType('\\');
  theFloor[r][c].notifyObservers(out);
}

// Spawns 10 Potions in Floor
void Floor::spawnPotions(std::stringstream &out){
  int r = 0;
  int c = 0;
  std::shared_ptr<Item> i; 
  Items item;
  for (int a = 0; a < 10; ++a){
    int chamber = genRandCoord(r,c);
    int ind = rand() % 5; //equal probability
    if (ind == 0){
      i = std::make_shared<RH>();
      item = Items::RH;
    } else if (ind == 1){
        i = std::make_shared<BA>();
      item = Items::BA;
    } else if (ind == 2){
      i = std::make_shared<BD>();
      item = Items::BD;
    } else if (ind == 3){
      i = std::make_shared<PH>();
      item = Items::PH;
    } else if (ind == 4){
      i = std::make_shared<WA>();
      item = Items::WA;
    } else {
      i = std::make_shared<WD>();
      item = Items::WD;
    }
    theFloor[r][c].setItem(i, item);
    theFloor[r][c].notifyObservers(out);
  }

}


// Spawns 10 treasures
void Floor::spawnTreasure(std::stringstream &out){
  int r = 0;
  int c = 0;
  std::shared_ptr<Item> i;
  Items item;
  for (int a = 0; a < 10; ++a){
    int ind = rand() % 8 + 1;
    int chamber = genRandCoord(r,c);
    if (ind <= 5){ //Normal: 5/8 probability
      i = std::make_shared<Normal>();
      item = Items::NH;
    } else if (ind == 6){ //Dragon: 1/8 probability
      i = std::make_shared<DragonHoard>();
      item = Items::DH;
    } else { //Small: 1/4 probability
      i = std::make_shared<Small>();
      item = Items::SH;
    }
    theFloor[r][c].setItem(i, item);
    theFloor[r][c].notifyObservers(out);
  }
}


// Spawns 20 enemies in Floor
void Floor::spawnEnemies(std::stringstream &out){
  int r = 0;
  int c = 0;
  std::shared_ptr<Enemy> e;
  for (int i = 0; i < 20; ++i){
    int ind = rand() % 18 + 1;
    int chamber = genRandCoord(r,c);
    if (ind <= 5){ //Hafling: 5/18 probability
      e = std::make_shared<Halfling>();
    } else if (ind <= 8) { //Dwarf: 3/18 probability
      e = std::make_shared<Dwarf>();
    } else if (ind <= 12) { //Human: 4/18 probability
      e = std::make_shared<Human>();
    } else if (ind <= 14) { //Elf: 2/18 probability
      e = std::make_shared<Elf>();
    } else if (ind <= 16) { //Orc: 2/18 probability
      e = std::make_shared<Orc>();
    } else { //Merchant: 2/18 probability
      e = std::make_shared<Merchant>();
    }
    e->setCol(c);
    e->setRow(r);
    enemiesPtrs.emplace_back(e);
    theFloor[r][c].setCharacter("Enemy", e.get());
    theFloor[r][c].notifyObservers(out);
  }

}

// destructor
Floor::~Floor(){
}

void Floor::init(PlayerCharacter &pc, std::stringstream &out){
  theFloor.clear(); //clears previous floor;

  //set up the floor using input file
  std::ifstream file{"floor.txt"};
  file >> *this; //input operator overload

  //initialize textdisplay
  td = std::make_unique<TextDisplay>();
  
  //set up neighbours
  for (auto &row:theFloor){ 
    for (auto &cell:row){
      int cellC = cell.getCol();
      int cellR = cell.getRow();

      if (cellR+1 < maxRows){ //South neighbour
        cell.attach(&theFloor[cellR+1][cellC]);
      }
      if (cellR+1 < maxRows && cellC+1 < maxCols){ //South east neighbour
        cell.attach(&theFloor[cellR+1][cellC+1]);
      }
      if (cellC+1 < maxCols){  //East neighbout 
        cell.attach(&theFloor[cellR][cellC+1]);
      }
      if (cellR-1 >= 0 && cellC+1 < maxCols){ //North East neighbour
        cell.attach(&theFloor[cellR-1][cellC+1]);
      }
      if (cellR-1 >= 0){ //North neighbour 
        cell.attach(&theFloor[cellR-1][cellC]);
      }
      if (cellR-1 >= 0 && cellC-1 >= 0){ //North west neighbour
        cell.attach(&theFloor[cellR-1][cellC-1]);
      }
      if (cellC-1 >= 0){ //West neighbour 
        cell.attach(&theFloor[cellR][cellC-1]);
      } 
      if (cellR+1 < maxRows && cellC-1 >= 0){ //South west neighbour 
        cell.attach(&theFloor[cellR+1][cellC-1]);
      } 
      cell.attach(td.get()); //attach textdisplay as an observer 
      td->buildFloor(cell);
    }
  }
  int ch = spawnPC(pc, out); //Spawns PC and returns chamber PC is spawned in
  spawnStairs(ch, out); // Checks Stairs is not in PC's chamber
  spawnPotions(out);
  spawnTreasure(out);
  spawnEnemies(out);
}

// Returns the floor
int Floor::getLevel(){
  return level;
}

// Sets up new level (reinitializes floor, sets potion buffers to 0)
void Floor::nextLevel(PlayerCharacter &pc, std::stringstream &out){
  pc.setAtk(pc.getAtk()-pc.getBuffAtk());
  pc.setBuffAtk(0);
  pc.setDef(pc.getDef()-pc.getBuffDef());
  pc.setBuffDef(0);
  init(pc, out);
  ++level;
}

// PC chooses to attack Enemy
void Floor::attackEnemy(PlayerCharacter &pc, std::string dir, 
      std::stringstream &out){
  int r = pc.getRow();
  int c = pc.getCol();
  Character *e = nullptr;
  if (dir == "no") {
    e = theFloor[r-1][c].getCharacter();
  } else if (dir == "ne"){
    e = theFloor[r-1][c-1].getCharacter();
  } else if (dir == "ea"){
    e = theFloor[r+1][c].getCharacter();
  } else if (dir == "se"){
    e = theFloor[r+1][c+1].getCharacter();
  } else if (dir == "so"){
    e = theFloor[r][c+1].getCharacter();
  } else if (dir == "sw"){
    e = theFloor[r-1][c+1].getCharacter();
  } else if (dir == "we"){
    e = theFloor[r][c-1].getCharacter();
  } else { //NW
    e = theFloor[r-1][c-1].getCharacter();
  }
  if (e != nullptr) { //check if user selected cell is indeed an enemy to attack
    // If PC attacks a Merchant, sets all Merchants to become hostile
    if (e->getRace() == "Merchant") {
      for (auto &enemy:enemiesPtrs) {
        if (enemy->getRace() == "Merchant") { 
          dynamic_cast<Merchant *>(enemy.get())->setHostile(); 
        }
      }
    }

    int damageToPC = (int)std::ceil((100.0/(100.0 + 
                        pc.getDef())) * e->getAtk());
    int damageToEnemy = (int)std::ceil((100.0/(100.0 + 
                        e->getDef())) * pc.getAtk());
    e->struckBy(pc);

    if (e->getHP() == 0) {
        int re = e->getRow();
        int ce = e->getCol();
        theFloor[re][ce].leaveOccupant();

        std::shared_ptr<Item> i = std::make_shared<Normal>();

        theFloor[re][ce].setItem(i, Items::NH);
        theFloor[re][ce].notifyObservers(out);
    }

    out << "PC deals " << damageToEnemy << " damage to " << e->getRace() 
    << "(" << e->getHP() << " HP). "
      << e->getRace() << " deals " << damageToPC << " damage to PC.";
    theFloor[r][c].notifyObservers(out);

  }
}

bool Floor::validType(Cell &c){
  return (c.getType()=='.' || c.getType()=='+' ||
            c.getType()=='#' || c.getType()=='\\');
}

void Floor::movePCHelper(PlayerCharacter &pc, std::stringstream &out,
              int r, int c, int ogR, int ogC){
  if (!validType(theFloor[r][c]) || theFloor[r-1][c].isOccupied()) { 
      throw InvalidMove{};
  } else { 
      if (theFloor[r][c].getType()=='\\'){
        nextLevel(pc, out);
        out << "Next Level! "; 
      } else {
        if ((int)theFloor[r][c].getEnumItem() <= 8 
        && (int)theFloor[r][c].getEnumItem() >= 6){ //gold
          theFloor[r][c].getItem()->passEffect(pc);
          theFloor[r][c].setItem(nullptr,Items::None);
          out << "PC gets Gold! ";
        }
        theFloor[r][c].setCharacter("PlayerCharacter", &pc);
        theFloor[ogR][ogC].leaveOccupant();
        theFloor[r][c].notifyObservers(out);
        pc.setRow(r);
        pc.setCol(c);
      }
  }
}


void Floor::movePC(PlayerCharacter &pc, std::string d, std::stringstream &out){
  int r = pc.getRow();
  int c = pc.getCol();
    if (d == "no"){
      movePCHelper(pc,out,r-1,c,r,c);
      out << "PC moves North ";
    } else if (d == "ne"){
      movePCHelper(pc,out,r-1,c+1,r,c);
      out << "PC moves North East ";
    } else if (d == "ea"){
      movePCHelper(pc,out,r,c+1,r,c);
      out << "PC moves East ";
    } else if (d == "se"){
      movePCHelper(pc,out,r+1,c+1,r,c);
      out << "PC moves South East ";
    } else if (d == "so"){
      movePCHelper(pc,out,r+1,c,r,c);
      out << "PC moves South ";
    } else if (d == "sw"){
      movePCHelper(pc,out,r+1,c-1,r,c);
      out << "PC moves South West ";
    } else if (d == "we"){
      movePCHelper(pc,out,r,c-1,r,c);
      out << "PC moves West ";
    } else { //NW
      movePCHelper(pc,out,r-1,c-1,r,c);
      out << "PC moves North West ";
    }
  theFloor[r][c].notifyObservers(out);
}

void Floor::usePotionHelper(PlayerCharacter &pc, std::stringstream &out,
      int r, int c){
  if (theFloor[r][c].getEnumItem() == Items::None) { throw InvalidMove(); }
  theFloor[r][c].getItem()->passEffect(pc);
  theFloor[r][c].setItem(nullptr, Items::None);
  theFloor[r][c].notifyObservers(out);
}

void Floor::usePotion(PlayerCharacter &pc, std::string d, 
  std::stringstream &out){
  int r = pc.getRow();
  int c = pc.getCol();
  if (d == "no"){
    usePotionHelper(pc, out, r-1, c);
  } else if (d == "ne"){
    usePotionHelper(pc, out, r-1, c+1);
  } else if (d == "ea"){
    usePotionHelper(pc, out, r, c+1);
  } else if (d == "se"){
    usePotionHelper(pc, out, r+1, c+1);
  } else if (d == "so"){
    usePotionHelper(pc, out, r+1, c);
  } else if (d == "sw"){
    usePotionHelper(pc, out, r+1, c-1);
  } else if (d == "we"){
    usePotionHelper(pc, out, r, c-1);
  } else { //NW
    usePotionHelper(pc, out, r-1, c-1);
  }
  out << "PC uses Potion ";
}

bool Floor::validTypeE(Cell &c){
    return (c.getType()=='.');
}

// Moves all the enemies on the floor to one of its
// adjacent floor tile cells
// 1 = North, 2 = NEast, 3 = East , 4 = SEast, 5 = South, 6 = SWest,
// 7 = West, 8 = NEast
void Floor::moveEnemies(std::stringstream &out){
    for (auto &e: enemiesPtrs) {
      int r = e->getRow();
      int c = e->getCol();
      if (theFloor[r-1][c-1].getOccupant() == "PlayerCharacter" 
      || theFloor[r-1][c].getOccupant() == "PlayerCharacter" ||
          theFloor[r][c+1].getOccupant() == "PlayerCharacter" 
          || theFloor[r+1][c+1].getOccupant() == "PlayerCharacter" ||
          theFloor[r+1][c].getOccupant() == "PlayerCharacter" 
          || theFloor[r+1][c-1].getOccupant() == "PlayerCharacter" ||
          theFloor[r][c-1].getOccupant() == "PlayerCharacter" 
          || theFloor[r-1][c+1].getOccupant() == "PlayerCharacter"){
        theFloor[r][c].notifyObservers(out);
        break;
      }
      while(true){ //we want to generate the dir until it is a valid one
        int dir = rand() % 8 + 1;

        if(dir == 1 && validTypeE(theFloor[r-1][c]) && 
        !theFloor[r-1][c].isOccupied()){ //if dir is NO
          theFloor[r-1][c].setCharacter("Enemy", e.get());
          theFloor[r][c].leaveOccupant();
          theFloor[r-1][c].notifyObservers(out);
          e->setRow(r-1);
          break;
        } else if(dir == 2 && validTypeE(theFloor[r+1][c-1]) && 
        !theFloor[r+1][c-1].isOccupied()){ //if dir is NE
          theFloor[r+1][c-1].setCharacter("Enemy", e.get());
          theFloor[r][c].leaveOccupant();
          theFloor[r+1][c-1].notifyObservers(out);
          e->setRow(r+1); 
          e->setCol(c-1); 
          break;
        } else if(dir == 3 && validTypeE(theFloor[r][c+1]) && 
        !theFloor[r][c+1].isOccupied()){ //if dir is east
          theFloor[r][c+1].setCharacter("Enemy", e.get());
          theFloor[r][c].leaveOccupant();
          theFloor[r][c+1].notifyObservers(out); 
          e->setCol(c+1); 
          break;
        } else if(dir == 4 && validTypeE(theFloor[r+1][c+1]) && 
        !theFloor[r+1][c+1].isOccupied()){ //if dir is SE
          theFloor[r+1][c+1].setCharacter("Enemy", e.get());
          theFloor[r][c].leaveOccupant();
          theFloor[r+1][c+1].notifyObservers(out);
          e->setRow(r+1); 
          e->setCol(c+1); 
          break;
        } else if(dir == 5 && validTypeE(theFloor[r+1][c]) && 
        !theFloor[r+1][c].isOccupied()){ //if dir is SO
          theFloor[r+1][c].setCharacter("Enemy", e.get());
          theFloor[r][c].leaveOccupant();
          theFloor[r+1][c].notifyObservers(out);
          e->setRow(r+1); 
          break;
        } else if(dir == 6 && validTypeE(theFloor[r+1][c-1]) && 
        !theFloor[r+1][c-1].isOccupied()){ //if dir is SW
          theFloor[r+1][c-1].setCharacter("Enemy", e.get());
          theFloor[r][c].leaveOccupant();
          theFloor[r+1][c-1].notifyObservers(out);
          e->setRow(r+1); 
          e->setCol(c-1); 
          break;
        } else if(dir == 7 && validTypeE(theFloor[r][c-1]) && 
        !theFloor[r][c-1].isOccupied()){ //if dir is WE
          theFloor[r][c-1].setCharacter("Enemy", e.get());
          theFloor[r][c].leaveOccupant();
          theFloor[r][c-1].notifyObservers(out);
          e->setCol(c-1); 
          break;
        } else {
            if(validTypeE(theFloor[r-1][c-1]) && 
            !theFloor[r-1][c-1].isOccupied()){ //if dir is NW
              theFloor[r-1][c-1].setCharacter("Enemy", e.get());
              theFloor[r][c].leaveOccupant();
              theFloor[r-1][c-1].notifyObservers(out);
              e->setRow(r-1); 
              e->setCol(c-1); 
              break;
            }
        }

      }
      theFloor[r][c].notifyObservers(out);
    }
}


std::ostream &operator<<(std::ostream &out, const Floor &f){
  out << *(f.td); // TODO: fix later
  return out;
}
