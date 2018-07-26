// Entrada: ...
// Sortida: ...

#include <iostream>
using namespace std;

const double IVA=4;

struct Factura {
    unsigned numero;
    double import;
    bool pagada;
};

Factura fer_factura(unsigned numero, double import_base) {
    // Pre: numero>0 i import_base>0
    // Post: crea factura nova no pagada amb el número indicat a partir de l'import_base i una constant d'IVA predefinida
    Factura factura;
    factura.numero=numero;
    factura.import=import_base*(1+IVA/100.0);
    factura.pagada=false;
    return factura;
}

void mostrar_factura(Factura factura) {
    // Pre: cert
    // Post: mostra dades factura
    cout<<factura.numero<<" -- "<<factura.import<<" -- "<<boolalpha<<factura.pagada<<endl;
}

int main(){
    double import_base;
    cout<<"Entrar import base: ";
    cin>>import_base;
    mostrar_factura(fer_factura(1,import_base));
    return 0;
}

