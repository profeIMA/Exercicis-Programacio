//Entrada: dos fitxers de caràcters
//Sortida: dir si els dos fitxers són o no iguals
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

bool son_iguals(ifstream& fitxer1, ifstream& fitxer2){
//Pre: fitxer1 i fitxer2 oberts i vàlids
//Post: retorna cert si fitxer1 i fitxer2 contenen exactament els mateixos caràcters, fals altr.
    bool iguals=true;
    char element_f1=fitxer1.get();
    char element_f2=fitxer2.get();
    //mentre no fi: no (final fitxer1 o final fitxer2)
    while(not fitxer1.eof()and not fitxer2.eof() and iguals){
        if(element_f1!=element_f2) iguals=false;
        else{
           element_f1=fitxer1.get();
           element_f2=fitxer2.get();
        }
    }
    if(fitxer1.eof()!=fitxer2.eof())iguals=false;
    return iguals;
}


bool son_iguals_v2(ifstream& fitxer1, ifstream& fitxer2){
//Pre: fitxer1 i fitxer2 oberts i vàlids
//Post: retorna cert si fitxer1 i fitxer2 contenen exactament els mateixos caràcters, fals altr.
    bool iguals=true;
    char element_f1=fitxer1.get(), element_f2=fitxer2.get();
    //menentre no fi: no (final fitxer1 o final fitxer2)
    while(not fitxer1.eof()and not fitxer2.eof() and element_f1==element_f2){
        element_f1=fitxer1.get();
        element_f2=fitxer2.get();
    }
    return (fitxer1.eof() and fitxer2.eof());
}

int main(){
    cout<<"Entra els noms del 2 fitxers: ";
    string nom_fitxer1, nom_fitxer2;
    cin>>nom_fitxer1>>nom_fitxer2;
    ifstream fentrada1(nom_fitxer1.c_str()), fentrada2(nom_fitxer2.c_str());
    cout<<"Són iguals? "<<boolalpha<<son_iguals_v2(fentrada1,fentrada2)<<endl;;
    return 0;
}
