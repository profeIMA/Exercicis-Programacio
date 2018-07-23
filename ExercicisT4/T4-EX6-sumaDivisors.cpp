/* Sumar els divisors d'un nombre natural >=2, exclòs ell mateix. */

// Entrada: llegeix natural >
// Sortida: escriu la suma dels divisors de n, exclòs ell mateix

#include <iostream>
using namespace std;

int main() {
    
    // Entrada
    unsigned n;
    cout<<"Entra n: ";
    cin>>n;
    
    // Càlcul
    unsigned suma=0;
    for (unsigned i=1; i<=n/2; i++)
        if (n%i==0) suma=suma+i;
    
    // Sortida
    cout<<"Suma dels divisors de "<<n<<" = "<<suma<<endl;
    
    return 0;
}