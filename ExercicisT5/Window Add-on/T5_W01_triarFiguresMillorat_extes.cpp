#include <iostream>
#include "windowAddon/WindowAddon.h" //incluim la llibreria de la finestra.

using namespace std;

const int AMPLE_FINESTRA = 640;          //amplada en pixels de la finestra que obrirem.
const int ALT_FINESTRA = 480;            //altura en pixels de la finestra que obrirem.

const char FI = 'e';            //marca de fi.

//opcions de color.
const char COLOR_BLANC = 'B';
const char COLOR_NEGRE = 'n';
const char COLOR_VERMELL = 'v';
const char COLOR_VERD = 'V';
const char COLOR_BLAU = 'b';
const char COLOR_GROC = 'g';
const char COLOR_MAGENTA = 'm';
const char COLOR_CIAN = 'c';
const char COLOR_GRIS = 'G';

//opcions de figura.
const char OPCIO_RECTANGLE = 'r';
const char OPCIO_RECTANGLE_EMPLENAT = 'R';
const char OPCIO_LINIA = 'l';
const char OPCIO_CERCLE = 'c';
const char OPCIO_CERCLE_EMPLENAT = 'C';
const char OPCIO_TRIANGLE = 't';
const char OPCIO_TRIANGLE_EMPLENAT = 'T';
const char OPCIO_TALL_DE_PASTIS = 'p';
const char OPCIO_TALL_DE_PASTIS_EMPLENAT = 'P';


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

