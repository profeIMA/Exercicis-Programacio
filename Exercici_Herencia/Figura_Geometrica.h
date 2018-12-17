#ifndef FIGURA_GEOMETRICA
#define FIGURA_GEOMETRICA

#include "Punt2D.h"

//Descripció: Classe abstracta de la que deriven diferents tipus de figures geomètriques

class Figura_Geometrica
{
    public:

        Figura_Geometrica();
        //Constructor per defect

        //virtual ~Figura_Geometrica();
        // Alguna de les classe derivades treballa amb memòria dinàmica cal indicar que el destructor és virtual
        // Si enlloc d'implementar-lo buit es fes abstracte caldria implementar-lo a totes les classes derivades

        // CONSULTORS
        virtual void mostra() const=0;//mètode abstracte
        // mètode virtual per mostrar les diferents figures geomètriques, no hi ha cap part del mostrar
        // que sigui comú, per això es fa virtual, si calgués mostrar una part comuna
        // s'implementaria
        bool te_menor_area(Figura_Geometrica *f)const;
        //Pre: f!=NULL
        //Post: retorna cert si la figura actual té area menor que l'apuntada per f

        //MODIFICADORS
        virtual void llegir()=0; //mètode abstracte
        //No hi ha cap part del llegir que sigui comú, no s'implementa

    protected:
        static const double PI;//=3.14159;
        //Constant accessible des de totes les classes derivades

        virtual double area()const=0;
        // el càlcul de l'àrea és específic de cada tipus de figura geomètrica, no s'implementa a la classe base

    private:
};

#endif
