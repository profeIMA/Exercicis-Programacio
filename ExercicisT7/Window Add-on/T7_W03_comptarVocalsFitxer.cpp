#include <string>                    //string
#include <iostream>                  //cin i cout
#include <fstream>                   //tractament de fitxers
#include <iomanip>                   //manipulacio del cout
#include <sstream>                   //tractament d'strings
#include "windowAddon/WindowAddon.h" //incluim la llibreria de la finestra.

using namespace std;

const int NUM_VOCALS = 5;                                                               //nombre de vocals.
const char VOCALS[NUM_VOCALS] = { 'A','E','I','O','U' };                                //array amb les vocals.
const int NUM_COLORS = 7;                                                               //nombre de colors.
const RGBColor COLORS[NUM_COLORS] = { RED, MAGENTA, BLUE, CIAN, GREEN, YELLOW, BLACK }; //array amb els colors.
const float VOLTA_COMPLETA = 360;                                                       //graus d'una volta completa.

const int AMPLE_FINESTRA = 600;     //amplada en pixels de la finestra que obrirem
const int ALT_FINESTRA = 600;       //altura en pixels de la finestra que obrirem
const float RADI = 150;             //radi del grafic de pastis

bool esVocal(char c) {
/*
    Pre: --
    Post: retorna cert si el caracter entrar es qualsevol vocal del alfabet angles, tant en majuscula com en minuscula, fals altrament.
    Param c: caracter a avaluar.
*/
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}


bool esMajuscula(char c) {
/*
    Pre: --
    Post: retorna cert si el caracter entrat es una lletra majuscula del alfabet angles, fals altrament.
    Param c: caracter a avaluar.
*/
	return (c >= 'A' && c <= 'Z');
}


char aMinuscula(char c) {
/*
    Pre: --
    Post: si el caracter entrat es una majuscula, es retorna el seu equivalent en minuscula. Altrament es retorna directament el caracter entrat.
    Param c: caracter a transformar.
*/
	if (esMajuscula(c)) return c + 32;
	else return c;
}


int indexVocal(char c) {
/*
    Pre: --
    Post: en el cas de que el caracter entrat sigui una vocal, retorna la seva posicio en ordre lexicografic a l'alfabet angles (descartant les consonants), altrament retorna un codi d'error.
    Param c: caracter a avaluar.
    Return: si el parametre no es una vocal, retorna el codi d'error -1. Altrament, retorna el codi de la vocal entrada,
            essent per a la 'a' el codi 1, la 'e' el 2, la 'i' el 3, la 'o' el 4 i la 'u' el 5.
*/
	if (!esVocal(c)) return -1;
	else {
		char caux = aMinuscula(c);
		int index;
		switch (caux) {
		case 'a':
			index = 1;
			break;
		case 'e':
			index = 2;
			break;
		case 'i':
			index = 3;
			break;
		case 'o':
			index = 4;
			break;
		case 'u':
			index = 5;
			break;
		default:
			index = 0;
			break;
		}

		return index;
	}
}


