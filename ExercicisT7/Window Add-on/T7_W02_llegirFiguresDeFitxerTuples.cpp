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

struct Cercle{
    Point2D c;
    float r;
};

struct Rectangl{ //no la podem anomenar 'Rectangle' ja que existeix una funcio anomenada Rectangle() a la llibreria wingdi i el CodeBlocks a Windows la fa servir.
    Point2D p1,p2;
};

typedef struct Rectangl Linia; //una linia i un rectangle tenen els mateixos elements.

Point2D llegirPuntDeFitxer(ifstream & f){
/*
    Pre: f.is_open
    Post: es llegeixen unes coordenades (dos nombres en format de coma flotant) del fitxer f, i es retorna el punt resultant.
    Param f: fitxer del que es vol llegir.
    Return: Point2D llegit.
*/
    Point2D p;

    f >> p.x;
    f >> p.y;

    return p;
}

Cercle llegirCercleDeFitxer(ifstream & f){
/*
    Pre: f.is_open
    Post: es llegeixen del fitxer f les dades necessaries per pintar un cercle, i es retorna una estructura que les emmagatzema.
    Param f: fitxer del que es vol llegir.
    Return: Cercle llegit.
*/
    Cercle c;
    c.c = llegirPuntDeFitxer(f); //c.c = centre del cercle
    f >> c.r;

    return c;
}

Rectangl llegirRectangleDeFitxer(ifstream & f){
/*
    Pre: f.is_open
    Post: es llegeixen del fitxer f les dades necessaries per pintar un rectangle, i es retorna una estructura que les emmagatzema.
    Param f: fitxer del que es vol llegir.
    Return: Rectangle llegit.
*/
    Rectangl r;
    r.p1 = llegirPuntDeFitxer(f);
    r.p2 = llegirPuntDeFitxer(f);

    return r;
}

Linia llegirLiniaDeFitxer(ifstream & f){
/*
    Pre: f.is_open
    Post: es llegeixen del fitxer f les dades necessaries per pintar una linia, i es retorna una estructura que les emmagatzema.
    Param f: fitxer del que es vol llegir.
    Return: Linia llegida.
*/
    return llegirRectangleDeFitxer(f);
}

bool dibuixarFiguraDeFitxer(Window & w, ifstream & f, char tipus){
/*
    Pre: f.is_open
    Post: en funcio del tipus de figura, llegeix les dades del fitxer i pinta la figura.
    Param w: finestra en la que es dibuixara la figura.
    Param f: fitxer d'on es llegiran les dades de la figura.
    Param tipus: tipus de figura que es vol dibuixar.
    Return: bool, cert si hi ha error de tipus de figura, fals altrament.
*/
    if(tipus == TIPUS_CERCLE){
        Cercle c = llegirCercleDeFitxer(f);
        w.circle(c.c.x, c.c.y, c.r);
    }
    else if(tipus == TIPUS_RECTANGLE){
        Rectangl r = llegirRectangleDeFitxer(f);
        w.rectangle(r.p1.x, r.p1.y, r.p2.x, r.p2.y);
    }
    else if(tipus == TIPUS_LINIA){
        Linia l = llegirLiniaDeFitxer(f);
        w.line(l.p1.x, l.p1.y, l.p2.x, l.p2.y);
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

	fitxer.open(nomFitxer.c_str()); //obrim el fitxer del que llegirem les dades. Cal fer c_str() ja que el paràmetre de la crida requereix que sigui un const char * i no una string.

	if(fitxer.is_open()){ //si el fitxer s'ha obert correctament.

        bool error = false;

        char tipus_figura;
        fitxer >> tipus_figura; //llegim el primer caracter, que sera el tipus de la figura.

        Window finestra(AMPLE_FINESTRA, ALT_FINESTRA);

        while(!fitxer.eof() && !error){ //mentre no acabem i no trobem cap error (als fitxers d'exemple no n'hi hauran).
            error = dibuixarFiguraDeFitxer(finestra, fitxer, tipus_figura); //llegim la resta de dades de la figura del fitxer, la dibuixem i detectem errors.
            fitxer >> tipus_figura; //llegim el seguent tipus de figura.
        }

        fitxer.close(); //tanquem el fitxer, ja hem acabat amb ell.

        finestra.waitWindowCloseButton(); //esprem a que l'usuari apreti el boto de tancar la finestra.
	}
	else cout << "No s'ha pogut obrir el fitxer '" << nomFitxer << "'. Torna-ho a probar." << endl;

    return 0;
}
