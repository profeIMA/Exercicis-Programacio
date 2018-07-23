// Entrada: llegeix dos nombres naturals (base, exponent) amb base>0
// Sortida: escriu base^exponent

#include <iostream>
using namespace std;

int main() {
    
    // Entrada
    unsigned base;
    cout<<"Entra base: ";
    cin>>base; // base>0
    
    unsigned exponent;
    cout<<"Entra exponent: ";
    cin>>exponent; // exponent>=0
    
    // Càlcul
    unsigned resultat=1;
    for (unsigned comptador=1; comptador<=exponent; comptador++)
        resultat=resultat*base;
    
    // Sortida
    cout<<base<<"^"<<exponent<<" = "<<resultat<<endl;
    
    return 0;
}
