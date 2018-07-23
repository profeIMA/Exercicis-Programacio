#include <iostream>
//Entrada: un natural (n) >1
//Sortida: diu si és o no potència d'un natural < que n

using namespace std;

bool es_primer(unsigned n){
//Pre: cert
//Post: cert si n és primer fals altrament
    bool primer=n==2;
    if(n>2){
        unsigned divisor=2;
        while(n%divisor!=0 and divisor*divisor<n) divisor++;
        primer=n%divisor!=0;
    }
    return primer;
}

int main()
{
    //Entrada
    cout << "Entra un natural>1:" << endl;
    unsigned n;
    cin>>n;
    //Càlcul
    unsigned candidat=n+1;
    while(not es_primer(candidat)) candidat++;
    //Sortida
    cout<<"Primer nombre primer > "<<n<<": "<<candidat<<endl;
    return 0;
}
