/* Donat un text acabat amb '.', comptar el nombre de caràcters 'a' */

// Entrada: llegeix una seqüència de caràcters acabada amb '.'
// Sortida: escriu el nombre de lletres 'a' (minúscula) que s'han trobat a la seqüència llegida

#include <iostream>
using namespace std;

int main() {
    
    // Entrada i càlcul
    unsigned quantitat_a=0;
    char caracter;
    cout<<"Entra una seqüència de caràcters acabada amb '.' : ";
    cin>>caracter;
    while (caracter!='.') {
        if (caracter=='a') quantitat_a++;
        cin>>caracter;
    }
    
    // Sortida
    cout<<"Nombre de lletres a = "<<quantitat_a<<endl;
    
    return 0;
}