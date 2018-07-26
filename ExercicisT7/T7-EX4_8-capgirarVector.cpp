/*
 4.8. Capgirar vector.
 */
#include <iostream>
using namespace std;

const unsigned N_MAX=100;
typedef int Vector_enter[N_MAX];

void llegir_vector_enter(Vector_enter vec_enter, unsigned n) {
    //Pre: 0<=n<=N_MAX
    //Post: vec_enter[0..n-1] conté successivament els enters entrats
    for(unsigned i=0; i<n; i++) cin>>vec_enter[i];
}

void intercanvi(int& x, int& y) {
    int aux=x;
    x=y;
    y=aux;
}

void capgirar_vector_enter(Vector_enter vec_enter, unsigned n) {
    //Pre: 0<=n<=N_MAX i vec_enter=VEC_ENTER
    //Post: vec_enter[0..n-1] conté els valors de VEC_ENTER en ordre invers
    for(unsigned i=0; i<n/2; i++) {
        intercanvi(vec_enter[i],vec_enter[n-i-1]);
        // int aux=vec_enter[i];
        // vec_enter[i]=vec_enter[n-i-1];
        // vec_enter[n-i-1]=aux;
    }
}

void escriure_vector_enter(const Vector_enter vec_enter, unsigned n) {
    //Pre: 0<=n<=N_MAX
    //Post: s'han mostrat el n valors de vec_enter[0..n-1]
    for(unsigned i=0; i<n; i++) cout<<vec_enter[i]<<" ";
}

int main() {
    
    Vector_enter vec;
    int n;
    cout<<"Nombre elements del vector (>0): ";
    cin>>n;
    
    cout<<"Entra "<<n<<" enters: ";
    llegir_vector_enter(vec,n);
    cout<<endl;
    
    capgirar_vector_enter(vec,n);
    
    cout<<"Vector capgirat: "<<endl;
    escriure_vector_enter(vec,n);
    cout<<endl;
    
    return 0;
}
