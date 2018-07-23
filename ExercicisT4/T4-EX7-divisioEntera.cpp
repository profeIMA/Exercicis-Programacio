/* Divisió entera per restes successives. S'introdueixen el dividend (natural) i el divisor (natural més gran que 0) i s'obtenen el quocient i el residu de la divisió entera. No es poden utilitzar els operadors de divisió / i %. */

// Entrada: llegeix dos naturals: dividend i divisor (divisor>0)
// Sortida: escriu el quocient i el residu de la divisió entera entre dividend i divisor

#include <iostream>
using namespace std;

int main() {
    
    // Entrada
    unsigned dividend, divisor;
    cout<<"Entra dividend i divisor (>0): ";
    cin>>dividend>>divisor;
    
    // Càlcul
    unsigned quocient=0;
    unsigned residu=dividend;
    while (residu>=divisor) {
        quocient++;
        residu-=divisor;
    }
    
    // Sortida
    cout<<"Quocient = "<<quocient<<" i residu = "<<residu<<endl;
    
    return 0;
}
