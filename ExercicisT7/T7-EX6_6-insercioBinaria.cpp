/*
 6.6. Ordenació inserció binària.
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

int posicio_insercio_dicotomica(const Vector_enter vec, int n, int element) {
    //Pre: 1<n<N_MAX i vec[0..n-1] està ordenat
    //Post: retorna la posició d'inserció d'element a vec en el rang 0..n
    int esquerre=0, dret=n-1, mig=0;
    bool trobat=false;
    while (esquerre<=dret and not trobat) {
        mig=(esquerre+dret)/2;
        if(element==vec[mig]) trobat=true;
        else if(element<vec[mig]) dret=mig-1;
        else esquerre=mig+1;
    }
    int pos;
    if (trobat) pos=mig;
    else pos=esquerre;
    return pos;
}

void insercio_coneguda_posicio(Vector_enter vec, int darrer, int pos) {
    //Pre: 1<n<N_MAX i vec[0..n-1] està ordenat i vec=VEC i n=N i 0<pos<=n
    //Post: n=N+1, vec[0..n-1] està ordenat i és el resultat d'inserir element a VEC a la posició pos
    int element=vec[darrer];
    for (int i=darrer-1; i>=pos; i--) vec[i+1]=vec[i];
    vec[pos]=element;
}
void escriure_vector_enter(const Vector_enter vec, unsigned n) {
    //Pre: 0<=n<=N_MAX
    //Post: s'han mostrat el n valors de vec[0..n-1]
    for (unsigned i=0; i<n; i++) cout<<vec[i]<<" ";
}
void ordenacio_insercio_binaria(Vector_enter vec, int n) {
    //Pre: 0<n<=N_MAX i vec=VEC
    //Post: vec[0..n-1] conté una permutació ordenada dels valors de VEC[0..n-1]
    for (int i=1; i<n; i++) {
        int pos=posicio_insercio_dicotomica(vec,i,vec[i]);
        insercio_coneguda_posicio(vec,i,pos);
    }
}

int main() {
    
    Vector_enter vec;
    int n;
    cout<<"Nombre elements del vector (>0): ";
    cin>>n;
    
    cout<<"Entra "<<n<<" enters: ";
    llegir_vector_enter(vec,n);
    
    ordenacio_insercio_binaria(vec,n);
    
    cout<<"Vector ordenat: ";
    escriure_vector_enter(vec,n);
    cout<<endl;
    
    return 0;
}

