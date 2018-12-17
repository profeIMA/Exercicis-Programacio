#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Figura_Geometrica.h"

//Descripció: Permet guardar la informació associada a una el·lipse (centre i distància dels semieixos) del pla

class Ellipse : public Figura_Geometrica
{
    public:
        Ellipse();
        //Pre:--
        //Post: crea una el·lipse degenerada amb semieixos =0

        //CONSULTOR
        void mostra()const;
        //Pre:--
        //Post: mostra la informació de l'el·lipse

        //MODIFICADOR
        void llegir();
        //Pre:--
        //Post: llegeix el centre i la distància als dos semieixos de l'el·lipse

    private:
        Punt2D a_centre;
        double a_a;
        double a_b;

        //CONSULTOR
        double area ()const;
        //Pre:--
        //Post: retorna l'àrea de l'el·lipse


};

#endif // ELLIPSE_H
