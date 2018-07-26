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

unsigned posicio_insercio(const Vector_enter vec, unsigned n, int element) {
    //Pre: 1<n<N_MAX i vec[0..n-1] està ordenat
    //Post: pos indica la posició d'inserció d'element a vec en el rang 0..n
    int j=n-1;
    while (j>=0 and element<vec[j]) { //curtcircuit
        j--;
    }
    return j+1;
}

void insercio_coneguda_posicio(Vector_enter vec, int& n, int element, unsigned pos) {
    //Pre: 1<n<N_MAX i vec[0..n-1] està ordenat i vec=VEC i n=N i 0<pos<=n
    //Post: n=N+1, vec[0..n-1] està ordenat i és el resultat d'inserir element a VEC a la posició pos
    for (int i=n-1; i>=pos; i--) vec[i+1]=vec[i];
    vec[pos]=element;
    n++;
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
    int valor;
    cout<<"Entra el valor que es vol inserir: ";
    cin>>valor;
    
    unsigned pos=posicio_insercio(vec,n,valor);
    cout<<"Posició d'inserció: "<<pos<<endl;
    insercio_coneguda_posicio(vec,n,valor,pos);
    
    cout<<"Vector ordenat: ";
    escriure_vector_enter(vec,n);
    cout<<endl;
    
    return 0;
}