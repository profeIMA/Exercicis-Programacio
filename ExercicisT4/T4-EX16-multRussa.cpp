/* Multiplicació russa de 2 nombres naturals. Veure, per exemple, Viquipèdia: multiplicació per duplicació.  */

// Entrada: llegeix dos naturals num1,num2>0
// Sortida: escriu num1*num2
// Restricció: podem usar la suma i les multiplicacions i divisions per 2

#include <iostream>
using namespace std;

int main() {
    
    // Entrada
    unsigned num1, num2;
    cout<<"Entra 2 naturals: ";
    cin>>num1>>num2;
    
    // Càlcul
    unsigned multiplicand=num1;
    unsigned multiplicador=num2;
    unsigned resultat=0;
    while (multiplicador>0) {
        if (multiplicador%2!=0) resultat+=multiplicand;
        multiplicand*=2;
        multiplicador/=2;
    }
    
    // Sortida
    cout<<num1<<" * "<<num2<<" = "<<resultat<<endl;
    
    return 0;
}
