/* Escriure quadrats (n*n) de nombres com els següents (exemples amb n=4):
 
 1   2   3   4        1   1   1   1        1    2    3    4
 1   2   3   4        2   2   2   2        5    6    7    8
 1   2   3   4        3   3   3   3        9   10   11   12
 1   2   3   4        4   4   4   4       13   14   15   16
 
	S'entra n (natural >0) i s'obté el "dibuix" del quadrat.
 */

// Entrada: llegeix nombre natural mida
// Sortida: dibuixa el quadrat mida*mida (segons el dibuix de l'enunciat)

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    // Entrada
    unsigned mida;
    cout<<"Entra la mida del quadrat: ";
    cin>>mida;
    
    // Càlcul i sortida
    unsigned comptador=0;
    for (unsigned i=1; i<=mida; i++ ) {
        for (unsigned j=1; j<=mida; j++ ) {
            comptador++;
            cout<<setw(4)<<comptador;
        }
        cout<<endl;
    }
    
    return 0;
}