// Entrada: llegeix un conjunt de nombres en forma de vector (vec)
// Sortida: escriu si el vec és capicua o no.

#include <iostream>

using namespace std;

typedef int Vector_enter[100];

void llegir_vector_enter(Vector_enter vec, unsigned n) {
    //Pre: 0<=n<=N_MAX
    //Post: vec[0..n-1] conté successivament els enters entrats
    for (unsigned i=0; i<n; i++) cin>>vec[i];
}

bool capicua(Vector_enter vec, unsigned n){
//Pre: n > 0
//Post: cert si vec és capicua, fals en cas contrari
    if (n < 2) return true;
    else if (vec[0] != vec[n-1]) return false;
    else {
        for (int i=1; i<n; i++) vec[i-1]=vec[i];
        capicua(vec, n-2);
    }
}

int main() {
    Vector_enter vec;
    unsigned n;
    cout<<"Nombre elements del vector: ";
    cin>>n;
    cout<<"Entra "<<n<<" enters: ";
    llegir_vector_enter(vec,n);
    cout<<endl;
    string text_variable = capicua(vec, n)? "es":"no es";
    cout << "El vector introduit "<<text_variable << " capicua.";
    return 0;
}
