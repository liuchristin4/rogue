#ifndef _FLOOR_H_
#define _FLOOR_H_
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include "coordinate.h"
#include "cell.h"
#include "textdisplay.h"

class PlayerCharacter;
class Enemy;
//class Cell;
class Item;

//using namespace std;


class InvalidMove{};

class Floor{
    const int maxRows = 25;
    const int maxCols = 79;
    std::vector<std::pair<int,int>> taken;
    std::vector<std::shared_ptr<Enemy>> enemiesPtrs; //TODO I erased the 20!!!!
    std::unique_ptr<TextDisplay> td;
    int level = 1;
    bool validType(Cell &c);
    bool validTypeE(Cell &c);
    int genRandCoord(int &r, int &c);
    void movePCHelper(PlayerCharacter &pc, std::stringstream &out, 
          int r, int c, int ogR, int ogC);
    void usePotionHelper(PlayerCharacter &pc, std::stringstream &out,
      int r, int c);
protected:
    std::vector<std::vector<Cell>> theFloor;

public:
    ~Floor();
    void init(PlayerCharacter &pc, std::stringstream &out);
    void attackEnemy(PlayerCharacter &pc, std::string dir, std::stringstream &out);
    int getLevel();
    void nextLevel(PlayerCharacter &pc, std::stringstream &out);
    void movePC(PlayerCharacter &pc, std::string d, std::stringstream &out);
    void usePotion(PlayerCharacter &pc, std::string d, std::stringstream &out);
    void moveEnemies(std::stringstream &out);
    int spawnPC(PlayerCharacter &pc, std::stringstream &out);
    void spawnStairs(int PCchamber, std::stringstream &out);
    void spawnPotions(std::stringstream &out);
    void spawnTreasure(std::stringstream &out);
    void spawnEnemies(std::stringstream &out);

    friend std::istream &operator>>(std::istream &in, Floor &f);
    friend std::ostream &operator<<(std::ostream &out, const Floor &f);

};

#endif
