// Entrada: llegeix un natural (nombre)
// Sortida: mostra els 5 darrers dígits del natural nombre, si té menys de 5 dígits mostra 0’s
#include<iostream>
using namespace std;

int main() {
    unsigned nombre;
    cout<<"Introdueix un nombre:"<<endl;
    cin>>nombre;
    unsigned aux=nombre;
    unsigned unitats=aux%10; //extraiem el darrer dígit de nombre
    aux=aux/10; //eliminem el darrer dígit de nombre
    //repetim el mateix procés 4 vegades més
    unsigned desenes=aux%10;
    aux=aux/10;
    unsigned centenes=aux%10;
    aux=aux/10;
    unsigned unitats_de_mil=aux%10;
    aux=aux/10;
    unsigned desenes_de_mil=aux%10;
    cout<<"Els digits de "<<nombre<<" son "<<desenes_de_mil<<" "
       <<unitats_de_mil<<" "<<centenes<<" "<<desenes<<" "<<unitats<<endl;
    return 0;
}
