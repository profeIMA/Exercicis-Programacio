/*
 5.7. Cercar repetit en un vector
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

bool existeix_des_de(const Vector_enter vec, unsigned n, unsigned pos) {
    //Pre: 0<n<=N_MAX i 0<=pos<n-1
    //Post: retorna cert si vec[pos] existeix a vec[pos+1..n-1], altrament fals
    unsigned i=pos+1;
    bool trobat=false;
    while (i<n and not trobat) // not (i=n or trobat)
        if(vec[i]==vec[pos]) trobat=true;
        else i++;
    return trobat;
}

bool existeix_repetit(const Vector_enter vec, unsigned n) {
    //Pre: 0<n<=N_MAX
    //Post: retorna cert si hi ha un repetit a vec[0..n-1], altrament fals
    unsigned i=0;
    bool repetit=false;
    while (i<n-1 and not repetit) // not (i=n-1 or repetit)
        if(existeix_des_de(vec,n,i)) repetit=true;
        else i++;
    return repetit;
}

int main() {
    Vector_enter vec; unsigned n;
    cout<<"Nombre d’elements (>0) i elements del vector: "<<endl;
    cin>>n;
    llegir_vector_enter(vec,n);

    bool hi_es=existeix_repetit(vec,n);
    cout<<"Hi ha un repetit en el vector? "<<boolalpha<<hi_es<<endl;
}

