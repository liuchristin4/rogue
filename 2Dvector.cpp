#include <vector>
#include <iostream>

using namespace std;

int main(){
    vector< vector<int> > intarray;
    vector<int> row;
    for (int a = 0; a < 5; ++a){
        intarray.emplace_back(row);
        for (int b = 0 ;b < 5; ++b){
            intarray[a].emplace_back(1);
            cout << intarray[a][b];
        }
        cout << endl;
    }
}