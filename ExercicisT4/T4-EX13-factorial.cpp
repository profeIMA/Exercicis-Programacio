/* Calcular el factorial d'un nombre natural n. S'entra n i s'obté el resultat del factorial. Per exemple:  4! = 24 */

// Entrada: llegeix natural n
// Sortida: escriu escriu el factorial de n

#include <iostream>
using namespace std;

int main() {
    
    // Entrada
    unsigned n;
    cout<<"Entra n: ";
    cin>>n;
    
    // Càlcul
    unsigned factorial=1;
    for (unsigned i=1; i<=n; i++) factorial*=i;
    
    // Sortida
    cout<<n<<"! = "<<factorial<<endl;
    
    return 0;
}
