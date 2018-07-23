// Entrada: llegeix un nombre enter (nombre)
// Sortida: escriu valor absolut de nombre

#include <iostream>
using namespace std;

typedef unsigned Natural;

int main(){
    Natural any;
    cout<<"Any julià: ";
    cin>>any;
    if ((any % 400==0) or (any % 4==0 and any % 100!=0))
        cout<<"L'any "<<any<<" és de traspàs"<<endl;
    else
        cout<<"L'any "<<any<<" no és de traspàs"<<endl;
    return 0;
}
