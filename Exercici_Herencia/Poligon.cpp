#include "Poligon.h"

Poligon::Poligon()
{
    reserva_memoria(5);
    //ctor
}

Poligon::Poligon(unsigned n){
    reserva_memoria(n);;
}

void Poligon::reserva_memoria(unsigned n){
    a_n=n;
    a_t=new Punt2D[a_n];
}

Poligon::~Poligon()
{
    cout<<"Dtor poligon"<<endl;
    allibera();
}

Poligon::Poligon(const Poligon& other)
{
    cout<<"Ctr copia poligon"<<endl;
    //copy ctor
    copia(other);
}

Poligon& Poligon::operator=(const Poligon& rhs)
{
    cout<<" op = poligon"<<endl;
    if (this != &rhs){
      allibera();
      copia(rhs);

    }
    return *this;
}

void Poligon::allibera(){
    if(a_t) delete[] a_t;
}

void Poligon::copia(const Poligon &o){
    a_n=o.a_n;
    a_t=new Punt2D[a_n]; //creo una taula de punts2D (objectes normals, no punters)
    for(unsigned i =0; i<a_n; i++){
        a_t[i]=o.a_t[i];
    }
}


double Poligon::area()const{

    double valor_area=0;
    //caldria buscar la manera de calcular l'àrea del poligon usant algun mètode general per poligons qualsevols, per exemple triangulant-lo
    return valor_area;

}

void Poligon::mostra()const{
    cout<<"Poligon: "<<endl;
    cout<<"  Nombre de vertexs: "<<a_n<<endl;
    mostra_vertexs();
    //Figura_Geometrica::mostra();//si hi hagués part a mostrar comuna (l'àrea??)
}


void Poligon::mostra_vertexs() const{
    cout<<"  Vertexs: ";
    for(unsigned i=0; i<a_n-1;i++){
        a_t[i].mostra();
        cout<<", ";
    }
    a_t[a_n-1].mostra(); cout<<endl;
}

void Poligon::llegir(){
    llegir_vertexs();
}

void Poligon::llegir_vertexs(){
    cout<<a_n<<" vertexs: ";
    for(unsigned i=0; i<a_n; i++){
        a_t[i].llegir();
    }
}


