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
    unsigned comptador=1;
    while (comptador<=exponent) {
        resultat=resultat*base;
        comptador++;
    }
    
    // Resultat
    cout<<base<<"^"<<exponent<<" = "<<resultat<<endl;
    
    return 0;
}
