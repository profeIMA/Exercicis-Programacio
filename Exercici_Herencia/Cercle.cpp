#include <iostream>

#include "Cercle.h"

Cercle::Cercle()
{
    a_r=0;
}

double Cercle::area()const{
    return PI*a_r*a_r;
}

void Cercle::mostra() const{
    cout<<"Cercle:"<<endl;
    cout<<"  Radi = "<<a_r<<endl;
    cout<<"  Centre = "; a_centre.mostra();  cout<<endl;
    //Figura_Geometrica::mostra();//si hi hagués part a mostrar comuna (l'àrea??)
}

void Cercle::llegir(){
    cout<<"Radi: "; cin>>a_r;
    cout<<"Centre: "; a_centre.llegir();
}

