#include "Rectangle.h"
#include <cmath>

// Constructors
Rectangle::Rectangle() {
    a_origen = Punt2D(0,0); // ens el podríem estalviar
    a_base = 1;
    a_altura = 1;
}

Rectangle::Rectangle(Punt2D origen, double base, double altura) {
    a_origen = origen;
    a_base = base;
    a_altura = altura;
}

// Mètodes públics
double Rectangle::base() const {
    return a_base;
}

double Rectangle::altura() const {
    return a_altura;
}

Punt2D Rectangle::origen() const {
    return a_origen;
}

double Rectangle::area() const {
    return a_altura*a_base;
}

double Rectangle::perimetre() const {
    return 2*(a_base+a_altura);
}

Punt2D Rectangle::centre() const {
    return Punt2D(a_origen.coordenada_x()+a_base/2, a_origen.coordenada_y()+a_altura/2);
}

void Rectangle::mostrar() const {
    cout << "Origen: ";
    a_origen.mostrar();
    cout << "Base: " << a_base << " , Altura: " << a_altura << endl;
}
    
void Rectangle::mostrar_vertexs() const {
    Vector_punt2D_rectangle v_rec;
    vertexs(v_rec);  // equival a (*this).vertexs(v_rec);
    cout << "Vèrtexs: " << endl;
    for (int k = 0; k<NOMBRE_VERTEXS; k++)
        v_rec[k].mostrar(); // usem mètode mostrar de Punt2D
}

void Rectangle::interseccio(Rectangle r, Rectangle &inter, bool &hi_ha_inter) const {
    // Pre: --; Post: si hi ha intersecció entre actual i r, hi_ha_inter és cert i, en cas contrari, és fals; en el cas que hi hagi interseccció, inter és el rectangle interseccció
    hi_ha_inter = false;
    double xmin = fmax(a_origen.coordenada_x(), r.a_origen.coordenada_x());
    double xmax = fmin(a_origen.coordenada_x() + a_base, r.a_origen.coordenada_x() + r.a_base);
    if (xmax > xmin) {
        double ymin = fmax(a_origen.coordenada_y(), r.a_origen.coordenada_y());
        double ymax = fmin(a_origen.coordenada_y() + a_altura, r.a_origen.coordenada_y() + r.a_altura);
        if (ymax > ymin) {
            inter.a_origen = Punt2D(xmin,ymin);
            inter.a_base = xmax - xmin;
            inter.a_altura = ymax - ymin;
            hi_ha_inter = true;
        }
    }
}

void Rectangle::moure(double x, double y) {
    a_origen.moure(x,y); // invoquem mètode de Punt2D
}

void Rectangle::escalar_centre(double factor) {
    Punt2D punt = centre();   // invoquem mètode de Rectangle
    a_base *= factor;
    a_altura *= factor;
    a_origen = Punt2D(punt.coordenada_x()-a_base/2, punt.coordenada_y()-a_altura/2);
}

void Rectangle::escalar_origen(double factor) {
    a_base *= factor;
    a_altura *= factor;
}

// Mètodes privats
void Rectangle::vertexs(Vector_punt2D_rectangle v_rec) const {
    v_rec[0]= a_origen;
    v_rec[1]= Punt2D(a_origen.coordenada_x(), a_origen.coordenada_y()+a_altura);
    v_rec[2]= Punt2D(a_origen.coordenada_x()+a_base, a_origen.coordenada_y()+a_altura);
    v_rec[3]= Punt2D(a_origen.coordenada_x()+a_base, a_origen.coordenada_y());
}


