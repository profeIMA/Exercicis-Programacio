#include <iostream>
#include<iomanip>
using namespace std;

const unsigned N_FIL_MAX=50, N_COL_MAX=100;
typedef int Matriu_enter[N_FIL_MAX][N_COL_MAX];

int main() {
    // Entrada
    Matriu_enter matriu;
    unsigned n,m;
    cout<<"Nombre files i columnes de la matriu: ";
    cin>>n>>m;
    for(unsigned i=0; i<n; i++) {
        cout<<"Entra fila "<<i+1<<" : ";
        for(unsigned j=0; j<m; j++)
            cin>>matriu[i][j];
        }
    // Sortida
    cout<<endl<<"Matriu entrada: "<<endl;
    for(unsigned i=0; i<n; i++) {
        for(unsigned j=0; j<m; j++)
            cout<<setw(5)<<matriu[i][j];
        cout<<endl;
    }
    cout<<endl;
    return 0;
}

