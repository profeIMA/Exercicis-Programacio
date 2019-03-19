#include <iostream>
#include "windowAddon/WindowAddon.h" //incluim la llibreria de la finestra.

using namespace std;

const int AMPLE_FINESTRA = 640;         //amplada en pixels de la finestra que obrirem.
const int ALT_FINESTRA = 480;           //altura en pixels de la finestra que obrirem.

const int MINIM_COSTAT = 5;             //minima longitud que volem que tingui el costat d'un quadrat.
const int REDUCCIO_COSTAT = 10;         //reduccio de la longitud del costat en cada iteracio.

int main()
{
    int mida_costat,n;

    cout << "Bon dia! Que et sembla si em dius el nombre de quadrats concentrics que vols que dibuixi?" << endl;
    cin >> n;
    cout << "Molt Be!" << endl << "Diga'm la mida del costat del quadrat mes exterior: ";
    cin >> mida_costat;

    Window finestra(AMPLE_FINESTRA, ALT_FINESTRA); //finestra de mida definida amb fons blanc i color de dibuix negre. Els colors son aixi per defecte, i no hem especificat canviar-los.

    Point2D p1((AMPLE_FINESTRA-mida_costat)/2, (ALT_FINESTRA+mida_costat)/2); //cantonada superior esquerra.
    Point2D p2((AMPLE_FINESTRA+mida_costat)/2, (ALT_FINESTRA-mida_costat)/2); //cantonada inferior dreta.

    int comptador = 0; //nombre de quadrats dibuixats.

    while(comptador < n && mida_costat >= MINIM_COSTAT) { //mentre no arribem al nombre maxim de quadrats i no arribem a la mida minima

        finestra.rectangle(p1, p2); //dibuixem el quadrat actual
        comptador++;

        p1 = Point2D(p1.x+REDUCCIO_COSTAT/2, p1.y-REDUCCIO_COSTAT/2); //cantonada superior esquerra del nou quadrat.
        p2 = Point2D(p2.x-REDUCCIO_COSTAT/2, p2.y+REDUCCIO_COSTAT/2); //cantonada inferior dreta del nou quadrat.
        mida_costat -= REDUCCIO_COSTAT; //reduim la mida del costat

    }

    finestra.waitWindowCloseButton(); //esperem a que l'usuari ens tanqui la finestra.

    return 0;
}
