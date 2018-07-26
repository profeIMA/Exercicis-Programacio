/*
 5.3. Cerca dicotòmica (amb posició)
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

int posicio_element_dicotomic(const Vector_enter vec, int n, unsigned x) {
    //Pre: 0<n<=N_MAX i vec[0..n-1] ordenat creixentment
    //Post: si x existeix a vec[0..n-1] retorna una de les seves posicions, altrament -1
    int esquerre=0, dret=n-1, pos=-1;
    bool trobat=false;
    while (esquerre<=dret and not trobat) {
        int mig=(esquerre+dret)/2;
        if(x==vec[mig]) {trobat=true; pos=mig;}
        else if(x<vec[mig]) dret=mig-1;
        else esquerre=mig+1;
    }
    return pos;
}

int main() {
    Vector_enter vec; unsigned n;
    cout<<"Nombre d’elements i elements del vector ordenats de petit a gran: "<<endl;
    cin>>n;
    llegir_vector_enter(vec,n);
    int valor;
    cout<<"Entra el valor a cercar: ";
    cin>>valor;
    int pos=posicio_element_dicotomic(vec,n,valor);
    if (pos!=-1) cout<<"La posició de "<<valor<<" és "<<pos+1<<endl;
    else cout<<"El "<<valor<<" no hi és!"<<endl;
}
