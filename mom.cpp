#include <iostream>
using namespace std;

#include "grandma.cpp"

class Mom : public Grandma {
    //char c = 'm';
public:
    void virtual hi() override;
};

void Mom::hi(){
    cout << "hi" << endl;
}