#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Poligon.h"

//Descripció: guarda els 3 vèrtexs d'un triangle al pla

class Triangle : public Poligon
{
    public:
        Triangle();
        //Pre:--
        //Post: crea un triangle degenerat amb 3 vèrtexs iguals

        void mostra()const;
        //Pre:--
        //Post: mostra la informació del triangle

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

#endif // TRIANGLE_H
