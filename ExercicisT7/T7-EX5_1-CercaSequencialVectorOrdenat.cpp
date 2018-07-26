/*
 5.1. Calcular l'existència o no d'un element en un vector ordenat.
 (Versió amb acabat i trobat)
 */
#include <iostream>
using namespace std;

const unsigned N_MAX=100;
typedef int Vector_enter[N_MAX];

void llegir_vector_enter(Vector_enter vec, unsigned n) {
    //Pre: 0<=n<=N_MAX
    //Post: vec[0..n-1] conté successivament els enters entrats
    for(unsigned i=0; i<n; i++) cin>>vec[i];
}

bool existeix_vector_ordenat(const Vector_enter vec, unsigned n, unsigned x) {
    //Pre: 0<=n<=N_MAX
    //Post: retorna cert si x existeix a vec[0..n-1], altrament fals
    int i=0;
    bool acabat=false;
    while (not acabat and i<n) // not (acabat or i=n)
        if(vec[i]>=x) acabat=true;
        else i++;
    bool trobat=acabat and vec[i]==x; // curtcircuit
    return trobat;
}

int main() {
    Vector_enter vec; unsigned n;
    cout<<"Nombre d’elements i elements del vector: "<<endl;
    cin>>n;
    llegir_vector_enter(vec,n);
    int valor;
    cout<<"Entra el valor a cercar: ";
    cin>>valor;
    bool hi_es=existeix_vector_ordenat(vec,n,valor);
    cout<<"El "<<valor<<" és al vector? "<<boolalpha<<hi_es<<endl;
}

