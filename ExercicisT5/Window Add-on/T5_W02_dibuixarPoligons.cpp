#include "windowAddon/WindowAddon.h" //incluim la llibreria de la finestra.
#include <cmath>

using namespace std;

const int AMPLE_FINESTRA = 800;     //amplada en pixels de la finestra que obrirem.
const int ALT_FINESTRA = 600;       //altura en pixels de la finestra que obrirem.

const char OPCIO_TRIANGLE = 't';    //caracter que ha d'entrar l'usuari si vol dibuixar un triangle.
const char OPCIO_QUADRAT = 'q';     //caracter que ha d'entrar l'usuari si vol dibuixar un quadrat.
const char OPCIO_PENTAGON = 'p';    //caracter que ha d'entrar l'usuari si vol dibuixar un pentagon.
const char OPCIO_HEXAGON = 'h';     //caracter que ha d'entrar l'usuari si vol dibuixar un hexagon.

const int ANGLE_TRIANGLE = 60;      //angle en graus que formen cadascun dels angles d'un triangle.
const int ANGLE_QUADRAT = 90;       //angle en graus que formen cadascun dels angles d'un quadrat.
const int ANGLE_PENTAGON = 108;     //angle en graus que formen cadascun dels angles d'un pentagon.
const int ANGLE_HEXAGON = 120;      //angle en graus que formen cadascun dels angles d'un hexagon.



int dibuixarFigura(Window & w, int angle, int n_costats, int mida_costat){
/*
    Pre: mida_costat > 0.
    Post: una tortuga dibuixa una figura a la finestra. En funcio dels parametres d'entrada, la figura pot ser un poligon regular o no.
    Param w: finestra on es dibuixara la figura.
    Param angle: angle intern entre dos costats de la figura.
    Param n_costats: nombre de costats de la figura.
    Param mida_costat: mida dels costats de la figura.
    Return: el perimetre de la figura.
*/
    int comptador = 0;

    if(n_costats >= 3){

        //ens guardem la posicio anterior de la tortuga per restaurar-la al acabar.
        float x_ant = w.t_getPos().x;
        float y_ant = w.t_getPos().y;
        float heading_ant = w.t_heading();

        //dades per centrar la figura
        float r = mida_costat/(2*sin(PI/n_costats));        //radi del cercle que circumscriu la figura.
        float h = sqrt(r*r-(mida_costat*mida_costat)/4);    //altura del triangle format al unir els dos extrems d'un costat de la figura amb el circumcentre.

        w.t_setPos((AMPLE_FINESTRA-mida_costat)/2, ALT_FINESTRA/2-h); //movem la tortuga a la posicio desitjada abans de dibuixar la figura.

        while(comptador < n_costats){
            w.t_forward(mida_costat);
            w.t_left(180-angle);
            comptador++;
        }

        //restaurem els valors d'abans d'usar la tortuga per dibuixar la figura.
        w.t_setPos(x_ant,y_ant);
        w.t_setHeading(heading_ant);
    }

    return comptador*mida_costat;
}

void mostrarMenu(){
/*
    Pre: --
    Post: es mostra per sortida estandard el menu d'opcions de figures a triar.
*/
    cout << OPCIO_TRIANGLE << ": Triangle" << endl << OPCIO_QUADRAT << ": Quadrat" << endl << OPCIO_PENTAGON << ": Pentagon" << endl << OPCIO_HEXAGON <<": Hexagon" << endl;
}

int main()
{
    cout << "Hola! Quina figura vols dibuixar?" << endl << endl;
    mostrarMenu();

    cout << endl << "Figura: ";
    char opcio;
    cin >> opcio;

    //determinem, a partir de la opcio, el nombre de costats i l'angle entre aquests.
    int angle, n_costats;

    switch(opcio){
        case OPCIO_TRIANGLE:
            angle = ANGLE_TRIANGLE;
            n_costats = 3;
            break;
        case OPCIO_QUADRAT:
            angle = ANGLE_QUADRAT;
            n_costats = 4;
            break;
        case OPCIO_PENTAGON:
            angle = ANGLE_PENTAGON;
            n_costats = 5;
            break;
        case OPCIO_HEXAGON:
            angle = ANGLE_HEXAGON;
            n_costats = 6;
            break;
        default:
            angle = 0;
            n_costats = -1; //definirem una funcio que no dibuixi si li donem un nombre de costats negatiu.
            break;
    }

    cout << "Molt be! Ara diga'm la mida d'un dels costats d'aquesta figura: ";

    int mida;
    cin >> mida;

    Window finestra(AMPLE_FINESTRA, ALT_FINESTRA); //finestra de mida definida amb color de fons i dibuix per defecte.

    //cridem la funcio i mostrem el perimetre de la figura.
    cout << "La figura ha estat dibuixada, i el seu perimetre es de: " << dibuixarFigura(finestra, angle, n_costats, mida) << endl;

    finestra.waitWindowCloseButton();

    return 0;
}
