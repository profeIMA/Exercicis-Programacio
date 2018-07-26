/*
 1.2. Assignar a una matriu n*m els successius nombres naturals per files. Retocar l'algorisme perquè l'ordre d'assignació sigui per columnes per comptes de per files.
 */
#include <iostream>
#include<iomanip>
using namespace std;

const unsigned N_FIL_MAX=50, N_COL_MAX=100;
typedef int Matriu_enter[N_FIL_MAX][N_COL_MAX];

void assigna_matriu_enter(Matriu_enter mat_enter, unsigned n, unsigned m) {
    //Pre: 0<=n<=N_FIL_MAX, 0<=m<=N_COL_MAX
    //Post: mat_enter[0..n-1,0..m-1] conté successivament els naturals des de 0 a n*m-1
    unsigned comptador=0;
    for(unsigned i=0; i<n; i++)
        for(unsigned j=0; j<m; j++) {
            mat_enter[i][j]=comptador;
            comptador++;
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
    
    assigna_matriu_enter(mat_enter,n,m);
    cout<<endl;
    
    cout<<"Matriu obtinguda: "<<endl;
    escriure_matriu_enter(mat_enter,n,m);
    cout<<endl;
    
    return 0;
}

