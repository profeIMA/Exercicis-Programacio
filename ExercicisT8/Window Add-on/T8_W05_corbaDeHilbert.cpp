#include <iostream>
#include "windowAddon/WindowAddon.h" //incluim la llibreria de la finestra.
#include <cmath>

using namespace std;

const int AMPLE_FINESTRA = 800;          //amplada en pixels de la finestra que obrirem.
const int ALT_FINESTRA = AMPLE_FINESTRA; //altura en pixels de la finestra que obrirem.

const int MARGE = 5;                     //marge de la cobra respecte els marcs de la finestra (en pixels).

void iHilbert(Window & w, int n, int direccio, double distancia){
/*
    Pre: n > 0 i direccio == 1 o direccio == -1. distancia > 0
    Post: dibuixa la corba de Hilbert d'ordre n a la finestra w.
    Param w: finestra on es dibuixara la corba.
    Param n: nivell de la corba.
    Param direccio: direccio cap a on es dibuixa el segment.
    Param distancia: mdia del segment.
*/
	if(n>0){ //mentre no arrivem al nivell final
		w.t_left(-90*direccio);
		iHilbert(w, n-1, -direccio, distancia);
		w.t_forward(distancia);
		w.t_left(90*direccio);
		iHilbert(w, n-1, direccio, distancia);
		w.t_forward(distancia);
		iHilbert(w, n-1, direccio, distancia);
		w.t_left(90*direccio);
		w.t_forward(distancia);
		iHilbert(w, n-1, -direccio, distancia);
		w.t_left(-90*direccio);
	}
}

void hilbert(Window & w, int n, double distancia){
/*
    Pre: n > 0 i distancia > 0.
    Post: dibuixa la corba de Hilbert d'ordre n a la finestra w.
    Param w: finestra on es dibuixara la corba.
    Param n: nivell de la corba.
    Param distancia: mida del segment.
*/
    iHilbert(w, n, -1, distancia/(pow(2,n)-1));
}

int main()
{
    cout << "Diga'm l'ordre de la corba de Hilbert que vols que et dibuixi: ";
    int ordre;
    cin >> ordre;

    if(ordre < 0) cout << "Error. No puc dibuixar una corba de Hilbert amb ordre negatiu." << endl;
    else{
        //calculem el punt d'inici.
        double distancia = ALT_FINESTRA - 2*MARGE; // fem distancia - 2*marge per fer encabir la corba dins dels marcs de la pantalla.
        double x = (AMPLE_FINESTRA - ALT_FINESTRA)/2.0 + MARGE; // 5 de marge.
        double y = MARGE; //5 de marge.

        Window finestra(AMPLE_FINESTRA,ALT_FINESTRA);

        finestra.t_setPos(x, y); //coloquem la tortuga al punt d'inici.

        hilbert(finestra, ordre, distancia); //dibuixem de manera recursiva la corba de Hilbert.

        finestra.waitWindowCloseButton();
    }

    return 0;
}
