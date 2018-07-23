/* Esbrinar si un nombre natural n més gran que 1 és perfecte (igual a la suma dels seus divisors, inclòs 1 i exclòs n). */

// Entrada: llegeix natural n
// Sortida: escriu si n és o no perfecte

#include <iostream>
using namespace std;

int main() {
    
    // Entrada
    unsigned n;
    cout<<"Entra n (>1): ";
    cin>>n;
    
    // Càlcul
    unsigned suma=0;
    for (unsigned i=1; i<=n/2; i++)
        if (n%i==0) suma=suma+i;
    
    // Sortida
    if (n==suma) cout<<"Sí ";
    else cout<<"No ";
    cout<<"és perfecte"<<endl;
    
    return 0;
}