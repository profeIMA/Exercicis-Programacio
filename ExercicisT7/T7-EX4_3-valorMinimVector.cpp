/*
 4.3. Trobar el valor mínim d'un vector i la seva  posició.
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

void escriure_vector_enter(const Vector_enter vec_enter, unsigned n) {
    //Pre: 0<=n<=N_MAX
    //Post: s'han mostrat el n valors de vec_enter[0..n-1]
    for(unsigned i=0; i<n; i++) cout<<vec_enter[i]<<" ";
}

int minim(const Vector_enter vec_enter, unsigned n) {
    //Pre: 0<n<=N_MAX
    //Post: retorna mínim de vec_enter[0..n-1]
    int min=vec_enter[0];
    for(unsigned i=1; i<n; i++) if(vec_enter[i]<min) min=vec_enter[i];
    return min;
}

int pos_minim(const Vector_enter vec_enter, unsigned n) {
    //Pre: 0<n<=N_MAX
    //Post: retorna la posició del mínim de vec_enter[0..n-1]
    int pos=0;
    for(unsigned i=1; i<n; i++) if(vec_enter[i]<vec_enter[pos]) pos=i;
    return pos;
}

int main() {
    
    Vector_enter vec;
    int n;
    cout<<"Nombre elements del vector (>0): ";
    cin>>n;
    
    cout<<"Entra "<<n<<" enters: ";
    llegir_vector_enter(vec,n);
    cout<<endl;
    
    cout<<"Vector entrat: "<<endl;
    escriure_vector_enter(vec,n);
    cout<<endl;
    
    cout<<"Mínim vector= "<<minim(vec,n)<<endl;
    cout<<"Posició mínim vector= "<<pos_minim(vec,n)+1<<endl;
    
    return 0;
}
