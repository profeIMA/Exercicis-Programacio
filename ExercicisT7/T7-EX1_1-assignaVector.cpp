/* 	
 1.1. Assignar a un vector d'n elements els successius nombres naturals (0, 1, 2, 3, ...). Retocar l'algorisme per tal que assigni els successius nombres naturals parells (0, 2, 4, 6, ...).
 */
#include <iostream>
using namespace std;

const unsigned N_MAX=100;
typedef int Vector_enter[N_MAX];

void assignar_vector_enter(Vector_enter vec_enter, unsigned n) {
    //Pre: 0<=n<=N_MAX
    //Post: vec_enter[0..n-1] conté successivament els naturals des de 0 a n-1
    for(unsigned i=0; i<n; i++) vec_enter[i]=i;
}

void escriure_vector_enter(const Vector_enter vec_enter, unsigned n) {
    //Pre: 0<=n<=N_MAX
    //Post: s'han mostrat el n valors de vec_enter[0..n-1]
    for(unsigned i=0; i<n; i++) cout<<vec_enter[i]<<" ";
}

int main() {
    
    Vector_enter vec_enter;
    int n;
    cout<<"Nombre elements del vector: ";
    cin>>n;
    
    assignar_vector_enter(vec_enter,n);
    
    cout<<"Vector obtingut: "<<endl;
    escriure_vector_enter(vec_enter,n);
    cout<<endl;

    return 0;
}