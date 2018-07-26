/*
 4.6. Triangle de Pascal.
 */
#include <iostream>
#include<iomanip>
using namespace std;

const unsigned N_FIL_MAX=100, N_COL_MAX=100;
typedef int Matriu_enter[N_FIL_MAX][N_COL_MAX];

void omplir_matriu_pascal(Matriu_enter mat_enter, unsigned n) {
    //Pre: 0<=n<=N_FIL_MAX
    //Post: mat_enter[0..n-1,0..n-1] conté l n files del triangle de Pascal
    for(unsigned i=0; i<n; i++) {
        mat_enter[i][0]=1; mat_enter[i][i]=1;
    }
    for(unsigned i=2; i<n; i++) {
        for(unsigned j=1; j<i; j++)
            mat_enter[i][j]=mat_enter[i-1][j]+mat_enter[i-1][j-1];
    }
}

void escriure_triangle(const Matriu_enter mat_enter, unsigned n) {
    //Pre: 0<=n<=N_FIL_MAX
    //Post: s'han mostrat els valors del triangle esquerre de la diagonal principal de mat_enter[0..n-1,0..n-1]
    for(unsigned i=0; i<n; i++) {
        for(unsigned j=0; j<=i; j++)
            cout<<setw(5)<<mat_enter[i][j];
        cout<<endl;
    }
}

int main() {
    
    Matriu_enter mat;
    unsigned n;
    cout<<"Nombre de files del triangle de Pascal: ";
    cin>>n;
    
    omplir_matriu_pascal(mat,n);
    
    cout<<"Triangle de Pascal: "<<endl;
    escriure_triangle(mat,n);
    cout<<endl;
    
    return 0;
}


