#include <iostream>
#include <fstream>
#include "windowAddon/WindowAddon.h" //incluim la llibreria de la finestra.

using namespace std;

const int AMPLE_FINESTRA = 640;          //amplada en pixels de la finestra que obrirem.
const int ALT_FINESTRA = 480;            //altura en pixels de la finestra que obrirem.

///constants que defineixen el codi de les opcions que el nostre programa pot processar.
const char TIPUS_CERCLE = 'c';
const char TIPUS_RECTANGLE = 'r';
const char TIPUS_LINIA = 'l';


void llegirCoordenadaDeFitxer(ifstream & f, float & x, float & y){
/*
    Pre: f.is_open
    Post: es llegeixen unes coordenades (dos nombres en format de coma flotant) del fitxer f, i es retornen per referencia.
    Param f: fitxer del que es vol llegir.
    Param x: coordenada X que es vol llegir.
    Param y: coordenada Y que es vol llegir.
*/
    f >> x;
    f >> y;
}

void llegirCercleDeFitxer(ifstream & f, float & cx, float & cy, float & r){
/*
    Pre: f.is_open
    Post: es llegeixen del fitxer f les dades necessaries per pintar un cercle, i es retornen per referencia.
    Param f: fitxer del que es vol llegir.
    Param cx: coordenada X del centre del cercle que es vol llegir.
    Param cy: coordenada Y del centre del cercle que es vol llegir.
*/
    llegirCoordenadaDeFitxer(f,cx,cy);
    f >> r;
}

void llegirRectangleDeFitxer(ifstream & f, float & x1, float & y1, float & x2, float & y2){
/*
    Pre: f.is_open
    Post: es llegeixen del fitxer f les dades necessaries per pintar un rectangle, i es retornen per referencia.
    Param f: fitxer del que es vol llegir.
    Param x1: coordenada X de la cantonada superior esquerra del rectangle que es vol llegir.
    Param y1: coordenada Y de la cantonada superior esquerra del rectangle que es vol llegir.
    Param x2: coordenada X de la cantonada inferior dreta del rectangle que es vol llegir.
    Param y2: coordenada Y de la cantonada inferior dreta del rectangle que es vol llegir.
*/
    llegirCoordenadaDeFitxer(f,x1,y1);
    llegirCoordenadaDeFitxer(f,x2,y2);
}

void llegirLiniaDeFitxer(ifstream & f, float & x1, float & y1, float & x2, float & y2){
/*
    Pre: f.is_open
    Post: es llegeixen del fitxer f les dades necessaries per pintar una linia, i es retornen per referencia.
    Param f: fitxer del que es vol llegir.
    Param x1: coordenada X del primer extrem de la linia que es vol llegir.
    Param y1: coordenada Y del primer extrem de la linia que es vol llegir.
    Param x2: coordenada X del l'altre extrem de la linia que es vol llegir.
    Param y2: coordenada Y del l'altre extrem de la linia que es vol llegir.
*/
    llegirRectangleDeFitxer(f,x1,y1,x2,y2);
}

bool dibuixarFiguraDeFitxer(Window & w, ifstream & f, char tipus){
/*
    Pre: f.is_open
    Post: en funcio del tipus de figura, llegeix les dades del fitxer i pinta aquesta figura.
    Param w: finestra en la que es dibuixara la figura.
    Param f: fitxer d'on es llegiran les dades de la figura.
    Param tipus: tipus de figura que s'ha de llegir del fitxer i dibuixar.
    Return: bool, cert si hi ha error de tipus de figura, fals altrament.
*/
    if(tipus == TIPUS_CERCLE){
        float cx,cy,r;
        llegirCercleDeFitxer(f,cx,cy,r);
        w.circle(cx,cy,r);
    }
    else if(tipus == TIPUS_RECTANGLE){
        float x1,y1,x2,y2;
        llegirRectangleDeFitxer(f,x1,y1,x2,y2);
        w.rectangle(x1,y1,x2,y2);
    }
    else if(tipus == TIPUS_LINIA){
        float x1,y1,x2,y2;
        llegirLiniaDeFitxer(f,x1,y1,x2,y2);
        w.line(x1,y1,x2,y2);
    }
    else return true;

    return false;
}

int main()
{
    cout << "Entra el nom del fitxer que conte les figures: ";

    string nomFitxer;
    cin >> nomFitxer;

    ifstream fitxer;

	fitxer.open(nomFitxer.c_str()); //obrim el fitxer del que llegirem les dades. Cal fer c_str() ja que el parametre de la crida requereix que sigui un const char * i no una string.

	if(fitxer.is_open()){ //si el fitxer s'ha obert correctament.

        bool error = false;

        char tipus_figura;
        fitxer >> tipus_figura; //llegim el primer caracter, que sera el tipus de la figura.

        Window finestra(AMPLE_FINESTRA, ALT_FINESTRA);

        while(!fitxer.eof() && !error){ //mentre no acabem i no trobem cap error (als fitxers d'exemple no hi haura errors).
            error = dibuixarFiguraDeFitxer(finestra, fitxer, tipus_figura); //llegim la resta de dades de la figura del fitxer, la dibuixem i detectem errors.
            fitxer >> tipus_figura; //llegim el seguent tipus de figura.
        }

        fitxer.close(); //tanquem el fitxer, ja hem acabat amb ell.

        finestra.waitWindowCloseButton(); //esprem a que l'usuari apreti el boto de tancar la finestra.
	}
	else cout << "No s'ha pogut obrir el fitxer " << nomFitxer << ". Torna-ho a probar." << endl;

    return 0;
}
