//Entrada: Dos fitxers de nombres naturals ordenats creixentment
//Sortida: Crea un fitxer ordenat amb els nombres que apareixen en els dos fitxers (sense repeticions)
#include <iostream>
#include<fstream>
using namespace std;
const unsigned EOS=0;

bool conte_29_febrer(){
    unsigned dia, mes, any;
    bool trobat=false;
    cin>>dia;
    while(dia!=EOS and not trobat){
        cin>>mes>>any;
        if(dia==29 and mes==2) trobat=true;
        else cin>>dia;
    }
    return trobat;
}

int main(){
    cout<<"Entra la seqüència de dates acabada amb un 0: "<<endl;
    if(conte_29_febrer())cout<<"Conte un 29 de febrer"<<endl;
    else cout<<"No hi ha cap 29 de febrer "<<endl;
    return 0;
}
