#include <iostream>
#include "windowAddon/WindowAddon.h" //incluim la llibreria de la finestra.

using namespace std;

const int AMPLE_FINESTRA = 640;          //amplada en pixels de la finestra que obrirem.
const int ALT_FINESTRA = 480;            //altura en pixels de la finestra que obrirem.

const int MAX_VOLTES = 10;      //nombre de voltes que fara la tortuga.
const float ANGLE_INICIAL = 45; //angle inicial absolut de la tortuga.
const double INTERVAL = 0.1;    //temps en segons entre desplaçaments de la tortuga.

const int MIDA_COSTAT = 200;         //mida del costat del quadrat que generara la tortuga.

int main()
{
    int angle; //angle de gir de la tortuga.

    cout << "Entra l'angle de gir de les cantonades: ";
    cin >> angle;

    Window finestra(AMPLE_FINESTRA, ALT_FINESTRA); //finestra de mida definida amb fons blanc i color de dibuix negre. Els colors son aixi per defecte, i no hem especificat canviar-los.

    finestra.t_show(); //fem que la tortuga mostri el seu cursor.

    finestra.t_setPos((AMPLE_FINESTRA-MIDA_COSTAT)/2, (ALT_FINESTRA-MIDA_COSTAT)/2); //fiquem la tortuga una mica abaix a la esquerra del centre de la pantalla.
    finestra.t_setHeading(ANGLE_INICIAL); //fiquem la tortuga amb una inclinacio inicial determinada.

    int voltes = 0;
    int girs = 0;

    while( voltes < MAX_VOLTES){ //mentre el comptador de voltes sigui inferior al maxim de voltes.

        finestra.t_forward(MIDA_COSTAT); //fem avancar cap endevant la tortuga.
        finestra.t_left(angle);     //la fem girar cap a l'esquerra.

        finestra.rest(INTERVAL); //fem esperar la finestra un temps determinat.

        girs++;

        if(girs >= 4){ //si ja hem girat 4 cops, sumem una volta i reiniciem el comptador de girs.
            girs = 0;
            voltes ++;
        }

    }

    finestra.waitWindowCloseButton(); //esperem a que tanquin la finestra.

    return 0;
}
