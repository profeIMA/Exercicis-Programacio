/*
 6.2. Inserció (ordenada) d'un element en un vector ordenat.
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

void insercio(Vector_enter vec, int& n, int element) {
    //Pre: 0<=n<N_MAX i vec[0..n-1] està ordenat i vec=VEC i n=N
    //Post: n=N+1, vec[0..n-1] està ordenat i és el resultat d'inserir element a VEC[0..N-1]
    int j=n-1;
    while (j>=0 and element<vec[j]) { //curtcircuit
        vec[j+1]=vec[j];
        j--;
    }
    vec[j+1]=element;
    n++;
}

void insercio_boolea(Vector_enter vec, int& n, int element) {
    //Pre: 0<=n<N_MAX i vec[0..n-1] està ordenat i vec=VEC i n=N
    //Post: n=N+1, vec[0..n-1] està ordenat i és el resultat d'inserir element a VEC[0..N-1]
    int j=n-1; bool trobat_lloc=false;
    while (j>=0 and not trobat_lloc) { //curtcircuit
        if (element<vec[j]) {
            vec[j+1]=vec[j];
            j--;
        }
        else trobat_lloc=true;
    }
    vec[j+1]=element;
    n++;
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
    
    cout<<"Entra "<<n<<" enters ordenats: ";
    llegir_vector_enter(vec,n);
    int valor;
    cout<<"Entra el valor que es vol inserir: ";
    cin>>valor;
    
    insercio(vec,n,valor);
    
    cout<<"Vector ordenat: ";
    escriure_vector_enter(vec,n);
    cout<<endl;
    
    return 0;
}
