#ifndef QUADRILATER_H
#define QUADRILATER_H

#include "Poligon.h"

//Descripció: Guarda la informació d'un quadrilàter 4 vèrtexs al pla
class Quadrilater: public Poligon
{
    public:
        Quadrilater();
         //Pre:--
        //Post: crea un quadrat degenerat amb 4 vèrtexs iguals

        //CONSULTOR
        void mostra()const;
        //Pre:--
        //Post: mostra la informació del quadrilàter

        //MODIFICADOR
        void llegir();
        //Pre:--
        //Post: llegeix els tres vertexs que formen el triangle

    private:
        //CONSULTOR
        double area ()const;
        //Pre:--
        //Post: retorna l'àrea del triangle
};

#endif // QUADRILATER_H
