/*
 4.9. Obtenir el resultat de multiplicar dues  matrius: A * B = C, on A té n files i m columnes i B té m files i p columnes.
 */
#include <iostream>
#include<iomanip>
using namespace std;

const unsigned N_FIL_MAX=100, N_COL_MAX=100;
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

void multiplicacio_matrius_enter(const Matriu_enter mat1, const Matriu_enter mat2, Matriu_enter mat3, unsigned n, unsigned m, unsigned p){
    //Pre: 0<=n,m,p<=N_FIL_MAX
    //Post: mat3[0..n-1,0..p-1] és la multiplicació de mat_1[0..n-1,0..m-1]*mat_2[0..m-1,0..p-1]
    for(unsigned i=0; i<n; i++) {
        for(unsigned k=0; k<p; k++) {
            int suma=0;
            for(unsigned j=0; j<m; j++) suma+=mat1[i][j]*mat2[j][k];
            mat3[i][k]=suma;
        }
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
    
    Matriu_enter mat1, mat2, mat3;
    unsigned n,m,p;
    cout<<"Nombre files i columnes de la primera matriu: ";
    cin>>n>>m;
    cout<<"Nombre columnes de la segona matriu: ";
    cin>>p;
    
    cout<<"Entra "<<n<<" files de "<<m<<" enters: "<<endl;
    llegir_matriu_enter(mat1,n,m);
    cout<<endl;
    cout<<"Entra "<<m<<" files de "<<p<<" enters: "<<endl;
    llegir_matriu_enter(mat2,m,p);
    cout<<endl;
    
    multiplicacio_matrius_enter(mat1,mat2,mat3,n,m,p);
    
    cout<<"Matriu resultant de la multiplicació: "<<endl;
    escriure_matriu_enter(mat3,n,p);
    cout<<endl;
    
    return 0;
}


