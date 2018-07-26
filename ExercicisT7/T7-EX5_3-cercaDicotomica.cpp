/*
 5.3. Cerca dicotòmica
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

bool existeix_dicotomic(const Vector_enter vec, unsigned n, unsigned x) {
    //Pre: 0<n<=N_MAX i vec[0..n-1] ordenat creixentment
    //Post: retorna cert si x existeix a vec[0..n-1], altrament fals
    int esquerre=0, dret=n-1, mig;
    bool trobat=false;
    while (esquerre<=dret and not trobat) {
        mig=(esquerre+dret)/2;
        if(x==vec[mig]) trobat=true;
        else if(x<vec[mig]) dret=mig-1;
        else esquerre=mig+1;
    }
    return trobat;
}

int main() {
    Vector_enter vec; unsigned n;
    cout<<"Nombre d’elements i elements del vector ordenats de petit a gran: "<<endl;
    cin>>n;
    llegir_vector_enter(vec,n);
    int valor;
    cout<<"Entra el valor a cercar: ";
    cin>>valor;
    bool hi_es=existeix_dicotomic(vec,n,valor);
    cout<<"El "<<valor<<" és al vector? "<<boolalpha<<hi_es<<endl;
}

