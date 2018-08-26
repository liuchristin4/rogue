#include <iostream>
using namespace std;

#include "mom.cpp"

class Baby: public Mom {
    //char c = 'b';
public:
    void virtual bye() override;
};

void Baby::bye(){
    cout << "bye" << endl;
}