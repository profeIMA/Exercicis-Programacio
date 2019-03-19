#include <string>                    //string
#include <iostream>                  //cin i cout
#include <sstream>                   //tractament d'strings
#include "windowAddon/WindowAddon.h" //incluim la llibreria de la finestra.

using namespace std;

const int NUM_LLETRES = 26;                                                             //nombre de lletres del alfabet angles.
const int NUM_COLORS = 7;                                                               //nombre de colors.
const RGBColor COLORS[NUM_COLORS] = { RED, MAGENTA, BLUE, CIAN, GREEN, YELLOW, BLACK }; //array amb els colors.

const char MARCA_FI = '#';

const int AMPLE_FINESTRA = 500;     //amplada en pixels de la finestra que obrirem
const int ALT_FINESTRA = 700;       //altura en pixels de la finestra que obrirem

const float ESPAI_ENTRE_BARRES = 2; //espai entre dues barres del grafic.

bool esMajuscula(char c) {
/*
    Pre: --
    Post: retorna cert si el caracter entrat es una lletra majuscula del alfabet angles, fals altrament.
    Param c: caracter a avaluar.
*/
	return (c >= 'A' && c <= 'Z');
}

bool esMinuscula(char c) {
/*
    Pre: --
    Post: retorna cert si el caracter entrat es una lletra minuscula del alfabet angles, fals altrament.
    Param c: caracter a avaluar.
*/
	return (c >= 'a' && c <= 'z');
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

int indexLletraAbecedari(char c) {
/*
    Pre: --
    Post: en el cas de que el caracter entrat sigui una lletra minuscula, retorna la seva posicio en ordre lexicografic a l'alfabet angles, altrament retorna un codi d'error.
    Param c: caracter a avaluar.
    Return: si el parametre no es una lletra minuscula, retorna el codi d'error -1. Altrament, retorna el codi de la lletra entrada.
            la 'a' seria un 1, la 'b' un 2, la 'c' un 3...
*/
	if (esMinuscula(c)) return c - 96;
	else return -1;
}

char lletraAbecedari(int index) {
/*
    Pre: --
    Post: si l'index entrat esta dins dels rangs d'index de lletres del alfabet angles, es retorna el caracter corresponent a aquella lletra. Altrament es retorna directament el caracter nul.
    Param index: index de la lletra que es vol obtenir.
*/
	if (index > 0 && index <= NUM_LLETRES) return index + 96;
	else return 0;
}


void dibuixarHistograma(Window & w, int ample, int alt, const int * taula_recompte, const int * colors, int mida_taula_recompte) {
/*
    Pre: taula_recompte != null && colors != null i mida_taula_recomtpe ha de ser la mida real de taula_recompte i de colors (colors ha de ser com a minim igual de llarga que taula_recompte).
         Tambe cal que ample > 0 i alt > 0
    Post: es mostra per pantalla un grafic de barres horitzontal de la frequencia de les lletres representada per la taula de recomptes.
    Param w: finestra on es pintara el grafic de barres.
    Param ample: amplada de la finestra on es pintara el grafic de barres.
    Param alt: altura de la finestra on es pintara el grafic de barres.
    Param taula_recompte: array amb la frequencia relativa de les lletres entrades.
    Param colors: array amb l'index de l'array COLORS per cada lletra del alfabet.
    Param mida_taula_recompte: mida de les arrays taula_recompte i colors.
*/
	int acumulat_total = taula_recompte[0];             //com hem definit al main, la primera posicio conte el recompte total de lletres.

	float pixels_reservats_per_a_barres = alt - (mida_taula_recompte - 1) * ESPAI_ENTRE_BARRES; //nombre de pixels verticals que ens ocuparan totes les barres juntes. Es un calcul intermig per poder saber quan ocupara cada barra.
	float alt_barra = pixels_reservats_per_a_barres / NUM_LLETRES;  //alt en pixels de cada barra (recordem que les barres creixen hortizontalment, i per tant, tots tenen la mateixa "altura").

	for (int i = 1; i < mida_taula_recompte; i++) {     //per cada lletra de la taula de recompte.
		int index_lletra = NUM_LLETRES - i + 1;         //recorrem la taula de manera inversa, comencant per la 'z'.
		float longitud_barra = ((float)taula_recompte[index_lletra]/acumulat_total) * ample; //calculem la longitud de la barra en funcio de la frequencia relativa de la lletra que representa.

		//cout << taula_recompte[index_lletra] << " " << acumulat_total << endl;

		Point2D p1(0, i*alt_barra + (i-1) * ESPAI_ENTRE_BARRES);            //cantonada superior esquerra de la barra.
		Point2D p2(longitud_barra, p1.y - alt_barra);                       //cantonada inferior dreta de la barra.
		w.filled_rectangle(p1,p2,COLORS[colors[i]]);                        //pintem la barra.

		Point2D posicio_lletra(10, p1.y);                                   //punt a on escriurem la lletra representada.
		char lletra = lletraAbecedari(index_lletra);                        //obtenim el caracter a partir del index de la lletra.
		string lletra_str(1,lletra);    //per construir una string a partir d'un caracter pots usar el constructor string(1,char).
		stringstream text;
		text << lletra << "  " << taula_recompte[index_lletra];             //lletra i nombre d'aparicions separats per un espai.

		w.text(posicio_lletra, text.str(), TEXT_ALIGN_CENTER);              //escrivim el text per pantalla.
	}
}

int main()
{
	int comptador_lletres[NUM_LLETRES+1];   //afegim una posicio al principi per emmagatzemar el recompte total de lletres.
	int colors_lletres[NUM_LLETRES+1];      //+1 per evitar tenir que fer conversions d'index, perdem un espai a canvi de simplicitat en el codi.

	srand(time(NULL));                          //inicialitzem la llavor de nombres aleatoris.
	comptador_lletres[0] = 0;                   //ho fiquem fora per evitar ficar condicions dins de l'estructura iterativa.
	for (int i = 1; i < NUM_LLETRES + 1; i++) { //inicialitzem la taula.
		comptador_lletres[i] = 0;
		colors_lletres[i] = rand() % (NUM_COLORS-1); //-1 perque no volem que ens surti el color negre.
	}

	string titol_finestra = "Histograma";   //titol de la finestra.

	Window w(titol_finestra, AMPLE_FINESTRA, ALT_FINESTRA);   //declarem una finestra amb titol, amplada i altura definides. La resta de parametres s'assignen per defecte.

	cout << "Tu ves entrant caracters que jo tels conto..." <<endl;
	char caracter = cin.get();  //rebem el seguent caracter de cin.

	while (caracter != MARCA_FI) {//mentre no ens entrin la marca de fi.

		char caracter_auxiliar = aMinuscula(caracter);                      //passem a minuscula el caracter entrat.
		if (esMinuscula(caracter_auxiliar)) {                               //comprovem que sigui efectivament una lletra.
			comptador_lletres[0]++;                                         //sumem 1 al comptador global.
			comptador_lletres[ indexLletraAbecedari(caracter_auxiliar) ]++; //sumem 1 al comptador especific de la lletra.
		}

		if (caracter == '\n') { //cada cop que ens entren un salt de linia.
			w.clear();  //netejem la finestra.
			dibuixarHistograma(w, AMPLE_FINESTRA, ALT_FINESTRA, comptador_lletres, colors_lletres, NUM_LLETRES + 1); //redibuixem l'histograma.
		}

		caracter = cin.get(); //rebem el seguent caracter de cin.

	}

	//Si volguessim ficar aquest tall de codi en una funcio, hauriem de posar la linia seguent per netejar el buffer d'entrada.
	//cin.ignore(1000,'\n'); //netejem el buffer per si haugues quedat algun caracter abans del salt de linia.

    return 0;
}
