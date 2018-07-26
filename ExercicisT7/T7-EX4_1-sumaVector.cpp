/*
 
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
//
//void escriure_vector_enter(const Vector_enter vec_enter, unsigned n) {
//    //Pre: 0<=n<=N_MAX
//    //Post: s'han mostrat el n valors de vec_enter[0..n-1]
//    for(unsigned i=0; i<n; i++) cout<<vec_enter[i]<<" ";
//}

void escriure_vector_enter(const int vec_enter[], unsigned n) {
    //Pre: 0<=n<=N_MAX
    //Post: s'han mostrat el n valors de vec_enter[0..n-1]
    for(unsigned i=0; i<n; i++) cout<<vec_enter[i]<<" ";
}

//int suma(const Vector_enter vec_enter, unsigned n) {
//    //Pre: 0<=n<=N_MAX
//    //Post: retorna suma de vec_enter[0..n-1]
//    int suma=0;
//    for(unsigned i=0; i<n; i++) suma+=vec_enter[i];
//    return suma;
//}

int suma(const int vec[], unsigned n) {
    //Pre: 0<=n<=N_MAX
    //Post: retorna suma de vec[0..n-1]
    int suma=0;
    for(unsigned i=0; i<n; i++) suma+=vec[i];
    return suma;
}

int main() {
    
    Vector_enter vec;
    int n;
    cout<<"Nombre elements del vector: ";
    cin>>n;
    
    cout<<"Entra "<<n<<" enters: ";
    llegir_vector_enter(vec,n);
    cout<<endl;
    
    cout<<"Suma vector= "<<suma(vec,n)<<endl;
    
    return 0;
}
