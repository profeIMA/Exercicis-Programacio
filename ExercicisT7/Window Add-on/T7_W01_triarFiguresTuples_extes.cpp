#include <iostream>
#include "windowAddon/WindowAddon.h" //incluim la llibreria de la finestra.

using namespace std;

const int AMPLE_FINESTRA = 640; //amplada en pixels de la finestra que obrirem.
const int ALT_FINESTRA = 480;   //altura en pixels de la finestra que obrirem.

const char FI = 'e';            //marca de fi

///constants que defineixen el codi de les opcions de color que el nostre programa pot processar.
const char COLOR_BLANC = 'B';
const char COLOR_NEGRE = 'n';
const char COLOR_VERMELL = 'v';
const char COLOR_VERD = 'V';
const char COLOR_BLAU = 'b';
const char COLOR_GROC = 'g';
const char COLOR_MAGENTA = 'm';
const char COLOR_CIAN = 'c';
const char COLOR_GRIS = 'G';

///constants que defineixen el codi de les opcions de figures que el nostre programa pot processar.
const char OPCIO_RECTANGLE = 'r';
const char OPCIO_RECTANGLE_EMPLENAT = 'R';
const char OPCIO_LINIA = 'l';
const char OPCIO_CERCLE = 'c';
const char OPCIO_CERCLE_EMPLENAT = 'C';
const char OPCIO_TRIANGLE = 't';
const char OPCIO_TRIANGLE_EMPLENAT = 'T';
const char OPCIO_TALL_DE_PASTIS = 'p';
const char OPCIO_TALL_DE_PASTIS_EMPLENAT = 'P';



struct Cercle{
    Point2D c;
    float r;
};

struct Rectangl{ //no la podem anomenar 'Rectangle' ja que existeix una funcio anomenada Rectangle() a la llibreria wingdi i el CodeBlocks a Windows la fa servir.
    Point2D p1,p2;
};

typedef struct Rectangl Linia; //una linia i un rectangle tenen els mateixos elements.

struct Triangle{
    Point2D p1,p2,p3;
};

struct Tall_Pastis{
    Point2D c;
    float r, start, delta;
};



void mostrarMenu(){
/*
    Pre: --
    Post: es mostra per sortida estandard el menu d'opcions de figures que es poden dibuixar.
*/
    cout << OPCIO_RECTANGLE << "    : Dibuixar rectangle" << endl;
    cout << OPCIO_RECTANGLE_EMPLENAT << "    : Dibuixar rectangle emplenat" << endl;
    cout << OPCIO_LINIA << "    : Dibuixar linia" << endl;
    cout << OPCIO_CERCLE << "    : Dibuixar cercle" << endl;
    cout << OPCIO_CERCLE_EMPLENAT << "    : Dibuixar cercle emplenat" << endl;
    cout << OPCIO_TRIANGLE << "    : Dibuixar triangle" << endl;
    cout << OPCIO_TRIANGLE_EMPLENAT << "    : Dibuixar triangle emplenat" << endl;
    cout << OPCIO_TALL_DE_PASTIS << "    : Dibuixar tall de pastis" << endl;
    cout << OPCIO_TALL_DE_PASTIS_EMPLENAT << "    : Dibuixar tall de pastis emplenat" << endl;
}

void mostrarColors(){
/*
    Pre: --
    Post: es mostra per sortida estandard el menu d'opcions de colors que es poden triar.
*/
    cout << COLOR_BLANC << "    : Blanc" << endl;
    cout << COLOR_NEGRE << "    : Negre" << endl;
    cout << COLOR_VERMELL << "    : Vermell" << endl;
    cout << COLOR_VERD << "    : Verd" << endl;
    cout << COLOR_BLAU << "    : Blau" << endl;
    cout << COLOR_GROC << "    : Groc" << endl;
    cout << COLOR_MAGENTA << "    : Magenta" << endl;
    cout << COLOR_CIAN << "    : Cian" << endl;
    cout << COLOR_GRIS << "    : Gris" << endl;
}

