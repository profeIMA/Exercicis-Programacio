/*

 */
#include <iostream>
#include<iomanip>
using namespace std;

const unsigned N_FIL_MAX=50, N_COL_MAX=100;
typedef int Matriu_enter[N_FIL_MAX][N_COL_MAX];

void llegir_matriu_enter(Matriu_enter mat_enter, unsigned n, unsigned m) {
    //Pre: 0<=n<=N_FIL_MAX, 0<=m<=N_COL_MAX
    //Post: mat_enter[0..n-1,0..m-1] conté successivament els enters entrats
    for(unsigned i=0; i<n; i++) {
        cout<<"Entra fila "<<i+1<<" : ";
        for(unsigned j=0; j<m; j++)
            cin>>mat_enter[i][j];
    }
}

void escriure_matriu_enter(const Matriu_enter mat_enter, unsigned n, unsigned m) {
    //Pre: 0<=n<=N_FIL_MAX, 0<=m<=N_COL_MAX
    //Post: s'han mostrat el n*m valors de mat_enter[0..n-1,0..m-1]
    for(unsigned i=0; i<n; i++) {
        for(unsigned j=0; j<m; j++)
            cout<<setw(5)<<mat_enter[i][j];
        cout<<endl;
    }
}

int main() {
      
    Matriu_enter mat_enter;
    unsigned n,m;
    cout<<"Nombre files i columnes de la matriu: ";
    cin>>n>>m;
    
    cout<<"Entra "<<n<<" files de "<<m<<" enters: "<<endl;
    llegir_matriu_enter(mat_enter,n,m);
    cout<<endl;
    
    cout<<"Matriu entrada: "<<endl;
    escriure_matriu_enter(mat_enter,n,m);
    cout<<endl;
    
    return 0;
}
