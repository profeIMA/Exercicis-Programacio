#ifndef CERCLE_H
#define CERCLE_H

#include "Figura_Geometrica.h"

//Descripció: permet guardar el centre i el radi d'un cercle al pla

class Cercle : public Figura_Geometrica
{
    public:
        Cercle();
        //Pre:--
        //Post: crea un cercle degenerat de radi 0

        //CONSULTORS
        void mostra() const;
        //Pre:--
        //Post: mostra el cercle actual

        //MODIFICADORS
        void llegir();
        //Pre:--
        //Post: llegeix tota la informació referent a un cercle

    private:
        double a_r;
        Punt2D a_centre;

        //CONSULTORS
        double area()const;
        //Pre:--
        //Post: retorna l'àrea del cercle
};

#endif // CERCLE_H
