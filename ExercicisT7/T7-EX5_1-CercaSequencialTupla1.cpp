/*
 5.1. Calcular l'existència o no d'un producte en un vector.
 (Versió amb trobat)
 */
#include <iostream>
using namespace std;

const unsigned N_MAX=100;
struct Producte {
    unsigned codi;
    double preu;
};
typedef Producte Vector_producte[N_MAX];

void llegir_vector_producte(Vector_producte vec, unsigned n) {
    //Pre: 0<=n<=N_MAX
    //Post: vec[0..n-1] conté successivament els productes entrats
    for (unsigned i=0; i<n; i++) {
        cin>>vec[i].codi;
        cin>>vec[i].preu;
    }
}

bool existeix_codi(const Vector_producte vec, unsigned n, unsigned codi_producte) {
    //Pre: 0<n<=N_MAX
    //Post: retorna cert si codi_producte existeix a vec[0..n-1], altrament fals
    unsigned i=0;
    bool trobat=false;
    while (i<n and not trobat) // not (i=n or trobat)
        if (vec[i].codi==codi_producte) trobat=true;
        else i++;
    return trobat;
}

int main() {
    Vector_producte vec; unsigned n;
    cout<<"Nombre d’elements i elements (codi preu) del vector: "<<endl;
    cin>>n;
    llegir_vector_producte(vec,n);
    unsigned codi_producte;
    cout<<"Entra el codi a cercar: ";
    cin>>codi_producte;
    bool hi_es=existeix_codi(vec,n,codi_producte);
    cout<<"El "<<codi_producte<<" és al vector de productes? "<<boolalpha<<hi_es<<endl;
}

