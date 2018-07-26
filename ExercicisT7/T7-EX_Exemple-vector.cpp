#include <iostream>
#include<iomanip>

using namespace std;const unsigned N_MAX=100;
typedef int Vector_enter[N_MAX];

int main() {
    // Entrada
    Vector_enter vector;
    unsigned n;
    cout<<"Nombre elements del vector: ";
    cin>>n;
    
    cout<<"Entra vector: ";
    for(unsigned i=0; i<n; i++) cin>>vector[i];
    
    // Sortida
    cout<<"Vector entrat: ";
    for(unsigned i=0; i<n; i++) cout<<setw(5)<<vector[i];
    cout<<endl;
    
    return 0;
}

