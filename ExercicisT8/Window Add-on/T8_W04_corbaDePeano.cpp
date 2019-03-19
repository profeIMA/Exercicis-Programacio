#include <iostream>
#include "windowAddon/WindowAddon.h" //incluim la llibreria de la finestra.

using namespace std;

const int AMPLE_FINESTRA = 800;          //amplada en pixels de la finestra que obrirem.
const int ALT_FINESTRA = AMPLE_FINESTRA; //altura en pixels de la finestra que obrirem.

void peano(Window & w, int n, double distancia){
/*
    Pre: n >= 0.
    Post: dibuixa la corba de Peano d'ordre n a la finestra w.
    Param w: finestra on es dibuixa la corba.
    Param n: nivell o ordre de la corba.
    Param distancia: longitud del segment.
*/
	if(n<1) //si hem arribat al cas base, pintem el segment corresponent.
		w.t_forward(distancia);
	else{ //altrament, subdividim el segment en la corva de Peano de nivell n-1.
		peano(w,n-1, distancia/3);
		w.t_left(-90.0);
		peano(w,n-1, distancia/3);
		w.t_left(90.0);
		peano(w,n-1, distancia/3);
		w.t_left(90.0);
		peano(w,n-1, distancia/3);
		peano(w,n-1, distancia/3);
		w.t_left(90.0);
		peano(w,n-1, distancia/3);
		w.t_left(90.0);
		peano(w,n-1, distancia/3);
		w.t_left(90.0);
		peano(w,n-1, distancia/3);
		peano(w,n-1, distancia/3);
	}
}

int main()
{
    cout << "Diga'm el nivell de la corba de Peano que vols que dibuixi: " << endl;
    int ordre;
    cin >> ordre;

    if(ordre < 0) cout << "Error. No puc dibuixar la corba de Peano d'ordre inferior a 0." << endl;
    else{

        if(ordre > 4) cout << "Warning: L'ordre que has introduit es " << ordre << ". La figura es pot veure deformada degut als errors d'arrodoniment quan s'introdueix un ordre major o igual a 5." << endl;

        //calculem el punt a on volem comencar a dibuixar la corba.
        double distancia = ALT_FINESTRA;
        double x = (AMPLE_FINESTRA - ALT_FINESTRA) / 2;
        double y = ALT_FINESTRA / 2;

        Window finestra(AMPLE_FINESTRA,ALT_FINESTRA);

        finestra.t_setPos(x,y); //ens coloquem al punt desitjat.

        peano(finestra, ordre, distancia); //dibuixem la corba de Peano de manera recursiva.

        finestra.waitWindowCloseButton();

    }
    return 0;
}
