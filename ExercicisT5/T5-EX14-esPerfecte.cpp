#include <iostream>
#include <cmath>
//Entrada: un natural (n) >1
//Sortida: diu si és o no potència d'un natural < que n

using namespace std;

unsigned suma_divisors(unsigned n){
//Pre: n>0
//Post: retorna la suma de tots els divisors d'n
    unsigned suma=0;
    unsigned arrel=sqrt(n);
    for(unsigned divisor=1;divisor<=arrel;divisor++)
        if(n%divisor==0) suma+=(divisor+n/divisor);
    if(n==arrel*arrel) suma-=arrel;
   // cout<<suma<<endl;
    return suma;
}

bool es_perfecte(unsigned n){
//Pre: cert
//Post: cert si n és igual a la suma dels divisors d'n < n
    return n==suma_divisors(n)-n;
}

int main()
{
    //Entrada
    cout << "Entra un natural>1:" << endl;
    unsigned n;
    cin>>n;
    //Sortida
    cout<<"És perfecte? "<<boolalpha<<es_perfecte(n)<<endl;
    return 0;
}
