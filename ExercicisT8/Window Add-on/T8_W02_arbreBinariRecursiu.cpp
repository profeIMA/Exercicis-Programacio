#include <iostream>
#include "windowAddon/WindowAddon.h" //incluim la llibreria de la finestra.

using namespace std;

const int AMPLE_FINESTRA = 600;      //amplada en pixels de la finestra que obrirem.
const int ALT_FINESTRA = 600;        //altura en pixels de la finestra que obrirem.

const int MIN_MIDA_BRANCA = 5;       //mida minima d'una branca del arbre.
const int ANGLE = 20;                //angle entre la direccio de la branca inicial i les dues sub-branques seguents.

//la idea principal es baixar el llapis, pintar de manera recursiva i tornar al lloc d'origen amb el llapis aixecat per no pintar la tornada.
void arbre(Window & w, int mida_branca, int reduccio_branca){
/*
    Pre: reduccio_branca > 0, altrament dibuixara fins l'infinit.
    Post: dibuixa un arbre binari recursiu fins que les branques de l'arbre deixin de mesurar el minim indicat.
    Param w: finestra on es pinta l'arbre.
    Param mida_branca: mida de la branca principal.
    Param reduccio_branca: disminucio de longitud de la branca en cada crida recursiva.
*/
    if (mida_branca > MIN_MIDA_BRANCA){
        w.t_forward(mida_branca);                               //dibuixem la branca principal.
        w.t_right(ANGLE);                                       //orientem la tortuga cap a la dreta.
        arbre(w,mida_branca-reduccio_branca, reduccio_branca);  //dibuixem l'arbre dret.
        w.t_left(2*ANGLE);                                      //orientem la tortuga cap a l'esquerra.
        arbre(w,mida_branca-reduccio_branca, reduccio_branca);  //fem l'arbre esquerre.
        w.t_right(ANGLE);                                       //la girem de tal manera que torna a quedar en la direccio inicial.

        //aixequem i baixem el llapis al recular ja que no ens cal pintar la linia que ja hem pintat. No es necessari pero redueix el nombre de crides de dibuixat.
        w.t_penUp();                                            //aixequem el llapis ja que no cal que pinti.
        w.t_back(mida_branca);                                  //fem recular a la tortuga.
        w.t_penDown();                                          //tornem a baixar el llapis.
    }
}

int main()
{
    int mida, reduccio;
    cout << "ATENCIO: la profunditat de l'algorisme depen de la relacio entre aquest nombre que entraras ara i el seguent. Et recomano que la divisio d'aquests dos nombres no sigui gaire mes gran que 15 si vols veure acabar el teu programa en un temps raonable." <<endl;
    cout << "Hola! Diga'm la mida de la primera branca que vols dibuixar: " <<endl;
    cin >> mida;

    cout << "Ara diga'm quant s'ha de reduir la branca per cada pas: " <<endl;
    cin >> reduccio;

    Window w(AMPLE_FINESTRA, ALT_FINESTRA);

    w.t_setPos(AMPLE_FINESTRA/2,ALT_FINESTRA/10); //coloquem la tortuga centrada al mig de la pantalla i una mica moguda cap avall.
    w.t_setHeading(90);         //la orientem mirant cap adalt, apuntant cap a la direccio on volem fer creixer l'arbre.

    arbre(w, mida, reduccio);   //dibuixem l'arbre recursiu.

    w.waitWindowCloseButton();  //esperem a que l'usuari ens tenqui la finestra.

    cout << "Ja ho has vist, fins aviat." << endl;

    return 0;
}
