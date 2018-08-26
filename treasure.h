#ifndef CC3K_FINAL_PROJECT_TREASURE_H
#define CC3K_FINAL_PROJECT_TREASURE_H


#include "item.h"

class Treasure: public Item {
public:
    explicit Treasure(int amt): Item{amt} {};
};

#endif //CC3K_FINAL_PROJECT_TREASURE_H
