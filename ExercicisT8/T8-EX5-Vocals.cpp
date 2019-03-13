// Entrada: vector de caracters (vec) i longitud d'aquest(n)
// Sortida: retorna el nombre de vocals en vec[0..n-1]

#include <iostream>

using namespace std;

typedef char Vector_caracters[100];

void llegir_vector_caracters(Vector_caracters vec, unsigned n) {
//Pre: 0<=n<=N_MAX
//Post: vec[0..n-1] conté successivament els enters entrats
    for (unsigned i=0; i<n; i++) cin>>vec[i];
}

int num_vocals(Vector_caracters vec, unsigned n){
//Pre: cert
//Post: retorna el nombre de vocals en vec[0..n-1]
    if(n==0) return 0;
    else if(vec[n-1] == 'a' || vec[n-1] == 'e' || vec[n-1] == 'i' || vec[n-1] == 'o' || vec[n-1] == 'o')
        return 1 + num_vocals(vec, n-1);
    else return num_vocals(vec, n-1);
}

int main() {
    Vector_caracters vec;
    unsigned n;
    cout<<"Nombre elements del vector: ";
    cin>>n;
    cout<<"Entra "<<n<<" caracters: ";
    llegir_vector_caracters(vec,n);
    cout<<endl;
    cout<<"El vector introduit conte " << num_vocals(vec,n) << " vocals.";
    return 0;
}

