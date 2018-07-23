/* Determinació del màxim comú divisor de dos naturals més grans que zero utilitzant el mètode d'Euclides. */

// Entrada: llegeix dos naturals num1,num2>0
// Sortida: escriu mcd(num1,num2)

#include <iostream>
using namespace std;

int main() {
    
    // Entrada
    unsigned num1, num2;
    cout<<"Entra 2 naturals (>0): ";
    cin>>num1>>num2;
    
    // Càlcul
    unsigned dividend = num1;
    unsigned divisor = num2;
    unsigned residu = dividend%divisor;
    while (residu!=0) {
        dividend = divisor;
        divisor = residu;
        residu = dividend%divisor;
    }
    
    // Sortida
    cout<<"MCD = "<<divisor<<endl;
    
    return 0;
}