float demanarCoordenada(char coord){
/*
    Pre: --
    Post: es demana una coordenada per l'entrada estandard.
    Param coord: tipus de la coordenada que es demana.
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

void dibuixarRectangle(Window & w, const RGBColor & c, bool emplenat = false){
/*
    Pre: --
    Post: demana les dades necessaries per dibuixar un rectangle o rectangle emplenat i el pinta a la finestra w.
    Param w: finestra en la que es pintara la figura.
    Param c: color de la figura.
    Param emplenat (optional): determina si la figura es pinta per dins o no. Per defecte es fals.
*/
    float x1,y1,x2,y2;

    demanarDadesRectangle(x1,y1,x2,y2);

    if(emplenat) w.filled_rectangle(x1,y1,x2,y2,c);
    else w.rectangle(x1,y1,x2,y2,c);
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

void dibuixarLinia(Window & w, const RGBColor & c){
/*
    Pre: --
    Post: demana les dades necessaries per dibuixar una linia i la pinta a la finestra w.
    Param w: finestra en la que es pintara la figura.
    Param c: color de la figura.
*/
    float x1,y1,x2,y2;

    demanarDadesLinia(x1,y1,x2,y2);

    w.line(x1,y1,x2,y2,c);
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

void dibuixarCercle(Window & w, const RGBColor & c, bool emplenat = false){
/*
    Pre: --
    Post: demana les dades necessaries per dibuixar un cercle o cercle emplenat i el pinta a la finestra w.
    Param w: finestra en la que es pintara la figura.
    Param c: color de la figura.
    Param emplenat (optional): determina si la figura es pinta per dins o no. Per defecte es fals.
*/
    float cx,cy,r;

    demanarDadesCercle(cx,cy,r);

    if(emplenat) w.filled_circle(cx,cy,r,c);
    else w.circle(cx,cy,r,c);
}

void demanarDadesTriangle(float & x1, float & y1, float & x2, float & y2, float & x3, float & y3){
/*
    Pre: --
    Post: s'entren per teclat les sis dades necessaries per pintar un triangle: les coordenades X i Y dels seus tres vertex.
    Param x1: coordenada X del primer vertex demanat.
    Param y1: coordenada Y del primer vertex demanat.
    Param x2: coordenada X del segon vertex demanat.
    Param y2: coordenada Y del segon vertex demanat.
    Param x3: coordenada X del tercer vertex demanat.
    Param y3: coordenada Y del tercer vertex demanat.
*/
    cout << "Per dibuixar un triangle, necessito que em diguis les coordenades dels seus tres vertex." << endl;
    cout << "Primer vertex:" <<endl;
    x1 = demanarCoordenada('X');
    y1 = demanarCoordenada('Y');

    cout << "Segon vertex:" <<endl;
    x2 = demanarCoordenada('X');
    y2 = demanarCoordenada('Y');

    cout << "Tercer vertex:" <<endl;
    x3 = demanarCoordenada('X');
    y3 = demanarCoordenada('Y');
}

void dibuixarTriangle(Window & w, const RGBColor & c, bool emplenat = false){
/*
    Pre: --
    Post: demana les dades necessaries per dibuixar un triangle o triangle emplenat i el pinta a la finestra w.
    Param w: finestra en la que es pintara la figura.
    Param c: color de la figura.
    Param emplenat (optional): determina si la figura es pinta per dins o no. Per defecte es fals.
*/
    float x1,y1,x2,y2,x3,y3;

    demanarDadesTriangle(x1,y1,x2,y2,x3,y3);

    if(emplenat) w.filled_triangle(x1,y1,x2,y2,x3,y3,c);
    else w.triangle(x1,y1,x2,y2,x3,y3,c);
}

void demanarDadesTallDePastis(float & cx, float & cy, float & r, float & st, float & dt){
/*
    Pre: --
    Post: s'entren per teclat les cinc dades necessaries per pintar un tall de pastis: les coordenades X i Y del seu centre, el radi, l'angle d'inici i l'increment d'angle del arc.
    Param cx: coordenada X del centre del tall de pastis demanat.
    Param cy: coordenada Y del centre del tall de pastis demanat.
    Param r: radi demanat.
    Param st: angle d'inici demanat.
    Param dt: increment d'angle demanat.
*/
    cout << "Per dibuixar un tall de pastis, necessito que em diguis les coordenades dels seu centre, el radi, l'angle d'inici i l'increment d'angle del arc." << endl;
    cout << "Coordenades del centre:" <<endl;
    cx = demanarCoordenada('X');
    cy = demanarCoordenada('Y');

    cout << "Radi: ";
    cin >> r;
    cout << "Angle d'inici (en graus): ";
    cin >> st;
    cout << "Increment d'angle (en graus): ";
    cin >> dt;
}

void dibuixarTallDePastis(Window & w, const RGBColor & c, bool emplenat = false){
/*
    Pre: --
    Post: demana les dades necessaries per dibuixar un tall de pastis o un tall de pastis emplenat i el pinta a la finestra w.
    Param w: finestra en la que es pintara la figura.
    Param c: color de la figura.
    Param emplenat (optional): determina si la figura es pinta per dins o no. Per defecte es fals.
*/
    float cx,cy,r,st,dt;

    demanarDadesTallDePastis(cx,cy,r,st,dt);

    if(emplenat) w.filled_pieslice(cx,cy,r,st,dt,c);
    else w.pieslice(cx,cy,r,st,dt,c);
}

void dibuixarInterrogant(Window & w, const RGBColor & c){
/*
    Pre: --
    Post: pinta un interrogant a la finestra w.
    Param w: finestra en la que es pintara la figura.
    Param c: color de la figura.
*/
    //arc amb centre 100 unitats per sobre del centre de la pantalla, que comença a l'angle -90
    //i te un increment d'angle de 225 graus, de color 'c' i amb gruix de linia 5.
    w.arc(AMPLE_FINESTRA/2, ALT_FINESTRA/2+100, 50, -90, 225, c, 5);
    //linia que surt del extrem inferior del arc i va cap abaix, amb el mateix color i amplada.
    w.line(AMPLE_FINESTRA/2, ALT_FINESTRA/2+50, AMPLE_FINESTRA/2, ALT_FINESTRA/2-50, c, 5);
    //punt de la interrogacio.
    w.filled_circle(AMPLE_FINESTRA/2, ALT_FINESTRA/2-60, 5, c);
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
