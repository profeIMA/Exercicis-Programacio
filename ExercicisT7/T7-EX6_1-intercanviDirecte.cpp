/*
 6.1.1. Ordenació per intercanvi directe.
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

void intercanvi(int& x, int& y) {
    int aux=x;
    x=y;
    y=aux;
}

void ordenacio_intercanvi_directe(Vector_enter vec, unsigned n) {
    //Pre: 0<n<=N_MAX i vec=VEC
    //Post: vec[0..n-1] conté una permutació ordenada dels valors de VEC[0..n-1]
    for(unsigned i=0; i<n-1; i++)
        for(unsigned j=n-1; j>i; j--)
            if (vec[j]<vec[j-1]) intercanvi(vec[j],vec[j-1]);
}

void escriure_vector_enter(const Vector_enter vec, unsigned n) {
    //Pre: 0<=n<=N_MAX
    //Post: s'han mostrat el n valors de vec[0..n-1]
    for(unsigned i=0; i<n; i++) cout<<vec[i]<<" ";
}

int main() {
    
    Vector_enter vec;
    int n;
    cout<<"Nombre elements del vector (>0): ";
    cin>>n;
    
    cout<<"Entra "<<n<<" enters: ";
    llegir_vector_enter(vec,n);
    
    ordenacio_intercanvi_directe(vec,n);
    
    cout<<"Vector ordenat: ";
    escriure_vector_enter(vec,n);
    cout<<endl;
    
    return 0;
}
