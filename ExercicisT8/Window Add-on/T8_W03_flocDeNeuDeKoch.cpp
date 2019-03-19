#include <iostream>
#include "windowAddon/WindowAddon.h" //incluim la llibreria de la finestra.
#include <cmath>
using namespace std;

const int AMPLE_FINESTRA = 800;          //amplada en pixels de la finestra que obrirem.
const int ALT_FINESTRA = AMPLE_FINESTRA; //altura en pixels de la finestra que obrirem.

const unsigned ANGLE = 60;               //valor dels angles d'un triangle equilater.

void koch(Window & w, int n, double longitud){
/*
    Pre: nivell >= 0.
    Post: dibuixa el fractal de Koch de nivell n.
    Param w: finestra on es dibuixa el fractal.
    Param n: nivell del fractal.
    Param longitud: longitud del segment.
*/
    if (n<1) //si hem arribat al nivell 0, pintem el segment.
        w.t_forward(longitud);
    else{ //altrament, pintem recursivament el segment.
        koch(w,n-1,longitud/3.0);
        w.t_left(ANGLE);
        koch(w,n-1,longitud/3.0);
        w.t_right(2.0*ANGLE);
        koch(w,n-1,longitud/3.0);
        w.t_left(ANGLE);
        koch(w,n-1,longitud/3.0);
    }
}

int main()
{
    cout << "Diga'm el nivell de la corba de Koch que vols que dibuixi: ";
    int nivell;
    cin >> nivell;

    if(nivell < 0) cout << "Error. No es pot dibuixar la corba de Koch amb nivell menor que 0." << endl;
    else{
        //Tall de codi per centrar la figura.
        //Font: http://www.sc.ehu.es/sbweb/fisica/cursoJava/numerico/recursivo/recursivo.htm#Curva%20de%20Koch
        double distancia=(3*(ALT_FINESTRA-30))/(2*1.732050807568); // 3*(altura del fractal)/(2*sqrt(3)).
        double x = (AMPLE_FINESTRA - distancia)/2;
        double y = ALT_FINESTRA - (distancia/3)*sin(PI/3) - 15;

        Window finestra(AMPLE_FINESTRA, ALT_FINESTRA);

        finestra.t_setPos(x,y);

        //dibuixem el fractal de Koch fent cadascun dels seus segments de manera recursiva.
        koch(finestra, nivell, distancia);
        finestra.t_right(2*ANGLE);
        koch(finestra, nivell, distancia);
        finestra.t_right(2*ANGLE);
        koch(finestra, nivell, distancia);

        finestra.waitWindowCloseButton();
    }

	return 0;
}
