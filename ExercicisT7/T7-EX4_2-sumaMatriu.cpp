/*
 
 */
#include <iostream>
#include<iomanip>
using namespace std;

const unsigned N_FIL_MAX=50, N_COL_MAX=100;
typedef int Matriu_enter[N_FIL_MAX][N_COL_MAX];

void llegir_matriu_enter(int mat_enter[][N_COL_MAX], unsigned n, unsigned m) {
    //Pre: 0<=n<=N_FIL_MAX, 0<=m<=N_COL_MAX
    //Post: mat_enter[0..n-1,0..m-1] conté successivament els enters entrats
    for(unsigned i=0; i<n; i++) {
        cout<<"Entra fila "<<i+1<<" : ";
        for(unsigned j=0; j<m; j++)
            cin>>mat_enter[i][j];
    }
}

int suma(const int mat_enter[][N_COL_MAX], unsigned n, unsigned m) {
    //Pre: 0<=n<=N_FIL_MAX, 0<=m<=N_COL_MAX
    //Post: retorna suma de mat_enter[0..n-1,0..m-1]
    int suma=0;
    for(unsigned i=0; i<n; i++) {
        for(unsigned j=0; j<m; j++)
            suma+=mat_enter[i][j];
    }
    return suma;
}

int main() {
    
    Matriu_enter mat;
    unsigned n,m;
    cout<<"Nombre files i columnes de la matriu: ";
    cin>>n>>m;
    
    cout<<"Entra "<<n<<" files de "<<m<<" enters: "<<endl;
    llegir_matriu_enter(mat,n,m);
    cout<<endl;
    
    cout<<"Suma matriu= "<<suma(mat,n,m)<<endl;
    
    return 0;
}
