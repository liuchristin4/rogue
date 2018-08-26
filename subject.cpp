#include "subject.h"


// attaches o as a neighbour in observers
void Subject::attach(Observer *o) {
    observers.emplace_back(o);
}

// returns type of the subject (i.e. '/', '#', ...)

