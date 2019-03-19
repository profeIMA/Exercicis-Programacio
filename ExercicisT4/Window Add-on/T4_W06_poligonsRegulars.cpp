#include <iostream>
#include "windowAddon/WindowAddon.h" //incluim la llibreria de la finestra.
#include <cmath>

const int AMPLE_FINESTRA = 640;          //amplada en pixels de la finestra que obrirem.
const int ALT_FINESTRA = 480;            //altura en pixels de la finestra que obrirem.

using namespace std;

int main()
{
    int n_costats;
    double radi;

    cout << "Diga'm el nombre de costats del poligon: ";
    cin >> n_costats;

    if(n_costats < 3){
        cerr << "Error, no puc mostrar un poligon de menys de 3 costats." <<endl;
    }
	else{

		cout << "Ara diga'm el radi del cercle que circumscriu el poligon que vols que dibuixi: ";
		cin >> radi;

		cout << "Molt be! Deixa'm que et dibuixi el poligon que m'has demanat..." <<endl;

		double mida_costat = 2*radi*sin(PI/n_costats); //longitud dels costats del poligon. Font: https://www.mathopenref.com/polygonsides.html
		double angle_per_costat = 180 - ((n_costats-2)*180)/n_costats; //angle entre dos costats del poligon. Font: https://www.dummies.com/education/math/geometry/interior-and-exterior-angles-of-a-polygon/

		Window finestra(AMPLE_FINESTRA,ALT_FINESTRA); //finestra de mida definida amb fons blanc i color de dibuix negre. Els colors son aixi per defecte, i no hem especificat canviar-los.

		finestra.t_setPos((AMPLE_FINESTRA-mida_costat)/2, ALT_FINESTRA/2-radi); //fiquem la tortuga una mica abaix a la esquerra del centre de la pantalla, de manera que el circumcentre del poligon quedi centrat.

		int comptador = 0; //comptador de costats dibuixats.

		while(comptador < n_costats){ //mentre ens quedin costats per pintar.

			finestra.t_forward(mida_costat); //pintem el costat.
			finestra.t_left(angle_per_costat); //girem per fer l'angle d'aquest costat.

			comptador++;
		}

		finestra.waitWindowCloseButton(); //esperem a que l'usuari premi el boto de tancar la finestra.
	}

    return 0;
}
