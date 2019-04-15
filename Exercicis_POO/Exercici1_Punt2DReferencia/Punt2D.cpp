#include <iostream>
#include <cmath>
#include "Punt2D.h"
using namespace std;

// Constructors

  Punt2D::Punt2D() {
    a_x=0;
    a_y=0;
  }

  Punt2D::Punt2D(double x, double y) {
    a_x=x;
    a_y=y;
  }

// Consultors

  double Punt2D::coordenada_x() const {
    return a_x;
  }

  double Punt2D::coordenada_y() const {
    return a_y;
  }

  double Punt2D::distancia(Punt2D p) const {
    double difX = a_x-p.a_x;
    double difY = a_y-p.a_y;
    return sqrt(difX*difX+difY*difY);
  }

  void Punt2D::mostrar() const {
    cout << "(" << a_x << "," << a_y << ")" << endl;
  }

  bool Punt2D::es_igual(Punt2D p) const {
    return a_x == p.a_x and a_y == p.a_y;
  }

  Punt2D Punt2D::punt_mig(Punt2D p) const {
    return Punt2D((a_x+p.a_x)/2, (a_y+p.a_y)/2);
  }

// Modificadors

  void Punt2D::moure(double x, double y) {
    a_x += x;
    a_y += y;
  }

  void Punt2D::moure(Punt2D p) {
    a_x += p.a_x;
    a_y += p.a_y;
  }

  void Punt2D::llegir() {
    cin >> a_x >> a_y;
  }
