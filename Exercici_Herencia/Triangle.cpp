#include "Triangle.h"
#include <cmath>

Triangle::Triangle():Poligon(3){
    //ctor
}
/*
Triangle::Triangle(const Triangle& other)Poligon(other)
{
    //copy ctor
}

Triangle& Triangle::operator=(const Triangle& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}*/


void Triangle::mostra()const {
    cout<<"Triangle: "<<endl;
    mostra_vertexs();
    //Figura_Geometrica::mostra(); //si hi hagués part a mostrar comuna (l'àrea??)
}

void Triangle::llegir(){
    llegir_vertexs();
}

double Triangle::area() const{
    double da=a_t[0].distancia(a_t[1]);
    double db=a_t[1].distancia(a_t[2]);
    double dc=a_t[0].distancia(a_t[2]);
    double s=(da+db+dc)/2;

    return sqrt(s*(s-da)*(s-db)*(s-dc));

}