void dibuixarGraficPastis(const int * taula_recompte, int mida_taula_recompte) {
/*
    Pre: taula_recompte != null && mida_taula_recompte == mida real de taula_recompte.
    Post: es mostra per pantalla un grafic de pastis de la distribuicio dels elements de la taula de recompte.
    Param taula_recompte: taula de recompte de vocals en un fitxer.
    Param mida_taula_recompte: enter que ens indica la mida de la taula de recompte.
*/
	string titol_finestra = "Grafic de pastis";

	Window w(titol_finestra, AMPLE_FINESTRA, ALT_FINESTRA); //declarem una finestra amb titol, amplada i altura definides. La resta de parametres s'assignen per defecte.
	w.t_penUp();                                            //usarem les tortugues per trobar els punts on dibuixar text, i per tant aixequem el pinzell ja que no volem que dibuixin el cami per on passen.

	int acumulat_total = taula_recompte[0];                 //al programa principal hem definit que la posicio 0 de la taula conte el recompte total de vocals.

	float angle_inicial = 0, angle_del_tall;

	for (int i = 1; i < mida_taula_recompte; i++) {                         //per totes les vocals de la taula de recompte.
		if (taula_recompte[i] != 0) {                                       //si no hi ha ocurrencies d'aquesta vocal, no cal fer res.

			float percentatge = taula_recompte[i] / (1.0*acumulat_total);   //calculem per percentatge de la circumferencia que ocupara aquesta vocal.
			angle_del_tall = percentatge * VOLTA_COMPLETA;                  //calculem l'angle del arc tros de pastis que volem dibuixar.


			//// Aixo no es necessari, pero enriqueix la sortida grafica: calcular els punts on s'escriu cada lletra del grafic (amb tortugues es senzill) ////
			//    La idea es mostrar la vocal, el nombre d'ocurrencies i el percentatge relatiu d'ocurrencies al costat de cada tall de pastis del grafic    //

			w.t_setPos(AMPLE_FINESTRA / 2, ALT_FINESTRA / 2);       //coloquem la tortuga al centre del pastis per posteriorment moure-la relativament a aquest.
			w.t_setHeading((angle_inicial + (angle_del_tall / 2))); //calculem l'angle de biseccio del tall del pastis per poder moure la tortuga en aquesta direccio.
			w.t_forward(RADI + 20);                                 //fem que la tortuga avanci de manera que queda colocada al costat de cada tall de pastis.

			stringstream percentatge_text_stream;                   //declarem un stringstream per poder editar facilment el format de la string que volem escriure.

			//aquest if nomes es correcte si es fa en graus.
			if (w.t_heading() >= 90 && w.t_heading() <= 270) {              //Si ens trobem a la part esquerra del grafic.
				percentatge_text_stream << " (" << taula_recompte[i] << ") " << fixed << setprecision(2) << percentatge * 100 << "%" << "   " << VOCALS[i-1];
				w.t_label(percentatge_text_stream.str(), TEXT_ALIGN_RIGHT); //escrivim el text a la posicio de la tortuga alineat a la dreta, de manera que quedi a prop del grafic.
			}
			else {                                                          //si ens trobem a la part dreta del grafic.
				percentatge_text_stream << VOCALS[i-1] << "   " << fixed << setprecision(2) << percentatge * 100 << "%" << " (" << taula_recompte[i] << ") ";
				w.t_label(percentatge_text_stream.str(), TEXT_ALIGN_LEFT);  //escrivim el text a la posicio de la tortuga alineat a la esquerre, de manera que quedi a prop del grafic.
			}

			/////////////////////////////////////////////////          fi del tall de codi estetic            //////////////////////////////////////////////////


			w.filled_pieslice(AMPLE_FINESTRA / 2, ALT_FINESTRA / 2, RADI, angle_inicial, angle_del_tall, COLORS[i-1]);
			angle_inicial += angle_del_tall; //l'angle inicial del seguent tall de pastis sera l'angle inicial del anterior mes l'increment d'angle del anterior

		}
	}

	w.waitAnyKeypress(); //esperem a que l'usuari apreti qualsevol tecla.
}

int main()
{
    int comptador_vocals[NUM_VOCALS+1]; //deixem una posicio extra per el recompte total d'ocurrencies.
	for (int i = 0; i < NUM_VOCALS+1; i++) comptador_vocals[i] = 0; //inicialitzem tots els valors de l'array.

	string nom_fitxer;

	cout << "Introdueix el nom del fitxer (recorda que ha d'estar al directori on execuits aquest programa): " << endl;
	cin >> nom_fitxer;  //no admet espais en el nom de fitxer, s'hauria d'usar getline() si es volgues aquesta funcionalitat.
                        //a mes, si es volen ficar rutes mes elaborades caldra escapar els caracters especials que contingui.

	fstream fitxer;
	fitxer.open(nom_fitxer.c_str()); //intentem obrim el fitxer.

	if (!fitxer.is_open()) cout << "No s'ha pogut obrir el fitxer " << nom_fitxer << endl; //si no podem obrir el fitxer, donem missatge d'error.
	else {
		char caracter;
		fitxer.get(caracter);
		while (!fitxer.eof()) {
			if (esVocal(caracter)) {
				comptador_vocals[0]++; //incrementem el nombre d'ocurrencies total.
				comptador_vocals[ indexVocal(aMinuscula(caracter)) ]++; //incrementem el comptador de la vocal en concret.
			}
			fitxer.get(caracter);
		}

		fitxer.close(); //tanquem el fitxer, ja em acabat amb ell.

		dibuixarGraficPastis(comptador_vocals, NUM_VOCALS + 1); //dibuixem el grafic de pastis.
	}

    return 0;
}
