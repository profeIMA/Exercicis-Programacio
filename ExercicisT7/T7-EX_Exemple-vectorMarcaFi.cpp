/*
 Entrar vector enter amb "marca fi = -1"
 
 */
#include <iostream>
using namespace std;

const unsigned N_MAX=100;
typedef int Vector_enter[N_MAX];

void llegir_vector_enter_amb_fi(Vector_enter vec, unsigned &n) {
    //Pre: cert
    //Post: 0<=n<=N_MAX i vec_enter[0..n-1] conté n valors entrats
    n=0;
    int element;
    cin>>element;
    while (element>-1 and n<N_MAX) {
        vec[n]=element;
        n++;
        cin>>element;
    }
}

void escriure_vector_enter(const Vector_enter vec_enter, unsigned n) {
    //Pre: 0<=n<=N_MAX
    //Post: s'han mostrat el n valors de vec_enter[0..n-1]
    for(unsigned i=0; i<n; i++) cout<<vec_enter[i]<<" ";
}

int main() {
    
    Vector_enter vec_enter;
    unsigned n;
    
    cout<<"Entra enters (fi amb -1): ";
    llegir_vector_enter_amb_fi(vec_enter,n);
    cout<<endl;
    cout<<n<<endl;
    cout<<"Vector entrat: "<<endl;
    escriure_vector_enter(vec_enter,n);
    cout<<endl;
    
    return 0;
}

