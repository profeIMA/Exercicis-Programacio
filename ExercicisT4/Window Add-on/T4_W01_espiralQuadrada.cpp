#include "windowAddon/WindowAddon.h" //incluim la llibreria de la finestra.

using namespace std;

const int AMPLE_FINESTRA = 500;          //amplada en pixels de la finestra que obrirem.
const int ALT_FINESTRA = 500;            //altura en pixels de la finestra que obrirem.

int main()
{
    Window finestra(AMPLE_FINESTRA, ALT_FINESTRA);        //finestra de mida definida amb fons blanc i color de dibuix negre. Els colors son aixi per defecte, i no hem especificat canviar-los.

    finestra.t_show();                  //fem que la tortuga mostri el seu cursor.

    finestra.t_setPos(AMPLE_FINESTRA/2, ALT_FINESTRA/2);  //fiquem la tortuga al centre de la pantalla.
    finestra.t_setHeading(270);         //fiquem la tortuga amb una inclinacio inicial determinada (mirant cap avall).

    bool dins_dels_marges = true;       //ens indicara quan hem de parar.
    int mida_linia = 10;                //mida del costat actual.

    finestra.t_forward(mida_linia/2);   //avancem abans de la iteracio per colocar-nos al marge del primer quadrat. Avancem la meitat perque actualment estem al centre del quadrat, i no als marges.


    while( dins_dels_marges ){ //mentre no sortim dels marges de la finestra.

        finestra.t_forward(mida_linia); //pintem el costat de la espiral.
        finestra.t_left(90);            //girem per fer la cantonada.

        dins_dels_marges = (finestra.t_getPos().x < AMPLE_FINESTRA && finestra.t_getPos().x >= 0) //comprovem si hem sortit dels marges.
                        && (finestra.t_getPos().y < ALT_FINESTRA && finestra.t_getPos().y >= 0);

        mida_linia += 10; //incrementem la mida del costat.
    }

    //finestra.line(finestra.t_getPos(), Point2D(ample/2, alt/2)); //podem dibuixar una linia des del punt on s'ha quedat la tortuga per confirmar que ha parat just quan ha sortit de la finestra.

    finestra.waitWindowCloseButton(); //esperem a que tanquin la finestra.

    return 0;
}
