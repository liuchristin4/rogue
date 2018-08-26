#ifndef CC3K_FINAL_PROJECT_POTION_H
#define CC3K_FINAL_PROJECT_POTION_H

#include "item.h"

class Potion: public Item {
public:
    explicit Potion(int amt): Item{amt} {};
};





#endif //CC3K_FINAL_PROJECT_POTION_H
