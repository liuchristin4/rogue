#ifndef CC3K_FINAL_PROJECT_SUBJECT_H
#define CC3K_FINAL_PROJECT_SUBJECT_H
#include <sstream>

#include <vector>

class Observer;

class Subject {
protected:
    std::vector<Observer *> observers;
public:
    virtual void notifyObservers(std::stringstream &out) = 0; // Notifies all neighbouring cells
    void attach(Observer *o); // Adds an observer to vector of observers

};

#endif //CC3K_FINAL_PROJECT_SUBJECT_H
