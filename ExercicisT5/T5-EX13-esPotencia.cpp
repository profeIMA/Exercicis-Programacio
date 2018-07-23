#include <iostream>
//Entrada: un natural (n) >1
//Sortida: diu si és o no potència d'un natural < que n

using namespace std;

bool es_potencia_de(unsigned n, unsigned base){
//Pre: cert
//Post: cert si n és base elevat a un natural, fals altrament
    unsigned resultat=1;
    while(resultat<n) resultat*=base;

    return resultat==n;
}

int main()
{
    //Entrada
    cout << "Entra un natural>1:" << endl;
    unsigned n;
    cin>>n;
    //Càlcul
    unsigned base=2;
    bool es_potencia=false;
    while(not es_potencia and base*base<=n){
        es_potencia=es_potencia_de(n,base);
        base++;
    }
    //Sortida
    cout<<"És una potència? "<<boolalpha<<es_potencia<<endl;
    return 0;
}
