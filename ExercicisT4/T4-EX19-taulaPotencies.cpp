#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
    
    const unsigned EXP_MAX = 4;
    const unsigned X_MAX = 10;
    
    for (unsigned exp = 1; exp <= EXP_MAX; exp++) {
        cout << setw(10) << exp;
    }
    cout << endl;
    
    for (unsigned exp = 1; exp <= EXP_MAX; exp++) {
        cout << setw(10) << "x ";
    }
    cout << endl << endl;
    
    for (int x = 1; x <= X_MAX; x++) {
        for (unsigned exp = 1; exp <= EXP_MAX; exp++)
            cout << setw(10) << pow(x, exp);
        cout << endl;
    }
    cout << endl;
    
    return 0;
}