RGBColor demanarColor(){
/*
    Pre: --
    Post: es demana per entrada estandard el color de la figura que es vol pintar.
    Return: el color seleccionat.
*/
    cout << "De quin color vols la figura?" << endl;
    mostrarColors();
    char c;
    cout << "Color: ";
    cin >> c;

    RGBColor color;

    switch(c){
        case COLOR_BLANC:
            color = WHITE;
            break;
        case COLOR_VERMELL:
            color = RED;
            break;
        case COLOR_VERD:
            color = GREEN;
            break;
        case COLOR_BLAU:
            color = BLUE;
            break;
        case COLOR_GROC:
            color = YELLOW;
            break;
        case COLOR_MAGENTA:
            color = MAGENTA;
            break;
        case COLOR_CIAN:
            color = CIAN;
            break;
        case COLOR_GRIS:
            color = GRAY;
            break;
        //case COLOR_NEGRE: //si ens entren un caracter desconegut o la opcio del color negre, el color sera negre.
        default:
            color = BLACK;
            break;
    }

    return color;
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

void dibuixarRectangle(Window & w, const RGBColor & color, bool emplenat = false){
/*
    Pre: --
    Post: demana les dades necessaries per dibuixar un rectangle o rectangle emplenat i el pinta a la finestra w.
    Param w: finestra en la que es pintara la figura.
    Param color: color de la figura.
    Param emplenat (optional): determina si la figura es pinta per dins o no. Per defecte es fals.
*/
    Rectangl r = demanarRectangle();

    if(emplenat) w.filled_rectangle(r.p1, r.p2, color); //recordem que la finestra ens permet dibuixar usant la struct Point2D.
    else w.rectangle(r.p1, r.p2, color);
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

void dibuixarLinia(Window & w, const RGBColor & color){
/*
    Pre: --
    Post: demana les dades necessaries per dibuixar una linia i la pinta a la finestra w.
    Param w: finestra en la que es pintara la figura.
    Param color: color de la figura.
*/
    Linia l = demanarLinia();

    w.line(l.p1, l.p2, color);  //recordem que la finestra ens permet dibuixar usant la struct Point2D.
}

Cercle demanarCercle(){
/*
    Pre: --
    Post: s'entren per teclat les tres dades necessaries per pintar un cercle: les coordenades X i Y del seu centre i el radi d'aquest.
    Return: el cercle entrat.
*/
    Cercle c;

    cout << "Per dibuixar una cercle, necessito que em diguis les coordenades del seu centre i el radi." << endl;
    cout << "Coordenades del centre:" <<endl;
    c.c = demanarPunt();

    cout << "Radi: ";
    cin >> c.r;

    return c;
}

void dibuixarCercle(Window & w, const RGBColor & color, bool emplenat = false){
/*
    Pre: --
    Post: demana les dades necessaries per dibuixar un cercle o cercle emplenat i el pinta a la finestra w.
    Param w: finestra en la que es pintara la figura.
    Param color: color de la figura.
    Param emplenat (optional): determina si la figura es pinta per dins o no. Per defecte es fals.
*/
    Cercle c = demanarCercle();

    if(emplenat) w.filled_circle(c.c, c.r, color); //recordem que la finestra ens permet dibuixar usant la struct Point2D.
    else w.circle(c.c, c.r, color);
}

Triangle demanarTriangle(){
/*
    Pre: --
    Post: s'entren per teclat les sis dades necessaries per pintar un triangle: les coordenades X i Y dels seus tres vertex.
    Return: el triangle entrat.
*/
    Triangle t;

    cout << "Per dibuixar un triangle, necessito que em diguis les coordenades dels seus tres vertex." << endl;
    cout << "Primer vertex:" <<endl;
    t.p1 = demanarPunt();

    cout << "Segon vertex:" <<endl;
    t.p2 = demanarPunt();

    cout << "Tercer vertex:" <<endl;
    t.p3 = demanarPunt();

    return t;
}

void dibuixarTriangle(Window & w, const RGBColor & color, bool emplenat = false){
/*
    Pre: --
    Post: demana les dades necessaries per dibuixar un triangle o triangle emplenat i el pinta a la finestra w.
    Param w: finestra en la que es pintara la figura.
    Param ccolor: color de la figura.
    Param emplenat (optional): determina si la figura es pinta per dins o no. Per defecte es fals.
*/
    Triangle t = demanarTriangle();

    if(emplenat) w.filled_triangle(t.p1, t.p2, t.p3, color);
    else w.triangle(t.p1, t.p2, t.p3, color);
}

Tall_Pastis demanarDadesTallDePastis(){
/*
    Pre: --
    Post: s'entren per teclat les cinc dades necessaries per pintar un tall de pastis: les coordenades X i Y del seu centre, el radi, l'angle d'inici i l'increment d'angle del arc.
    Return: el tall de pastis entrat.
*/
    Tall_Pastis tp;

    cout << "Per dibuixar un tall de pastis, necessito que em diguis les coordenades dels seu centre, el radi, l'angle d'inici i l'increment d'angle del arc." << endl;
    cout << "Coordenades del centre:" <<endl;
    tp.c = demanarPunt();

    cout << "Radi: ";
    cin >> tp.r;
    cout << "Angle d'inici (en graus): ";
    cin >> tp.start;
    cout << "Increment d'angle (en graus): ";
    cin >> tp.delta;

    return tp;
}

void dibuixarTallDePastis(Window & w, const RGBColor & color, bool emplenat = false){
/*
    Pre: --
    Post: demana les dades necessaries per dibuixar un tall de pastis o un tall de pastis emplenat i el pinta a la finestra w.
    Param w: finestra en la que es pintara la figura.
    Param color: color de la figura.
    Param emplenat (optional): determina si la figura es pinta per dins o no. Per defecte es fals.
*/
    Tall_Pastis tp = demanarDadesTallDePastis();

    if(emplenat) w.filled_pieslice(tp.c ,tp.r, tp.start, tp.delta, color);
    else w.pieslice(tp.c ,tp.r, tp.start, tp.delta, color);
}

void dibuixarInterrogant(Window & w, const RGBColor & color){
/*
    Pre: --
    Post: pinta un interrogant a la finestra w.
    Param w: finestra en la que es pintara la figura.
    Param color: color de la figura.
*/
    //arc amb centre 100 unitats per sobre del centre de la pantalla, que comença a l'angle -90
    //i te un increment d'angle de 225 graus, de color 'color' i amb gruix de linia 5.
    w.arc(AMPLE_FINESTRA/2, ALT_FINESTRA/2+100, 50, -90, 225, color, 5);
    //linia que surt del extrem inferior del arc i va cap abaix, amb el mateix color i amplada.
    w.line(AMPLE_FINESTRA/2, ALT_FINESTRA/2+50, AMPLE_FINESTRA/2, ALT_FINESTRA/2-50, color, 5);
    //punt de la interrogacio.
    w.filled_circle(AMPLE_FINESTRA/2, ALT_FINESTRA/2-60, 5, color);
}

void pintarFigura(Window & w, char s){
/*
    Pre: --
    Post: es demanen dades addicionals i es pinta una figura depenent de la opcio entrada.
    Param w: finestra on es pintara la figura.
    Param s: opcio entrada.
*/
    RGBColor c = demanarColor();

    switch(s){
        case OPCIO_RECTANGLE:
            dibuixarRectangle(w,c);
            break;
        case OPCIO_RECTANGLE_EMPLENAT:
            dibuixarRectangle(w,c,true);
            break;
        case OPCIO_LINIA:
            dibuixarLinia(w,c);
            break;
        case OPCIO_CERCLE:
            dibuixarCercle(w,c);
            break;
        case OPCIO_CERCLE_EMPLENAT:
            dibuixarCercle(w,c,true);
            break;
        case OPCIO_TRIANGLE:
            dibuixarTriangle(w,c);
            break;
        case OPCIO_TRIANGLE_EMPLENAT:
            dibuixarTriangle(w,c,true);
            break;
        case OPCIO_TALL_DE_PASTIS:
            dibuixarTallDePastis(w,c);
            break;
        case OPCIO_TALL_DE_PASTIS_EMPLENAT:
            dibuixarTallDePastis(w,c,true);
            break;
        default: //opcio desconeguda
            dibuixarInterrogant(w,c);
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
