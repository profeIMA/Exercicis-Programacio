// Entrada: un vector ordenat de petit a gran vec, el nombre d'elements de vec (n) i l'element a inserir(x)
// Sortida: posició d'inserció de x a vec.

#include <iostream>

using namespace std;

typedef int Vector_enter[100];

void llegir_vector_enter(Vector_enter vec, unsigned n) {
//Pre: 0<=n<=N_MAX
//Post: vec[0..n-1] conté successivament els enters entrats
    for (unsigned i=0; i<n; i++) cin>>vec[i];
}

int i_posicio_insercio(const Vector_enter a, unsigned n, int x, int esq, int dre) {
//Pre: 0<n<=MAX i a[0..n-1] ordenat creixentment i 0<=esq<=dre+1<=n
//Post: retorna la posicio de a on s'hauria de inserir x
    int mig = (esq+dre)/2, pos;
    if(a[mig]<=x && a[mig+1]>x) pos = mig+1;
    else if(a[esq]>x) pos = esq;
    else if(a[dre]<x) pos = dre+1;
    else if(x<a[mig]) pos = i_posicio_insercio(a,n,x,esq,mig-1);
    else pos = i_posicio_insercio(a,n,x,mig+1,dre);
    return pos;
}
int posicio_insercio(const Vector_enter a, unsigned n, int x) {
//Pre: 0<n<=MAX i a[0..n-1] ordenat creixentment
//Post: retorna la posicio de a on s'hauria de inserir x
    return i_posicio_insercio(a,n,x,0,n-1);
}

int main() {
    Vector_enter vec;
    unsigned n;
    int x;
    cout<<"Nombre elements del vector: ";
    cin>>n;
    cout<<"Entra "<<n<<" enters ordenats de petit a gran: ";
    llegir_vector_enter(vec,n);
    cout<<endl;
    cout<<"Entre l'element a inserir: ";
    cin>>x;
    cout<< "La insercio seria a la posicio: "<<posicio_insercio(vec, n, x);


    return 0;
}
