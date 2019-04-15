/* Vector de punts 2D ordenat de menor a major distància a l'origen (si la distància és igual cal ordenar segons coordenada x)
 */

#ifndef Vector_punt2D_h
#define Vector_punt2D_h
#include "Punt2D.h"

class Vector_punt2D {
// Descripció: vector de punts 2D ordenat de menor a major distància a l'origen (si la distància és igual cal ordenar segons menor coordenada x)

public:
// Constructors
    Vector_punt2D();
    // Pre: --; Post: vector buit de punts
    
// Consultors
    double nombre_punts() const;
    // Pre: --; Post: retorna el nombre de punts
    double mitjana_distancies_origen() const;
    // Pre: nombre_punts()>0; Post: retorna la distància mitjana de tots els punts del vector a l'origen
    void mostrar() const;
    // Pre: --; Post: mostra tots els punts del vector numerats de 0 al nombre de punts-1
    
// Modificadors
    void inserir_punt(Punt2D punt);
    // Pre: nombre_punts()<MAX; Post: s'ha inserit ordenadament un punt en el vector de punts
    void esborrar_punt(int pos);
    // Pre: nombre_punts()>0 i 0<=pos<nombre_punts(); Post: s'esborra el punt que ocupa la posició pos
    
private:
    // Constants
    static const unsigned MAX= 100;
    // Atributs
    Punt2D a_t[MAX]; // vector de punts
    unsigned a_n;    // nombre de punts
    
    // Mètodes privats
    static bool es_menor(Punt2D p1, Punt2D p2);
    // Pre: --; Post: retorna cert si el punt actual és menor (més proper a l'origen) que p, fals en el cas contrari
};

#endif /* Vector_punt2D_h */
