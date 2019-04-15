#ifndef PUNT2D_H
#define PUNT2D_H
#include <iostream>
using namespace std;

class Punt2D { //guardat en en un fitxer Punt2D.h
// Descripci—: un punt en el pla
public:
  // Constructors
  Punt2D(); //Pre:--; Post: el punt Žs (0,0)
  Punt2D(double x, double y); //Pre:--; Post: el punt Žs (x,y)

  // Mtodes consultors
  double coordenada_x() const;
  //Pre: --; Post: retorna la coordenada x del punt
  double coordenada_y() const;
  //Pre: --; Post: retorna la coordenada y del punt
  double distancia(Punt2D p) const;
  //Pre: --; Post: retorna la distˆncia del punt a p
  void mostrar() const;
  //Pre: --; Post: mostra el punt en forma (x,y)
  bool es_igual(Punt2D p) const;
  //: --; Post: retorna cert si el punt i p s—n iguals
  Punt2D punt_mig(Punt2D p) const;
  //Pre:--; Post: retorna el punt mig entre el punt i p

  // Mtodes modificadors
  void moure(double vector_x, double vector_y);
  //Pre:--; Post: punt desplaat amb vector (vector_x,vector_y)
  void moure(Punt2D p);
  //Pre:--; Post: punt desplaat amb vector (0,0)->p
  void llegir();
  //Pre:--; Post: el punt Žs el llegit de teclat

private:
  double a_x, a_y; // atributs (usem coordenades cartesianes)
};

#endif // PUNT2D_H
