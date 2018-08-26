#include <iostream>
#include <fstream>
using namespace std;

int main () {
  ifstream file;
  file.open("suite.txt");
  string s;
  while (file >> s) {
    cout << s << endl;
  }
}