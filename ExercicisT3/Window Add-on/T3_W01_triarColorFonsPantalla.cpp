#include <iostream>
#include "windowAddon/WindowAddon.h" //incluim la llibreria de la finestra.

using namespace std;

int main()
{
    cout << "Tria un color:" << endl;
	cout << "(y) groc" << endl;
	cout << "(b) blau" << endl;
	cout << "(g) verd" << endl;
	cout << "(r) vermell" << endl;
	cout << endl << "Si no tries cap d'aquestes opcions, el fons sera negre" << endl;

	char input;
	cin >> input;

	RGBColor color;	//declarem una variable que emmagatzemara el color que escollim. Aquesta variable es una tupla (les veuras mes endevant).

	//constants definides a la llibreria de la finestra.
	if (input == 'y') color = YELLOW;
	else if (input == 'b') color = BLUE;
	else if (input == 'g') color = GREEN;
	else if (input == 'r') color = RED;
	else color = BLACK;

	Window finestra(400, 400, color);	//creem una finestra 400x400 amb el fons del color escollit.

	finestra.rest(5);   //fem que la finestra es quedi en pantalla durant 5 segons.

    return 0;
}