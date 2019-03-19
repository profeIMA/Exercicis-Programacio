#include <iostream>
#include "windowAddon/WindowAddon.h" //incluim la llibreria de la finestra.

using namespace std;

const int AMPLE_FINESTRA = 640;     //amplada en pixels de la finestra que obrirem.
const int ALT_FINESTRA = 480;       //altura en pixels de la finestra que obrirem.

void dividirQuadrat(Window & w, Point2D p1, Point2D p2, int n){
/*
    Pre: p1 i p2 son la cantonada superior esquerra i la cantonada inferior dreta d'un quadrat.
    Post: es subdivideix el quadrat en 4^n quadrats iguals continguts dins del quadrat original.
    Param w: finestra on s'executaran les operacions de pintar.
    Param p1: punt superior esquerre del quadrat.
    Param p2: punt inferior dret del quadrat.
    Param n: nivell de profunditat.
*/
    if(n>0){
        double costat = p2.x - p1.x;
        Point2D centre(p1.x+costat/2, p1.y-costat/2);

        //w.changeDrawingThickness(n); //la linia s'aprima quan la profunditat va decreixent.

        w.line(centre.x, p2.y, centre.x, p1.y); //linia vertical de la creu de separacio.
        w.line(p1.x, centre.y, p2.x, centre.y); //linia horitzontal de la creu de separacio.

        if(n > 1){ //permet estalviar-nos crides innecessaries.
            dividirQuadrat(w, p1, centre, n-1); //quadrat superior esquerre.
            dividirQuadrat(w, Point2D(centre.x, p1.y), Point2D(p2.x,centre.y), n-1); //quadrat superior dret.
            dividirQuadrat(w, Point2D(p1.x, centre.y), Point2D(centre.x, p2.y), n-1); //quadrat inferior esquerre.
            dividirQuadrat(w, centre, p2, n-1); //quadrat inferior dret.
        }
    }
}

int main()
{

    int mida, profunditat; //mida del costat del quadrat i nombre de subdivisions recursives que volem efectuar.

    cout << "Hola! Quina mida vols que tingui el costat del quadrat?" << endl;
    cin >> mida;
    cout << "Quina profunditat vols?" << endl;
    cin >> profunditat;

    if(profunditat < 0){
        cerr << "No es permeten profunditats negatives" << endl;
    }
    else{//si tenim profunditat 0 o positiva.

        Window finestra(AMPLE_FINESTRA, ALT_FINESTRA); //finestra de mida definida amb fons blanc i color de dibuix negre. Els colors son aixi per defecte, i no hem especificat canviar-los.

        Point2D p1((AMPLE_FINESTRA-mida)/2, (ALT_FINESTRA+mida)/2); //cantonada superior esquerra.
        Point2D p2((AMPLE_FINESTRA+mida)/2, (ALT_FINESTRA-mida)/2); //cantonada inferior dreta.

        finestra.rectangle(p1, p2); //dibuixem el contorn del quadrat inicial.

        dividirQuadrat(finestra, p1, p2, profunditat); //subdividim aquest quadrat i els seus subquadrats de manera recursiva.

        finestra.waitWindowCloseButton(); //esperem a que l'usuari tanqui la finestra.

    }

    return 0;
}
