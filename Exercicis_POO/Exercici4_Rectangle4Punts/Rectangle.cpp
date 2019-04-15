#include "Rectangle.h"

// Constructors
Rectangle::Rectangle() {//(0,0),(1,0),(1,1),(0,1)
    a = Punt2D(0,0); // ens el podríem estalviar
    b = Punt2D(1,0);
    c = Punt2D(1,1);
    d = Punt2D(0,1);
}

Rectangle::Rectangle(Punt2D origen, double base, double altura) {
    a = origen;
    b = Punt2D(origen.coordenada_x(), origen.coordenada_y()+altura);
    c = Punt2D(origen.coordenada_x()+base, origen.coordenada_y()+altura);
    d = Punt2D(origen.coordenada_x()+base, origen.coordenada_y());

}

// Mètodes públics
double Rectangle::base() const {
    return a.distancia(d);
}

double Rectangle::altura() const {
    return a.distancia(b);
}

Punt2D Rectangle::origen() const {
    return a;
}

double Rectangle::area() const {
    return altura()*base();
}

double Rectangle::perimetre() const {
    return 2*(base()+altura());
}

Punt2D Rectangle::centre() const {
    return Punt2D(a.coordenada_x()+base()/2, a.coordenada_y()+altura()/2);
}

void Rectangle::mostrar() const {
    cout << "Origen: ";
    a.mostrar();
    cout << "Base: " << base() << " , Altura: " << altura() << endl;
}
    
void Rectangle::mostrar_vertexs() const {
    Vector_punt2D_rectangle v_rec;
    vertexs(v_rec);  // equival a (*this).vertexs(v_rec);
    cout << "Vèrtexs: " << endl;
    for (int k = 0; k<NOMBRE_VERTEXS; k++)
        v_rec[k].mostrar(); // usem mètode mostrar de Punt2D
}

void Rectangle::moure(double x, double y) {
    a.moure(x,y); // invoquem mètode de Punt2D
    b.moure(x,y); // invoquem mètode de Punt2D
    c.moure(x,y); // invoquem mètode de Punt2D
    d.moure(x,y); // invoquem mètode de Punt2D
}

void Rectangle::escalar_centre(double factor) {
    Punt2D punt = centre();   // invoquem mètode de Rectangle
    double base = this->base()*factor;
    double altura = this->altura()*factor;
    a = Punt2D(punt.coordenada_x()-base/2, punt.coordenada_y()-altura/2);
    b = Punt2D(a.coordenada_x(), a.coordenada_y()+altura);
    c = Punt2D(a.coordenada_x()+base, a.coordenada_y()+altura);
    d = Punt2D(a.coordenada_x()+base, a.coordenada_y());
}

void Rectangle::escalar_origen(double factor) {
    double base = this->base();
    double altura = this->altura();
    b = Punt2D(b.coordenada_x(), b.coordenada_y()+altura);
    c = Punt2D(c.coordenada_x()+base, c.coordenada_y()+altura);
    d = Punt2D(d.coordenada_x()+base, d.coordenada_y());
}

// Mètodes privats
void Rectangle::vertexs(Vector_punt2D_rectangle v_rec) const {
    v_rec[0]= a;
    v_rec[1]= b;
    v_rec[2]= c;
    v_rec[3]= d;
}


