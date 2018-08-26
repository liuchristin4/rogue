#ifndef CC3K_FINAL_PROJECT_OBSERVER_H
#define CC3K_FINAL_PROJECT_OBSERVER_H
#include <sstream>

class Subject;
class Cell;

class Observer {
    
public:
    virtual void notify(Cell &whoNotified, std::stringstream &out) = 0;
    virtual void notify(Subject &whoFrom, std::stringstream &out){ 
        (void)&whoFrom;
        (void)out;
    };
};

#endif //CC3K_FINAL_PROJECT_OBSERVER_H
