/*
 5.5. Donat un vector d'enters, indicar si hi ha tres elements consecutius tals que la seva suma sigui més gran que una certa quantitat.
 */
#include <iostream>
using namespace std;

const unsigned N_MAX=100;
typedef int Vector_enter[N_MAX];

void llegir_vector_enter(Vector_enter vec, unsigned n) {
    //Pre: 0<=n<=N_MAX
    //Post: vec[0..n-1] conté successivament els enters entrats
    for(unsigned i=0; i<n; i++) cin>>vec[i];
}

bool hi_ha_tres_elements(const Vector_enter vec, unsigned n, int valor_suma) {
    //Pre: 0<=n<=N_MAX
    //Post: retorna cert si a vec[0..n-1] hi has 3 elements seguits que sumen més que valor_suma, altrament fals
    bool trobat=false;
    if (n>2) {
        unsigned i=0;
        while (i<n-2 and not trobat) // not (i=n-2 or trobat)
            if (vec[i]+vec[i+1]+vec[i+2]>valor_suma) trobat=true;
            else i++;
    }
    return trobat;
}

int main() {
    Vector_enter vec; unsigned n;
    cout<<"Nombre d’elements i elements del vector: "<<endl;
    cin>>n;
    llegir_vector_enter(vec,n);
    int valor;
    cout<<"Entra el valor de la suma: ";
    cin>>valor;
    cout<<"Hi ha 3 elements seguits que la seva suma > "<<valor<<" ? "<<boolalpha<<hi_ha_tres_elements(vec,n,valor)<<endl;
}





