/*
 4.7. Donat un vector de notes naturals positives entre 0 i 10, obtenir i mostrar el corresponent histograma que indicarà el nombre d'aparicions de cada nota.
 */
#include <iostream>
#include<iomanip>
using namespace std;

const unsigned N_MAX=100;
typedef unsigned Vector_natural[N_MAX];
typedef int Vector_histograma_notes[11];

void llegir_vector_notes(Vector_natural vec_natural, unsigned n) {
    //Pre: 0<=n<=N_MAX
    //Post: vec_natural[0..n-1] conté successivament els naturals entre 0 i 10 entrats
    for(unsigned i=0; i<n; i++) cin>>vec_natural[i];
}

void omplir_histograma_notes(const Vector_natural notes, unsigned n, Vector_histograma_notes hist) {
    //Pre: 0<=n<=N_MAX i elements de notes estan entre 0 i 10
    //Post: hist[0..10] és l'histograma de notes[0..n-1]
    for(unsigned i=0; i<=10; i++) hist[i]=0;
    for(unsigned i=0; i<n; i++) {
        unsigned nota=notes[i];
        hist[nota]++; // hist[notes[i]]++
    }
}

void escriure_histograma_notes(const Vector_histograma_notes hist) {
    //Pre: cert
    //Post: s'ha mostrat l'histograma de notes (format nota-freqüència)
    for(unsigned i=0; i<=10; i++) cout<<i<<" -- "<<hist[i]<<endl;
}

int main() {
    
    Vector_natural notes;
    int n;
    cout<<"Nombre notes: ";
    cin>>n;
    
    cout<<"Entra "<<n<<" notes: ";
    llegir_vector_notes(notes,n);
    cout<<endl;
    
    Vector_histograma_notes hist;
    omplir_histograma_notes(notes,n,hist);
    
    cout<<"Vector histograma: "<<endl;
    escriure_histograma_notes(hist);
    cout<<endl;
    
    return 0;
}

