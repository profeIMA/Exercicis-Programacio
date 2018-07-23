/* Sumar els n (natural) nombres naturals (des de 1 a n) */

// Entrada: llegeix natural n
// Sortida: escriu la suma dels naturals des de 1 a n

#include <iostream>
using namespace std;

int main() {
    
    // Entrada
    unsigned n;
    cout<<"Entra n: ";
    cin>>n;
    
    // Càlcul
    unsigned suma=0;
    for (unsigned i=1; i<=n; i++) suma=suma+i;
    
    // Sortida
    cout<<"Suma= "<<suma<<endl;
    
    return 0;
}


