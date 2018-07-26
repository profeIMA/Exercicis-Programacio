/*
 6.3. Ordenació per inserció directa.
 */
#include <iostream>
using namespace std;

const unsigned N_MAX=100;
typedef int Vector_enter[N_MAX];

void llegir_vector_enter(Vector_enter vec, unsigned n) {
    //Pre: 0<=n<=N_MAX
    //Post: vec[0..n-1] conté successivament els enters entrats
    for (unsigned i=0; i<n; i++) cin>>vec[i];
}

void insercio_des_de(Vector_enter vec, int pos) {
    //Pre: 0<=n<=N_MAX i 0<pos<n i vec[0..pos-1] està ordenat i vec=VEC
    //Post: vec[0..pos] està ordenat i és una permutació de VEC[0..pos]
    int x=vec[pos];
    int j=pos-1;
    while (j>=0 and x<vec[j]) { //curtcircuit
        vec[j+1]=vec[j];
        j--;
    }
    vec[j+1]=x;
}

void ordenacio_insercio_directa(Vector_enter vec, unsigned n) {
    //Pre: 0<n<=N_MAX i vec=VEC
    //Post: vec[0..n-1] conté una permutació ordenada dels valors de VEC[0..n-1]
    for (unsigned i=1; i<n; i++) insercio_des_de(vec,i);
}

void escriure_vector_enter(const Vector_enter vec, unsigned n) {
    //Pre: 0<=n<=N_MAX
    //Post: s'han mostrat el n valors de vec[0..n-1]
    for (unsigned i=0; i<n; i++) cout<<vec[i]<<" ";
}

int main() {
    
    Vector_enter vec;
    int n;
    cout<<"Nombre elements del vector (>0): ";
    cin>>n;
    
    cout<<"Entra "<<n<<" enters: ";
    llegir_vector_enter(vec,n);
    
    ordenacio_insercio_directa(vec,n);
    
    cout<<"Vector ordenat: ";
    escriure_vector_enter(vec,n);
    cout<<endl;
    
    return 0;
}

