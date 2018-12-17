
#include "Figura_Geometrica.h"

const double PI=3.14159;

Figura_Geometrica::Figura_Geometrica(){

}

//Figura_Geometrica::~Figura_Geometrica(){
//No cal fer res, però hi posem la implementació per evitar que sigui un mètode abstracte i que per tant calgui impelemntar a totes les classes derivades
//}

bool Figura_Geometrica::te_menor_area(Figura_Geometrica *pf) const{
    //cout<<area()<<" < "<<pf->area()<<" ?"<<endl;
    return area()<pf->area();
}

// si es volgués mostar una part comuna com podria ser l'àrea
//void Figura_Geometrica::mostrar()const{
//    cout<<"  Area: "<<area()<<endl;
//}
