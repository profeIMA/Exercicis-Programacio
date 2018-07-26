/*
 4.4. Obtenir el mínim de cada fila i el màxim de cada columna d'una matriu. Indicar què caldria fer si es volgués guardar també la posició on apareixen.
 */
#include <iostream>
#include<iomanip>
using namespace std;

const unsigned N_MAX=100, N_FIL_MAX=50, N_COL_MAX=100;
typedef int Vector_enter[N_MAX];
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

void minim_fila_matriu(const Matriu_enter mat_enter, unsigned n, unsigned m, Vector_enter vec_enter) {
    //Pre: 0<=n<=N_FIL_MAX, 0<=m<=N_COL_MAX
    //Post: vec_enter[0..n-1] conté el mínim de cada fila de mat_enter[0..n-1,0..m-1]
    for(unsigned i=0; i<n; i++) {
        int min=mat_enter[i][0];
        for(unsigned j=1; j<m; j++)
            if(mat_enter[i][j]<min) min=mat_enter[i][j];
        vec_enter[i]=min;
    }
}

void maxim_columna_matriu(const Matriu_enter mat_enter, unsigned n, unsigned m, Vector_enter vec_enter) {
    //Pre: 0<=n<=N_FIL_MAX, 0<=m<=N_COL_MAX
    //Post: vec_enter[0..m-1] conté el màxim de cada columna de mat_enter[0..n-1,0..m-1]
    for(unsigned j=0; j<m; j++) {
        int max=mat_enter[0][j];
        for(unsigned i=1; i<n; i++)
            if(mat_enter[i][j]>max) max=mat_enter[i][j];
        vec_enter[j]=max;
    }
}

void escriure_vector_enter(const Vector_enter vec_enter, unsigned n) {
    //Pre: 0<=n<=N_MAX
    //Post: s'han mostrat el n valors de vec_enter[0..n-1]
    for(unsigned i=0; i<n; i++) cout<<vec_enter[i]<<" ";
}

int main() {

    Matriu_enter mat;
    unsigned n,m;
    cout<<"Nombre files i columnes de la matriu: ";
    cin>>n>>m;
    
    cout<<"Entra "<<n<<" files de "<<m<<" enters: "<<endl;
    llegir_matriu_enter(mat,n,m);
    cout<<endl;
    
    Vector_enter vec_min, vec_max;
    minim_fila_matriu(mat,n,m,vec_min);
    maxim_columna_matriu(mat,n,m,vec_max);
    
    cout<<"Vector de mínims de cada fila: "<<endl;
    escriure_vector_enter(vec_min, n);
    cout<<endl;
    cout<<"Vector de màxims de cada columna: "<<endl;
    escriure_vector_enter(vec_max, m);
    cout<<endl;
    
    return 0;
}

