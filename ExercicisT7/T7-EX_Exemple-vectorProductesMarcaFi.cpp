/*
  Entrar vector de productes amb marca fi codi = -1
 */
#include <iostream>
using namespace std;

const unsigned N_MAX=100;
struct Producte {
    unsigned codi;
    double preu;
};
typedef Producte Vector_producte[N_MAX];

void llegir_vector_producte_amb_fi(Vector_producte vec, unsigned &n) {
    //Pre: cert
    //Post: 0<=n<=N_MAX i vec_producte[0..n-1] conté n productes entrats
    n=0;
    int codi;
    cin>>codi;
    while (codi>-1 and n<N_MAX) {
        vec[n].codi=codi;
        cin>>vec[n].preu;
        n++;
        cin>>codi;
    }
}

void escriure_vector_producte(const Vector_producte vec, unsigned n) {
    //Pre: 0<=n<=N_MAX
    //Post: s'han mostrat el n productes de vec_enter[0..n-1]
    for(unsigned i=0; i<n; i++) cout<<vec[i].codi<<" - "<<vec[i].preu<<endl;
}

int main() {
    
    Vector_producte vec;
    unsigned n;
    
    cout<<"Entra productes amb fi codi=-1: ";
    llegir_vector_producte_amb_fi(vec,n);
    cout<<endl;

    cout<<"Vector entrat: "<<endl;
    escriure_vector_producte(vec,n);
    cout<<endl;
    
    return 0;
}
