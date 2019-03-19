/// Problema: Donats dos punts inicials, volem comprovar si un tercer punt donat esta contingut dins del segment generat al unir-los.
/// Solucio 1: De manera visual, dibuixem tots els elements i comprovem si el tercer punt esta contingut dins del segment.
/// Solucio 2: De manera analitica, comprovem si el punt esta contingut dins del segment.

#include <iostream>
#include "windowAddon/WindowAddon.h" //incluim la llibreria de la finestra.

using namespace std;

const int AMPLE_FINESTRA = 640; //amplada en pixels de la finestra que obrirem.
const int ALT_FINESTRA = 480;   //altura en pixels de la finestra que obrirem.

int main()
{
    ///******* Demanem les dades i les entrem per teclat *******///

    int ax,ay,bx,by,cx,cy;

    cout << "Aquest programa determina si donats dos punts que generen un segment i donat un tercer punt addicional aquest tercer esta contingut dins del segment." << endl << endl;

    /// Demanem i entrem les dades del primer punt ///
    cout << "Entra'm les dades del primer punt: " << endl;
    cout << "X: ";
    cin >> ax;
    cout << "Y: ";
    cin >> ay;
    cout << "Molt be! Ja el tinc." << endl << endl;

    /// Demanem i entrem les dades del segon punt ///
    cout << "Entra'm les dades del segon punt: " << endl;
    cout << "X: ";
    cin >> bx;
    cout << "Y: ";
    cin >> by;
    cout << "D'acord! Ja el tinc." << endl;

    cout << "Ara ja puc generar el segment. Seguim" << endl << endl;

    /// Demanem i entrem les dades del tercer punt ///
    cout << "Entra'm les dades del punt que vols comprovar: " << endl;
    cout << "X: ";
    cin >> cx;
    cout << "Y: ";
    cin >> cy;
    cout << "Perfecte! Anem a comprovar si aquest punt esta o no dins del segment." << endl << endl;

    ///*********************************************************///



    ///************* Suport visual (Solucio 1) *****************///

    Window finestra(AMPLE_FINESTRA, ALT_FINESTRA); //finestra de mida definida amb fons blanc i color de dibuix negre. Els colors son aixi per defecte, i no hem especificat canviar-los.

    ///Pintarem els punts com a cercles, ja que si els fessim com a pixels individuals poden ser dificils de veure.
    int radi = 3; //3 pixels de radi.

    finestra.line(ax,ay,bx,by,GREEN); //primer pintem la linia (de color verd), aixi els punts quedaran dibuixats a sobre d'ella.
    finestra.circle(ax,ay,radi);
    finestra.circle(bx,by,radi);
    finestra.circle(cx,cy,radi,RED); //pintem el punt entrat de color vermell, per diferenciar-lo.

    finestra.waitWindowCloseButton(); //ordre d'esperar fins que es premi el boto de tancar la finestra.

    ///*********************************************************///


    ///La solucio 1 pot estar be si el que volem es passar el rato, pero com podeu comprovar no es ni precissa ni efectiva,
    ///ja que requereix d'un huma per a poder ser realitzada. Anem amb la segona solucio. El que farem sera comprovar si els
    ///vectors AB i AC son colinears (producte vecotrial = 0, vector nul). Si ho son, vol dir que els 3 punts
    ///estan alineats, i ara faltaria comprovar si el tercer punt es troba enmig dels dos primers.
    ///font: https://www.lucidar.me/en/mathematics/check-if-a-point-belongs-on-a-line-segment/

    ///********* Calcul de interseccio (Solucio 2) *************///

    //components dels vectors AB i AC
    int abx = bx-ax, aby = by-ay, acx = cx-ax, acy = cy-ay;

    //com estem treballant en dues dimensions, el producte vectorial es redueix a un simple nombre (la component z del vector tridimensional resultant).
    //Aixo es degut a que les altrs components es multipliquen per z i per tant, per 0. Doncs si es vector nul, depen unicament de la component z
    //del vector tridimensional, que es calcula aixi.
    int prod_vect = abx*acy - aby*acx;

    if(prod_vect != 0) { //si els vectors no son colinears
        cout << "El tercer punt no es troba dins del segment." << endl;
    }
    else{
        //si els vectors son colinears, cal comprovar si el punt es troba dins del segment AB. Recordem que el producte escalar
        //es pot interpretar com el modul d'un dels vectors multiplicat per la projeccio d'aquest sobre l'altre vector. Per tant,
        //aixo ens indicara si aquesta projeccio (Kac) sobresurt del segment.

        int Kac = abx*acx + aby+acy; //AB·AC
        int Kab = abx*abx + aby+aby; //AB·AB

        if( Kac < 0 || Kac > Kab ){ //si c esta fora del segment.
            cout << "El tercer punt no es troba dins del segment." << endl;
        }
        else{ //si c no esta fora del segment (esta a dins).
            cout << "Eureka! El tercer punt es troba dins del segment!" << endl;
        }
    }

    cout << "S'ha acabat!" << endl;

    return 0;
}
