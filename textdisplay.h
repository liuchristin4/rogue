#ifndef CC3K_FINAL_PROJECT_TEXTDISPLAY_H
#define CC3K_FINAL_PROJECT_TEXTDISPLAY_H

#include <iostream>
#include <vector>
#include <string>
#include "observer.h"

class Cell;


class TextDisplay: public Observer {
    int row = 25;
    int col = 79;
    std::vector<std::vector<char>> theDisplay;
public:
    TextDisplay();
    ~TextDisplay();
    void buildFloor(Cell &whoBuild);
    void notify(Cell &whoNotified, std::stringstream &out) override;
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};




#endif //CC3K_FINAL_PROJECT_TEXTDISPLAY_H
