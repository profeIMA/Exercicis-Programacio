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
	cout << endl << "Si no tries cap d'aquestes opcions, el fons sera blanc" << endl;

	char input;
	cin >> input;

	RGBColor color;	//declarem una variable que contindra el color que escollim. Aquesta variable es una tupla (les veuras mes endevant).

	if (input == 'y') color = YELLOW;
	else if (input == 'b') color = BLUE;
	else if (input == 'g') color = GREEN;
	else if (input == 'r') color = RED;
	else color = WHITE;

    cout << "Quina figura vols dibuixar?" << endl;
	cout << "(q) Quadrat" << endl;
	cout << "(c) Cercle" << endl;
	cout << "(l) Linia" << endl;
	cout << endl << "Si no tries cap d'aquestes opcions, el programa acabara" << endl;

	cin >> input; //reaprofitem la variable.

	if(input == 'q' or input == 'c' or input == 'l'){ //comprovem si cal pintar o no.
        Window finestra(300, 300);	//declarem una finestra de 300x300 pixels. El color de fons es blanc i el color de dibuix negre.

		//passarem com a ultim parametre el color escollit, de manera que la figura sera del color que l'usuari trii.
        if (input == 'q') finestra.rectangle(50, 250, 250, 50, color);	//quadrat amb cantonada superior esquerre al punt (50,250) i cantonada inferior dreta al punt (250,50).
        else if (input == 'c') finestra.circle(150, 150, 50, color);	//cercle amb centre al punt (150,150) i radi 50.
        else //si arribem aqui sabem que input == 'l'
            finestra.line(50,150,250,150, color);	                    //linia que uneix els punts (50,150) i (250,150) (estan a la mateixa altura, per tant es una linia horitzontal).

        finestra.rest(5); //fem que la finestra persisteixi en pantalla durant 5 segons.
	}

    return 0;
}
