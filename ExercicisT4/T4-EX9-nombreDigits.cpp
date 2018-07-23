/* Calcular el nombre de dígits d'un nombre natural. */

// Entrada: llegeix un natural num
// Sortida: escriu el nombre de dígits de num

#include <iostream>
using namespace std;

int main() {
    
    // Entrada
    unsigned num;
    cout<<"Entra un nombre natural: ";
    cin>>num;
    
    // Càlcul
    unsigned nombre_digits=1;
    unsigned num_aux=num;
    while (num_aux>=10) {
        nombre_digits++;
        num_aux=num_aux/10;
    }
    
    // Sortida
    cout<<"Nombre dígits de "<<num<<" = "<<nombre_digits<<endl;
    
    return 0;
}