#include <iostream>
#include "windowAddon/WindowAddon.h" //incluim la llibreria de la finestra.

using namespace std;

int main()
{
    cout << "Quina figura vols dibuixar?:" << endl;
	cout << "(q) Quadrat" << endl;
	cout << "(c) Cercle" << endl;
	cout << "(l) Linia" << endl;
	cout << endl << "Si no tries cap d'aquestes opcions, el programa acabara" << endl;

	char input;
	cin >> input;

	if(input == 'q' or input == 'c' or input == 'l'){ //comprovem si cal pintar o no.
        Window finestra(300, 300);	//declarem una finestra de 300x300 pixels. El color de fons es per defecte blanc i el color de dibuix negre.

        if (input == 'q') finestra.rectangle(50, 250, 250, 50);	//quadrat amb cantonada superior esquerra al punt (50,250) i cantonada inferior dreta al punt (250,50).
        else if (input == 'c') finestra.circle(150, 150, 50);	//cercle amb centre al punt (150,150) i radi 50.
        else //si arribem aqui sabem que input == 'l'
            finestra.line(50,150,250,150);	//linia que uneix els punts (50,150) i (250,150) (estan a la mateixa altura, per tant es una linia horitzontal).

        finestra.rest(5); //fem que la finestra persisteixi en pantalla durant 5 segons.
	}

    return 0;
}
