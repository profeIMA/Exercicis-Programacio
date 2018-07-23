#include <iostream>
#include<iomanip>
//Entrada: un natural (n) >1
//Sortida: mostra un quadrat amb els cubs de 1 a n

using namespace std;

const unsigned COL_1=5;
const unsigned COL_2=11;

void mostrar_extrem(){
//Pre: cert
//Post: mostra la linia superior i inferior de la taula
    cout<<"+"<<setfill('-')<<setw(COL_1+1)<<"+"<<setw(COL_2+1)<<"+"<<setfill(' ')<<endl;
}

void mostrar_fila(unsigned n){
//Pre: cert
//Post: mostra la fila numero n de la taula (el valor d'n i el seu cub)
    cout<<"|"<<setw(COL_1)<<n<<"|"<<setw(COL_2)<<n*n*n<<"|"<<endl;
}



void mostrar_quadrat(unsigned n){
//Pre: n>0
//Post: mostra el quadrat dels n primers cubs
    mostrar_extrem();
    cout<<"|"<<setw(COL_1+1)<<"i|"<<setw(COL_2)<<"i^3"<<"|"<<endl;
    for(unsigned int num=1;num<=n;num++)
        mostrar_fila(num);
    mostrar_extrem();
}


int main(){
    //Entrada
    cout<<"nombre de files: "<<endl;
    unsigned n;
    cin>>n;
    //Sortida
    cout<<"Els "<<n<<"  primers cubs són: "<<endl;
    mostrar_quadrat(n);
}
