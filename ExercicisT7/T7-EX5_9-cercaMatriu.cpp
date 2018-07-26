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

void cerca_matriu(Matriu_enter mat, unsigned n, unsigned m, unsigned x, bool& trobat, unsigned& fila, unsigned& col) {
    //Pre: 0<=n<=N_FIL_MAX, 0<=m<=N_COL_MAX, mat està ordenada ((mat[i+1,j]>=mat[i,j] i mat[i,j+1]>=mat[i,j]))
    //Post: si x pertany a mat, trobat=cert i (fila,col) contenen la posició de x; altrament, trobat=fals i (fila,col) no tenen significat

    int i=n-1,j=0;
    trobat=false;
    while (i>=0 and j<=m-1 and not trobat) {
        if (mat[i][j]<x) j++;
        else
            if (mat[i][j]>x) i--;
            else {
                trobat=true;
                fila=i+1; col=j+1;
            }
    }
}

int main() {
    
    Matriu_enter mat;
    unsigned n,m;
    cout<<"Nombre files i columnes de la matriu: ";
    cin>>n>>m;
    
    cout<<"Entra "<<n<<" files de "<<m<<" enters: "<<endl;
    llegir_matriu_enter(mat,n,m); // s'omple una matriu ordenada
    cout<<endl;
    
    int valor;
    cout<<"Entra el valor a cercar: ";
    cin>>valor;
    
    unsigned fila,col;
    bool trobat;
    cerca_matriu(mat,n,m,valor,trobat,fila,col);
    if (trobat) cout<<"Trobat a ("<<fila<<","<<col<<")"<<endl;
    else cout<<"No trobat"<<endl;
    return 0;
}
