#include <iostream>
#include <fstream>
using namespace std;

int main () {
    ifstream file;
    file.open("floor.txt");
    char s;
    while (file.get(s)) {
        if (s == '\n') {
            cout << endl;
        } else {
            cout << s;
        }
    }
}