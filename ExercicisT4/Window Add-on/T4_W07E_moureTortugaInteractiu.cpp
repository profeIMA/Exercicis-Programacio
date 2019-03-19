#include "windowAddon/WindowAddon.h" //incluim la llibreria de la finestra.

using namespace std;

const int AMPLE_FINESTRA = 800; //amplada en pixels de la finestra que obrirem.
const int ALT_FINESTRA = 600;   //altura en pixels de la finestra que obrirem.



int rebreInputDelTeclatCASE(Window & w) {
/*
    Pre: --
    Post: s'ha gestionat un event de teclat de la finestra w.
    Param w: finestra de la qual es rebra l'event de teclat.
    Return: nombre_retorn, un valor que depen de la tecla pressionada.
            Llista de valors de retorn en funcio de la tecla detectada:
            - Esborrar o Suprimir (KEYBOARD_KEY_BACKSPACE o KEYBOARD_KEY_DELETE):   -1
            - Escapar (KEYBOARD_KEY_ESCAPE):         0
            - Fletxa dreta (KEYBOARD_KEY_RIGHT):     1
            - Fletxa amunt (KEYBOARD_KEY_UP):        2
            - Feltxa esquerre (KEYBOARD_KEY_LEFT):   3
            - Feltxa avall (KEYBOARD_KEY_DOWN):      4
            - Barra Espaiadora (KEYBOARD_KEY_SPACE): 5
            - Altres:                                -2
*/
	int tecla_apretada, nombre_retorn;

	tecla_apretada = w.waitAnyKeypress();

	switch (tecla_apretada) {
		case KEYBOARD_KEY_DELETE:
		case KEYBOARD_KEY_BACKSPACE:    //aixo equival a fer KEYBOARD_KEY_DELETE || KEYBOARD_KEY_BACKSPACE en una estructura if else.
			nombre_retorn = -1;
			break;
		case KEYBOARD_KEY_ESCAPE:
			nombre_retorn = 0;
			break;
		case KEYBOARD_KEY_RIGHT:
			nombre_retorn = 1;
			break;
		case KEYBOARD_KEY_UP:
			nombre_retorn = 2;
			break;
		case KEYBOARD_KEY_LEFT:
			nombre_retorn = 3;
			break;
		case KEYBOARD_KEY_DOWN:
			nombre_retorn = 4;
			break;
		case KEYBOARD_KEY_SPACE:
			nombre_retorn = 5;
			break;
		default:
			nombre_retorn = -2;
			break;
	}

	return nombre_retorn;
}

int rebreInputDelTeclatIF(Window & w) {
/*
    Pre: --
    Post: s'ha gestionat un event de teclat de la finestra w.
    Param w: finestra de la qual es rebra l'event de teclat.
    Return: nombre_retorn, un valor que depen de la tecla pressionada.
            Llista de valors de retorn en funcio de la tecla detectada:
            - Esborrar o Suprimir (KEYBOARD_KEY_BACKSPACE o KEYBOARD_KEY_DELETE):   -1
            - Escapar (KEYBOARD_KEY_ESCAPE):         0
            - Fletxa dreta (KEYBOARD_KEY_RIGHT):     1
            - Fletxa amunt (KEYBOARD_KEY_UP):        2
            - Feltxa esquerre (KEYBOARD_KEY_LEFT):   3
            - Feltxa avall (KEYBOARD_KEY_DOWN):      4
            - Barra Espaiadora (KEYBOARD_KEY_SPACE): 5
            - Altres:                                -2
*/
	int tecla_apretada, nombre_retorn;

	tecla_apretada = w.waitAnyKeypress();

	if (tecla_apretada == KEYBOARD_KEY_DELETE || tecla_apretada == KEYBOARD_KEY_BACKSPACE)
		nombre_retorn = -1;
	else if (tecla_apretada == KEYBOARD_KEY_ESCAPE)
		nombre_retorn = 0;
	else if (tecla_apretada == KEYBOARD_KEY_RIGHT)
		nombre_retorn = 1;
	else if (tecla_apretada == KEYBOARD_KEY_UP)
		nombre_retorn = 2;
	else if (tecla_apretada == KEYBOARD_KEY_LEFT)
		nombre_retorn = 3;
	else if (tecla_apretada == KEYBOARD_KEY_DOWN)
		nombre_retorn = 4;
	else if (tecla_apretada == KEYBOARD_KEY_SPACE)
		nombre_retorn = 5;
	else
		nombre_retorn = -2;

	return nombre_retorn;
}

int main()
{
	Window finestra("Tortugueta", AMPLE_FINESTRA, ALT_FINESTRA, WHITE, GREEN);	//declarem la finestra amb titol "Tortugueta", amplada i altura definides, color de fons blanc i color de dibuix verd.

	//Preparem a la tortuga
	finestra.t_setPos(AMPLE_FINESTRA / 2, ALT_FINESTRA / 2);	//la coloquem al centre de la pantalla.
	finestra.t_show();											//fem visible el cursor de la tortuga.

	int distancia_salt_tortuga = 25;							//distancia que recorrera la tortuga en cada iteracio.
	int seleccio_usuari;

	seleccio_usuari = rebreInputDelTeclatCASE(finestra);

	while (seleccio_usuari != 0) {

		if (seleccio_usuari != -2) {								//nomes volem actuar si coneixem la tecla que ens han entrat.

			if (seleccio_usuari == 1) {								//si l'usuari apreta la tecla RIGHT.
				finestra.t_setHeading(0);							//posicionem la tortuga mirant cap a la dreta (0 graus absoluts).
			}
			else if (seleccio_usuari == 2) {						//si l'usuari apreta la tecla UP.
				finestra.t_setHeading(90);							//posicionem la tortuga mirant cap amunt (90 graus absoluts).
			}
			else if (seleccio_usuari == 3) {						//si l'usuari apreta la tecla LEFT.
				finestra.t_setHeading(180);							//posicionem la tortuga mirant cap a l'esquerra (180 graus absoluts).
			}
			else if (seleccio_usuari == 4) {						//si l'usuari apreta la tecla DOWN.
				finestra.t_setHeading(270);							//posicionem la tortuga mirant cap avall (270 graus absoluts).
			}
			else if (seleccio_usuari == 5) {                        //si l'usuari apreta la tecla SPACE.
				finestra.t_swapPen();                               //Canviem l'estat del llapis de la tortuga (aixequem si estava a baix, i baixem si estava aixecat).
			}
			else if (seleccio_usuari == -1) {
				finestra.clear();									        //Netejem la finestra.
				finestra.t_setPos(AMPLE_FINESTRA / 2, ALT_FINESTRA / 2);	//recoloquem la tortuga al centre de la pantalla.
			}

			if (seleccio_usuari > 0 && seleccio_usuari < 5) finestra.t_forward(distancia_salt_tortuga);	//fem avancar la tortuga (no ho fem si s'acaba de netejar la pantalla).
		}

		seleccio_usuari = rebreInputDelTeclatCASE(finestra);    //el proces es quedara encallat aqui fins que rebi una pulsacio de teclat.
	}

	return 0;
}
