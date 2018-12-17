#include "Punt2D.h"
#include <cmath>


// CONSTRUCTORS

 Punt2D::Punt2D() {
     a_x=0;
     a_y=0;
 }

 Punt2D::Punt2D(double x, double y) {
     a_x=x;
     a_y=y;
 }

// CONSULTORS

 double Punt2D::projeccio_eix_x() const {
     return a_x;
  }

  double Punt2D::projeccio_eix_y() const {
     return a_y;
  }

  double Punt2D::distancia(Punt2D p) const {
     double difX= a_x-p.a_x;
     double difY= a_y-p.a_y;
     return sqrt(difX*difX+difY*difY);
  }

  void Punt2D::mostra() const {
     cout << "(" << a_x << "," << a_y << ")";// << endl;
  }

  bool Punt2D::son_iguals(Punt2D p) const {
     return a_x == p.a_x and a_y == p.a_y;
  }

  Punt2D Punt2D::punt_mig(Punt2D p) const {
     return Punt2D((a_x+p.a_x)/2, (a_y+p.a_y)/2);
  }

// MODIFICADORS

  void Punt2D::desplacament(double x, double y) {
   a_x+= x;
   a_y+= y;
 }

void Punt2D::desplacament(Punt2D p) {
   a_x+= p.a_x;
   a_y+= p.a_y;
 }

void Punt2D::llegir() {
   cin >> a_x >> a_y;
}

void Punt2D::canvia_posicio(double x, double y) {
   a_x= x;
   a_y= y;
 }
