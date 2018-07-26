/*
 6.5. Inserció (ordenada) d'un element en un vector ordenat coneguda la posició.
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

void esborrat_coneguda_posicio(Vector_enter vec, unsigned& n, int pos) {
    //Pre: 0<n<=N_MAX i vec[0..n-1] està ordenat i vec=VEC i n=N i 0<=pos<n
    //Post: n=N-1, vec[0..n-1] està ordenat i conté els elements de VEC[0..N-1] excepte VEC[pos]
    for (int i=pos+1; i<n; i++) vec[i-1]=vec[i];
    n--;
}

void escriure_vector_enter(const Vector_enter vec, unsigned n) {
    //Pre: 0<=n<=N_MAX
    //Post: s'han mostrat el n valors de vec[0..n-1]
    for (unsigned i=0; i<n; i++) cout<<vec[i]<<" ";
}

int main() {
    
    Vector_enter vec;
    unsigned n;
    cout<<"Nombre elements del vector (>0): ";
    cin>>n;
    
    cout<<"Entra "<<n<<" enters ordenats: ";
    llegir_vector_enter(vec,n);
    int pos;
    cout<<"Entra la posició de l'element que vols esborrar en el rang 1.."<<n<<": ";
    cin>>pos;
    
    esborrat_coneguda_posicio(vec,n,pos-1);
    
    cout<<"Vector ordenat: ";
    escriure_vector_enter(vec,n);
    cout<<endl;
    
    return 0;
}
