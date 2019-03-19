#include <iostream>
#include "windowAddon/WindowAddon.h" //incluim la llibreria de la finestra.

using namespace std;

const int AMPLE_FINESTRA = 640;         //amplada en pixels de la finestra que obrirem.
const int ALT_FINESTRA = 480;           //altura en pixels de la finestra que obrirem.

const int MAX_VOLTES = 32;              //nombre de voltes que fara la tortuga. Equival al nombre de quadrats que volem dibuixar.
const float ANGLE_INICIAL = 45;         //angle inicial absolut de la tortuga.
const double INTERVAL = 0.02;           //temps en segons entre desplaçaments de la tortuga.

const int DESFASAMENT = 5;              //angle de desfasament entre els quadrats.
const int INCREMENT = 5;                //increment de la mida del costat per cada volta donada.

const int MIDA_COSTAT_INICIAL = 50;     //mida inicial del costat del quadrat.

int main()
{
    Window finestra(AMPLE_FINESTRA, ALT_FINESTRA); //finestra de mida definida amb fons blanc i color de dibuix negre. Els colors son aixi per defecte, i no hem especificat canviar-los.

    finestra.t_show(); //fem que la tortuga mostri el seu cursor.

    finestra.t_setPos(AMPLE_FINESTRA/2, ALT_FINESTRA/2); //fiquem la tortuga al centre de la pantalla.
    finestra.t_setHeading(ANGLE_INICIAL); //fiquem la tortuga amb una inclinacio inicial determinada.

    int voltes = 0;
    int girs = 0;

    int costat = MIDA_COSTAT_INICIAL; //mida del costat del quadrat, anira variant durant l'execucio.

    while( voltes < MAX_VOLTES){    //mentre el comptador de voltes sigui inferior al maxim de voltes.

        finestra.t_forward(costat); //fem avancar cap endevant la tortuga.
        finestra.t_left(90);        //la fem girar cap a l'esquerra.

        finestra.rest(INTERVAL);    //fem esperar la finestra un temps determinat.

        girs++;

        if(girs >= 4){ //si ja hem girat 4 cops, sumem una volta i reiniciem el comptador de girs.
            girs = 0;
            voltes++;
            costat += INCREMENT;
            finestra.t_left(DESFASAMENT); //fem girar la tortuga uns graus per generar un quadrat desfasat respecte l'anterior.
        }

    }

    finestra.waitWindowCloseButton(); //esperem a que tanquin la finestra.

    return 0;
}
