#include <iostream>
using namespace std;

int foo(const int &k) {
    cout << "foo ran" << endl;
    return 0;
}

int main(){
  int x = 15;
  int &xRef = x;
  foo(const_cast<const int &> (xRef));
} 