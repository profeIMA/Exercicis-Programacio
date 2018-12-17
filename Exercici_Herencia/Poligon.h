#ifndef POLIGON
#define POLIGON

#include "Figura_Geometrica.h"

//Descripció: Permet guardar un poligon al pla

class Poligon : public Figura_Geometrica
{
    public:
        Poligon();
        //Pre:--
        //Post: Crea un poligon degenerat de 5 costats
        Poligon (unsigned n);
        //Pre: n>2
        //Post: crea un poligon d'n costats degenerat
        Poligon(const Poligon& other);
        //Pre:--
        //Post: crea un polígon amb els mateixos vèrtexs que other

        virtual ~Poligon();
        //Pre:--
        //Post: allibera la memòria reservada pel polígon

        //CONSULTORS
        virtual double area()const;
        //Pre: --
        //Post: retorna l'àrea del polígon actual
        virtual void mostra() const;
        //Pre: --
        //Post: mostra els vèrtexs de polígon actual

        //MODIFICADORS
        virtual void llegir();
        //Pre: --
        //Post: crea el polígon indicat per teclat
        Poligon& operator=(const Poligon& other);
        //Pre:--
        //Post: el polígon actual té els mateixos vèrtexs que other

    protected:
        Punt2D* a_t;
        unsigned a_n;

        //CONSULTOR
        void mostra_vertexs()const;
        //Pre:--
        //Post: mostra tots els vèrtexs del polígon

        //MODIFICADOR
        void llegir_vertexs();
        //Pre: --
        //Post: llegeix els vèrtexs del polígon


    private:
        //MODIFICADORS
        void reserva_memoria(unsigned n);
        //Pre:n>0
        //Post: reserva memòria per un poligon d'n punts
        void allibera();
        //Pre: --
        //Post: allibera la memòria reservada pel poligon si és que en té.
        void copia(const Poligon &o);
        //Pre:--
        //Post: el polígon actual té exactament els mateixos vèrtexs que o
};

#endif
