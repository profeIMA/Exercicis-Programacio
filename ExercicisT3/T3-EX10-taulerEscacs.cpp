/* En un tauler d'escacs, cada quadre pot ser descrit per una lletra i un número, per exemple, g5. Escriure un algorisme en pseudocodi i un programa que, donada una parella lletra-número, determini de quin color és el quadre: negre o blanc? Preparar un joc de proves que permeti testejar les diverses branques. [Basat en R3.7 p115]
*/
// Entrada: llegeix lletra (lletra) i numero natural (num) que representa una casella d'un tauler d'escacs
// Sortida: escriu el color (color) corresponent a la casella lletra-num

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    char lletra;
    unsigned num;
    cout<<"Lletra-Número de la casella: ";
    cin>>lletra>>num;
    if (lletra=='a' or lletra=='c' or lletra=='e' or lletra=='g') {
        if (num%2==0) cout<<"Casella blanca"<<endl;
        else cout<<"Casella negra"<<endl;
    }
    else
        if (num%2!=0) cout<<"Casella blanca"<<endl;
        else cout<<"Casella negra"<<endl;

    return 0;
}