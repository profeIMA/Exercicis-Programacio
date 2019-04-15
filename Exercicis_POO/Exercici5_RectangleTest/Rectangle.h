#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Punt2D.h"

class Rectangle {
// Descripció: un rectangle 2D, alineat amb els eixos de coordenades

public:
// Constructors
    Rectangle();
    // Pre:--; Post: rectangle (0,0),(1,0),(1,1),(0,1)
    Rectangle(Punt2D origen, double base, double altura);
    // Pre: base,altura>0 ; Post: rectangle amb vertex_inferior_esquerre=origen i base i altura

// Consultors
    double base() const;
    // Pre: --; Post: retorna base del rectangle
    double altura() const;
    // Pre: --; Post: retorna altura del rectangle
    Punt2D origen() const;
    // Pre: --; Post: retorna el punt origen del rectangle
    double area() const;
    // Pre: --; Post: retorna àrea del rectangle
    double perimetre() const;
    // Pre: --; Post: retorna perímetre del rectangle
    Punt2D centre() const;
    // Pre: --; Post: retorna centre del rectangle
    void mostrar() const;
    // Pre: --; Post: mostra origen (vèrtex inferior esquerre) i base i altura
    void mostrar_vertexs() const;
    // Pre: --; Post: mostra els 4 vèrtexs en sentit horari, començant per inferior-esquerre

// Modificadors
    void moure(double x, double y);
    // Pre:--; Post: rectangle desplaçat segons vector (x,y)
    void escalar_origen(double factor);
    // Pre: factor>0; Post: rectangle escalat segons factor, mantenint el seu origen
    void escalar_centre(double factor);
    // Pre: factor>0; Post: rectangle escalat segons factor, mantenint el seu centre

private:
// Atributs
    Punt2D a_origen;     // composició, vèrtex inferior esquerra
    double a_base;
    double a_altura;

// Definicions
    static const int NOMBRE_VERTEXS=4;
    typedef Punt2D Vector_punt2D_rectangle[NOMBRE_VERTEXS];

// Mètodes privats
    void vertexs(Vector_punt2D_rectangle v_rec) const;
    // Pre: --; Post: v_rec conté els 4 vèrtexs en sentit horari començant per inferior-esquerre
};

#endif // RECTANGLE_H
