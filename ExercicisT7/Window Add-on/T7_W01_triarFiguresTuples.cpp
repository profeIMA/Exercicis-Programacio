#include <iostream>
#include "windowAddon/WindowAddon.h" //incluim la llibreria de la finestra.

using namespace std;

const int AMPLE_FINESTRA = 640; //amplada en pixels de la finestra que obrirem.
const int ALT_FINESTRA = 480;   //altura en pixels de la finestra que obrirem.

const char FI = 'e';            //marca de fi

const char OPCIO_RECTANGLE = 'r';
const char OPCIO_LINIA = 'l';
const char OPCIO_CERCLE = 'c';



struct Cercle{
    Point2D c;
    float r;
};

struct Rectangl{ //no la podem anomenar 'Rectangle' ja que existeix una funcio anomenada Rectangle() a la llibreria wingdi i el CodeBlocks a Windows la fa servir.
    Point2D p1,p2;
};

typedef struct Rectangl Linia; //una linia i un rectangle tenen els mateixos elements.



void mostrarMenu(){
/*
    Pre: --
    Post: es mostra per sortida estandard el menu d'opcions de figures que es poden dibuixar.
*/
    cout << OPCIO_RECTANGLE << "    : Dibuixar rectangle" << endl;
    cout << OPCIO_LINIA << "    : Dibuixar linia" << endl;
    cout << OPCIO_CERCLE << "    : Dibuixar cercle" << endl;
}

Point2D demanarPunt(){
/*
    Pre: --
    Post: Demana un punt per entrada estandard.
    Return: el punt entrat.
*/
    Point2D p;

    cout << "X: ";
    cin >> p.x;

    cout << "Y: ";
    cin >> p.y;

    return p;
}

Rectangl demanarRectangle(){
/*
    Pre: --
    Post: s'entren per teclat les quatre dades necessaries per pintar un rectangle: les coordenades X i Y de les seves cantonades superior esquerra i inferior dreta.
    Return: el rectangle entrat.
*/
    Rectangl r;

    cout << "Per dibuixar un rectangle, necessito que em diguis les coordenades de la cantonada superior esquerra i la cantonada inferior dreta." << endl;
    cout << "Cantonada superior esquerra:" <<endl;
    r.p1 = demanarPunt();

    cout << "Cantonada superior esquerra:" <<endl;
    r.p2 = demanarPunt();

    return r;
}

void dibuixarRectangle(Window & w){
/*
    Pre: --
    Post: demana les dades necessaries per dibuixar un rectangle i el pinta a la finestra w.
    Param w: finestra en la que es pintara la figura.
*/
    Rectangl r = demanarRectangle();

    w.rectangle(r.p1, r.p2); //recordem que la finestra ens permet dibuixar usant la struct Point2D.
}

Linia demanarLinia(){
/*
    Pre: --
    Post: s'entren per teclat les quatre dades necessaries per pintar una linia: les coordenades X i Y dels seus dos extrems.
    Return: la linia entrada.
*/
    Linia l;

    cout << "Per dibuixar una linia, necessito que em diguis les coordenades dels seus dos extrems." << endl;
    cout << "Primer punt:" <<endl;
    l.p1 = demanarPunt();

    cout << "Segon punt:" <<endl;
    l.p2 = demanarPunt();

    return l;
}

void dibuixarLinia(Window & w){
/*
    Pre: --
    Post: demana les dades necessaries per dibuixar una linia i la pinta a la finestra w.
    Param w: finestra en la que es pintara la figura.
*/
    Linia l = demanarLinia();

    w.line(l.p1, l.p2);  //recordem que la finestra ens permet dibuixar usant la struct Point2D.
}

Cercle demanarCercle(){
/*
    Pre: --
    Post: s'entren per teclat les tres dades necessaries per pintar un cercle: les coordenades X i Y del seu centre i el radi.
    Return: el cercle entrat.
*/
    Cercle c;

    cout << "Per dibuixar una cercle, necessito que em diguis les coordenades del seu centre i el radi d'aquest." << endl;
    cout << "Coordenades del centre:" <<endl;
    c.c = demanarPunt();

    cout << "Radi: ";
    cin >> c.r;

    return c;
}

void dibuixarCercle(Window & w){
/*
    Pre: --
    Post: demana les dades necessaries per dibuixar un cercle o cercle emplenat i el pinta a la finestra w.
    Param w: finestra en la que es pintara la figura.
*/
    Cercle c = demanarCercle();

    w.circle(c.c, c.r); //recordem que la finestra ens permet dibuixar usant la struct Point2D.
}

void pintarFigura(Window & w, char s){
/*
    Pre: --
    Post: es demanen dades addicionals i es pinta una figura en funcio de la opcio entrada.
    Param w: finestra on es pintara la figura.
    Param s: opcio entrada.
*/

    switch(s){
        case OPCIO_RECTANGLE:
            dibuixarRectangle(w);
            break;
        case OPCIO_LINIA:
            dibuixarLinia(w);
            break;
        case OPCIO_CERCLE:
            dibuixarCercle(w);
            break;
        default: //opcio desconeguda
            cout << "Opcio desconeguda: torna-ho a intentar." << endl;
            break;
    }
}

int main()
{
    cout << "Hola. Diga'm quina figura vols dibuixar: " << endl;
    cout << "Les opcions son: " << endl << endl;
    mostrarMenu();
    cout << endl;

    char seleccio;
    cout << "Que tries? ";
    cin >> seleccio;

    if (seleccio != FI){

        Window finestra(AMPLE_FINESTRA,ALT_FINESTRA);

        while(seleccio != FI){ //mentre no arrivem a la marca de fi.
            cout << endl;
            pintarFigura(finestra, seleccio);
            cout << endl;
            cout << "Vols fer alguna cosa mes?" << endl << endl;
            mostrarMenu();
            cout << endl << "Que tries? ";
            cin >> seleccio;
        }
    }

    cout << endl << "Adeu!" << endl;

    return 0;
}
