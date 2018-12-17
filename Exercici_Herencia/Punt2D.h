#ifndef PUNT2D_H
#define PUNT2D_H
#include <iostream>
using namespace std;

class Punt2D{ //guardat en en un fitxer Punt2D.h
// Descripció: un punt en el pla

public:
  // CONSTRUCTORS
  Punt2D(double x, double y); //Pre:--; Post: el punt és (x,y)
  Punt2D(); //Pre:--; Post: el punt és (0,0)

  // MÈTODES CONSULTORS
  double projeccio_eix_x() const;
  //Pre: --; Post: retorna la projecció del punt a sobre l’eix x
  double projeccio_eix_y() const;
  //Pre: --; Post: retorna la projecció del punt a sobre l’eix y
  double distancia(Punt2D p) const;
  //Pre: --; Post: retorna la distància del punt a p
  void mostra() const;
  //Pre: --; Post: mostra el punt en forma (x,y)
  bool son_iguals(Punt2D p) const;
  //: --; Post: retorna cert si p i el punt són iguals
  Punt2D punt_mig(Punt2D p) const;
  //Pre:--; Post: el punt mig entre el punt i p

  // MÈTODES MODIFICADORS
  void desplacament(double vector_x, double vector_y);
  //Pre:--; Post: punt desplaçat amb vector (vector_x,vector_y)
  void desplacament(Punt2D p);
  //Pre:--; Post: punt desplaçat amb vector 0p
  void llegir();
  //Pre:--; Post: el punt és el llegit de teclat
  void canvia_posicio(double x, double y);
  // Pre: -- ; Post: El punt és (x,y)

private: // PART PRIVADA
  double a_x, a_y; //atributs (usem coordenades cartesianes)


};


#endif // PUNT2D_H
