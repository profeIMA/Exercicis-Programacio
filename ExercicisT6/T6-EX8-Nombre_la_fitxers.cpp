//Entrada: una fitxer de caràcters
//Sortida: ens diu quantes vegades hiha una 'l' seguida d'una 'a'
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

unsigned nombre_aparicions_la(ifstream& fentrada){
//Pre: fentrada obert i vàlid
//Post: retorna el nombre d'aparicions d'una 'l' seguida a una 'a'
    unsigned comptador=0;
    char actual=fentrada.get();
    char anterior =' ';//evitar un fals 'l''a'
    while(not fentrada.eof()){//mentre no fi
        if(anterior=='l' and actual=='a') comptador++;
        anterior=actual;
        fentrada.get(actual);
    }
    return comptador;
}

int main(){
    cout<<"Entra el nom del fitxer: ";
    string nom_fitxer;
    cin>>nom_fitxer;
    ifstream fentrada(nom_fitxer.c_str());
    cout<<nom_fitxer<<" conté "<<nombre_aparicions_la(fentrada)<<" aparicions d'una l seguida d'una a"<<endl;
    return 0;
}
