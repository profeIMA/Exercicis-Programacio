/*
 7.2. Esborrar repetits en vector ordenat.
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

void esborrar_repetits(Vector_enter vec, unsigned& n) {
    //Pre: 0<n<=N_MAX i vec[0..n-1] està ordenat i vec=VEC i n=N
    //Post: vec[0..n-1] està ordenat i conté tots els elements de VEC[0..N-1] però sense repeticions
    unsigned pos_consolidada=0;
    for (int i=1; i<n; i++)
        if (vec[i]!=vec[pos_consolidada]) {
            pos_consolidada++;
            vec[pos_consolidada]=vec[i];
        }
    n=pos_consolidada+1;
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
    
    esborrar_repetits(vec,n);
    
    cout<<"Vector ordenat sense repetits: ";
    escriure_vector_enter(vec,n);
    cout<<endl;
    
    return 0;
}

