/*
 5.1. Calcular l'existència o no d'un element en un vector.
 (Versió amb trobat)
 */
#include <iostream>
using namespace std;

const unsigned MAX=100;
typedef int Vector_enter[MAX];

void llegir_vector_enter(Vector_enter vec, unsigned n) {
    //Pre: 0<=n<=MAX
    //Post: vec[0..n-1] conté successivament els enters entrats
    for(unsigned i=0; i<n; i++) cin>>vec[i];
}

//bool existeix(const Vector_enter vec, unsigned n, unsigned x) {
//    //Pre: 0<n<=N_MAX
//    //Post: retorna cert si x existeix a vec[0..n-1], altrament fals
//    unsigned i=0;
//    bool trobat=false;
//    while (i<n and not trobat) // not (i=n or trobat)
//        if(vec[i]==x) trobat=true;
//        else i++;
//    return trobat;
//}

bool existeix(const Vector_enter a, unsigned n, unsigned x) {
    //Pre: 0<n<=N_MAX
    //Post: retorna cert si x existeix a vec[0..n-1], altrament fals
    bool trobat;
    if (n==1) trobat = a[0]==x;
    else if (a[n-1]==x) trobat = true;
         else trobat = existeix(a,n-1,x);
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
    bool hi_es=existeix(vec,n,valor);
    cout<<"El "<<valor<<" és al vector? "<<boolalpha<<hi_es<<endl;
}




