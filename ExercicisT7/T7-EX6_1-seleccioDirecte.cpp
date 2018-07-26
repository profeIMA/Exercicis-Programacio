/*
 6.1.2. Ordenació per selecció directa.
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
void intercanvi(int& x, int& y) {
    int aux=x;
    x=y;
    y=aux;
}
int pos_minim_des_de(const Vector_enter vec, unsigned n, unsigned pos) {
    //Pre: 1<n<=N_MAX i 0<=pos<n
    //Post: retorna la posició del mínim de vec[pos..n-1]
    int pos_min=pos;
    for (unsigned i=pos+1; i<n; i++) if(vec[i]<vec[pos_min]) pos_min=i;
    return pos_min;
}
void ordenacio_seleccio_directa(Vector_enter vec, unsigned n) {
    //Pre: 0<n<=N_MAX i vec=VEC
    //Post: vec[0..n-1] conté una permutació ordenada dels valors de VEC[0..n-1]
    for (unsigned i=0; i<n-1; i++) {
        unsigned pos_min= pos_minim_des_de(vec,n,i);
        intercanvi(vec[i],vec[pos_min]);
    }
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
    
    ordenacio_seleccio_directa(vec,n);
    
    cout<<"Vector ordenat: ";
    escriure_vector_enter(vec,n);
    cout<<endl;
    
    return 0;
}
