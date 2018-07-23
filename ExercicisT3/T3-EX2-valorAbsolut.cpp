// Entrada: llegeix un nombre enter (nombre)
// Sortida: escriu valor absolut de nombre

#include <iostream>
using namespace std;

typedef unsigned Natural;

int main(){
    int nombre;
    cout<<"Nombre enter: ";
    cin>>nombre;
    Natural valor_absolut;
    if (nombre>=0)
        valor_absolut=nombre;
    else
        valor_absolut=-nombre;
    cout<<"El valor absolut de "<<nombre<<" és "<<valor_absolut<<endl;
    return 0;
}