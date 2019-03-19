#include <iostream>
#include "windowAddon/WindowAddon.h" //incluim la llibreria de la finestra.

using namespace std;

const int AMPLE_FINESTRA = 640;          //amplada en pixels de la finestra que obrirem.
const int ALT_FINESTRA = 480;            //altura en pixels de la finestra que obrirem.

const char FI = 'e';            //marca de fi.

//opcions del usuari.
const char OPCIO_RECTANGLE = 'r';
const char OPCIO_LINIA = 'l';
const char OPCIO_CERCLE = 'c';



void mostrarMenu(){
/*
    Pre: --
    Post: es mostra per sortida estandard el menu d'opcions de figures que es poden dibuixar.
*/
    cout << OPCIO_RECTANGLE << "    : Dibuixar rectangle" << endl;
    cout << OPCIO_LINIA << "    : Dibuixar linia" << endl;
    cout << OPCIO_CERCLE << "    : Dibuixar cercle" << endl;
}

float demanarCoordenada(char coord){
/*
    Pre: --
    Post: es demana una coordenada per l'entrada estandard.
    Param coord: tipus de la coordenada demanada.
    Return: la coordenada entrada.
*/
    float f = 0;

    if(coord == 'X') cout << "X: ";
    else cout << "Y: ";

    cin >> f;

    return f;
}

void demanarDadesRectangle(float & x1, float & y1, float & x2, float & y2){
/*
    Pre: --
    Post: s'entren per teclat les quatre dades necessaries per pintar un rectangle: les coordenades X i Y de les seves cantonades superior esquerra i inferior dreta.
    Param x1: coordenada X de la cantonada superior esquerra.
    Param y1: coordenada Y de la cantonada superior esquerra.
    Param x2: coordenada X de la cantonada inferior dreta.
    Param y2: coordenada Y de la cantonada inferior dreta.
*/
    cout << "Per dibuixar un rectangle, necessito que em diguis les coordenades de la cantonada superior esquerra i la cantonada inferior dreta." << endl;
    cout << "Cantonada superior esquerra:" <<endl;
    x1 = demanarCoordenada('X');
    y1 = demanarCoordenada('Y');

    cout << "Cantonada superior esquerra:" <<endl;
    x2 = demanarCoordenada('X');
    y2 = demanarCoordenada('Y');
}

void dibuixarRectangle(Window & w){
/*
    Pre: --
    Post: demana les dades necessaries per dibuixar un rectangle i el pinta a la finestra w.
    Param w: finestra en la que es pintara la figura.
*/
    float x1,y1,x2,y2;

    demanarDadesRectangle(x1,y1,x2,y2);

    w.rectangle(x1,y1,x2,y2);
}

void demanarDadesLinia(float & x1, float & y1, float & x2, float & y2){
/*
    Pre: --
    Post: s'entren per teclat les quatre dades necessaries per pintar una linia: les coordenades X i Y dels seus dos extrems.
    Param x1: coordenada X del primer punt demanat.
    Param y1: coordenada Y del primer punt demanat.
    Param x2: coordenada X del segon punt demanat.
    Param y2: coordenada Y del segon punt demanat.
*/
    cout << "Per dibuixar una linia, necessito que em diguis les coordenades dels seus dos extrems." << endl;
    cout << "Primer punt:" <<endl;
    x1 = demanarCoordenada('X');
    y1 = demanarCoordenada('Y');

    cout << "Segon punt:" <<endl;
    x2 = demanarCoordenada('X');
    y2 = demanarCoordenada('Y');
}

void dibuixarLinia(Window & w){
/*
    Pre: --
    Post: demana les dades necessaries per dibuixar una linia i la pinta a la finestra w.
    Param w: finestra en la que es pintara la figura.
*/
    float x1,y1,x2,y2;

    demanarDadesLinia(x1,y1,x2,y2);

    w.line(x1,y1,x2,y2);
}

void demanarDadesCercle(float & cx, float & cy, float & r){
/*
    Pre: --
    Post: s'entren per teclat les tres dades necessaries per pintar un cercle: les coordenades X i Y del seu centre i el radi.
    Param cx: coordenada X del centre demanat.
    Param cy: coordenada Y del centre demanat.
    Param r: radi demanat.
*/
    cout << "Per dibuixar una cercle, necessito que em diguis les coordenades del seu centre i el radi." << endl;
    cout << "Coordenades del centre:" <<endl;
    cx = demanarCoordenada('X');
    cy = demanarCoordenada('Y');

    cout << "Radi: ";
    cin >> r;
}

void dibuixarCercle(Window & w){
/*
    Pre: --
    Post: demana les dades necessaries per dibuixar un cercle o cercle emplenat i el pinta a la finestra w.
    Param w: finestra en la que es pintara la figura.
*/
    float cx,cy,r;

    demanarDadesCercle(cx,cy,r);

    w.circle(cx,cy,r);
}

void pintarFigura(Window & w, char s){
/*
    Pre: --
    Post: es demanen dades adicionals i es pinta una figura depenent de la opcio entrada.
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
    cout << "Hola. Diga'm quina figura et ve de gust dibuixar: " << endl;
    cout << "Les opcions son: " << endl << endl;
    mostrarMenu();
    cout << endl;

    char seleccio;
    cout << "Que tries? ";
    cin >> seleccio;

    if(seleccio != FI){

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
