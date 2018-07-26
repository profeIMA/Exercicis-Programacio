/*
 5.2. Retorna posició d'un element en un vector
 (si no trobat, -1)
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

int posicio_element(const Vector_enter vec, unsigned n, unsigned x) {
    //Pre: 0<=n<=N_MAX
    //Post: si x existeix a vec[0..n-1] retorna la seva posició més petita, altrament -1
    int pos=-1;
    unsigned i=0;
    bool trobat=false;
    while (i<n and not trobat) // not (i=n or trobat)
        if (vec[i]==x) trobat=true;
        else i++;
    if (trobat) pos=i;
    return pos;
}

int main() {
    Vector_enter vec; unsigned n;
    cout<<"Nombre d’elements i elements del vector: "<<endl;
    cin>>n;
    llegir_vector_enter(vec,n);
    int valor;
    cout<<"Entra el valor a cercar: ";
    cin>>valor;
    int pos=posicio_element(vec,n,valor);
    if (pos!=-1) cout<<"La posició de "<<valor<<" és "<<pos+1<<endl;
    else cout<<"El "<<valor<<" no hi és!"<<endl;
}
