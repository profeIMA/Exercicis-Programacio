#include <iostream>
#include "windowAddon/WindowAddon.h" //incluim la llibreria de la finestra.

using namespace std;

int main()
{
    cout << "Quina figura vols dibuixar?:" << endl;
	cout << "(a) Arc" << endl;
	cout << "(c) Cercle" << endl;
	cout << "(e) Ellipse" << endl;
	cout << "(l) Linia" << endl;
	cout << "(o) Rectangle arrodonit" <<endl;
	cout << "(p) Tall de pastis" << endl;
	cout << "(r) Rectangle" << endl;
	cout << "(t) Triangle" << endl;
	cout << "Si escrius qualsevol d'aquestes opcions en majuscula, la figura es pintara per dins (les que es puguin)." << endl;
	cout << endl << "Si no tries cap d'aquestes opcions, el programa acabara" << endl;

	char input;
	cin >> input;

    Window finestra(300, 300);	//declarem una finestra de 300x300 pixels. El color de fons es per defecte blanc i el color de dibuix es negre.

    bool cal_esperar = true;    //ens indica si hem de fer persistir la finestra en pantalla. Ho farem servir per saber si l'usuari ha entrar una opcio valida o no.

    if(input == 'a' or input == 'A') finestra.arc(150, 150, 50, 45, 90);                //arc amb centre al punt (150,150) de radi 50, angle inicial de 45 i increment d'angle de 90.
    else if (input == 'c') finestra.circle(150, 150, 50);	                            //cercle amb centre al punt (150,150) i radi 50.
    else if (input == 'C') finestra.filled_circle(150, 150, 50);                        //cercle emplenat amb centre al punt (150,150) i radi 50.
    else if (input == 'e') finestra.ellipse(150, 150, 50, 60);                          //ellipse amb centre al punt (150,150), radi horitzontal 50 i radi vertical 60.
    else if (input == 'E') finestra.filled_ellipse(150, 150, 50, 60);                   //ellipse emplenada amb centre al punt (150,150), radi horitzontal 50 i radi vertical 60.
    else if (input == 'l' or input == 'L') finestra.line(50, 150, 250, 150);	        //linia que uneix els punts (50,150) i (250,150) (estan a la mateixa altura, linia horitzontal).
    else if (input == 'o') finestra.rounded_rectangle(50, 250, 200, 50, 10, 10);        //rectangle arrodonit amb cantonada superior esquerra al punt (50,250) i cantonada inferior dreta al punt (200,50) i 10 de radi tant horitzontal com vertical d'arrodoniment.
    else if (input == 'O') finestra.filled_rounded_rectangle(50, 250, 200, 50, 10, 10); //rectangle arrodonit emplenat amb cantonada superior esquerra al punt (50,250) i cantonada inferior dreta al punt (200,50) i 10 de radi tant horitzontal com vertical d'arrodoniment.
    else if (input == 'p') finestra.pieslice(150, 150, 50, 45, 90);                     //tall de pastis amb centre al punt (150,150), radi 50, angle inicial 45 i increment d'angle de 90 graus.
    else if (input == 'P') finestra.filled_pieslice(150, 150, 50, 45, 90);              //tall de pastis emplenat amb centre al punt (150,150), radi 50, angle inicial 45 i increment d'angle de 90 graus.
    else if (input == 'r') finestra.rectangle(50, 250, 200, 50);	                    //rectangle amb cantonada superior esquerra al punt (50,250) i cantonada inferior dreta al punt (200,50).
    else if (input == 'R') finestra.filled_rectangle(50, 250, 200, 50);                 //rectangle emplenat amb cantonada superior esquerra al punt (50,250) i cantonada inferior dreta al punt (200,50).
    else if (input == 't') finestra.triangle(50, 50, 250, 50, 150, 250);                //triangle amb vertex (50,50), (250,50) i (150,250).
    else if (input == 'T') finestra.filled_triangle(50, 50, 250, 50, 150, 250);         //triangle emplenat amb vertex (50,50), (250,50) i (150,250).
    else cal_esperar = false;           //no cal fer persistir la finestra si no hi pintarem res.

    if(cal_esperar) finestra.rest(5);   //fem que la finestra es quedi en pantalla durant 5 segons.

    return 0;
}
