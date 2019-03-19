#include <iostream>
#include "windowAddon/WindowAddon.h" //incluim la llibreria de la finestra.

using namespace std;

const int AMPLE_FINESTRA = 640;         //amplada en pixels de la finestra que obrirem.
const int ALT_FINESTRA = 480;           //altura en pixels de la finestra que obrirem.

const int AMPLE_TARGETA = 400;          //amplada en pixels de la targeta.
const int ALT_TARGETA = 150;            //altura en pixels de la targeta.



void dibuixarConnectors(Window & w, int p1x, int p1y, int p2x, int p2y){
/*
    Pre: p1x < p2x && p1y > p2y (representen les cantonades superior esquerra i inferior dreta d'un rectangle).
    Post: dibuixa un rectangle estriat a la finestra w representant la interficie de connexio amb l'ordinador.
    Param w: finestra on es dibuixen els connectors.
    Param p1x: coordenada x de la cantonada superior esquerra dels interconnectors.
    Param p1y: coordenada y de la cantonada superior esquerra dels interconnectors.
    Param p2x: coordenada x de la cantonada inferior dreta dels interconnectors.
    Param p2y: coordenada y de la cantonada inferior dreta dels interconnectors.
*/
    w.rectangle(p1x,p1y,p2x,p2y); //rectangle principal

    int n_connectors = 82;
    double ample_connector = ((double)(p2x-p1x))/(n_connectors-1);

    for(int i = 0; i < n_connectors-1; i++){ //n_connectors-1 ja que l'ultim no cal que dibuixem la linia.
        double x_connector_act = p1x+(i+1)*ample_connector;
        w.line(x_connector_act, p1y, x_connector_act, p2y);
    }

}

void dibuixarPlaca(Window & w, int p1x, int p1y, int p2x, int p2y){
/*
    Pre: p1x < p2x && p1y > p2y (representen les cantonades superior esquerra i inferior dreta d'un rectangle).
    Post: dibuixa la placa de la targeta, amb els seus connectors.
    Param w: finestra on es dibuixa la placa.
    Param p1x: coordenada x de la cantonada superior esquerra de la placa principal.
    Param p1y: coordenada y de la cantonada superior esquerra de la placa principal.
    Param p2x: coordenada x de la cantonada inferior dreta de la placa principal.
    Param p2y: coordenada y de la cantonada inferior dreta de la placa principal.
*/
    w.rectangle(p1x, p1y, p2x, p2y); //dibuixem el rectangle central

    dibuixarConnectors(w, p1x+50, p2y, p1x+225, p2y-20); //dibuixem la interficie de connexio de la targeta amb l'ordinador.
}

void dibuixarVentilador(Window & w, int cx, int cy, int r){
/*
    Pre: --
    Post: Dibuixa un ventilador (simplificat) de radi r centrat al punt (cx,cy).
    Param w: finestra on es dibuixa el ventilador.
    Param cx: coordenada x del centre del ventilador.
    Param cy: coordenada y del centre del ventilador.
    Param r: radi del ventilador.
*/
    w.circle(cx,cy,r);
    w.circle(cx,cy,0.3*r);
}

void dibuixarVentiladors(Window & w, int x_ini, int y, int r, int n, int separacio = 0){
/*
    Pre: --
    Post: Dibuixa n ventiladors equiespaiats 'separacio' unitats entre ells de radi r centrats sobre l'eix definit per la recta horitzontal y.
    Param w: finestra on es dibuixen els n ventiladors.
    Param x_ini: coordenada x del centre del primer ventilador a dibuixar.
    Param y: coordenada y de tots els centres dels ventiladors que es dibuixaran.
    Param r: radi dels ventiladors.
    Param n: nombre de ventiladors.
    Param separacio (opt): separacio entre ventiladors.
*/
    for(int i = 0; i<n; i++){
        dibuixarVentilador(w, x_ini+i*(2*r+separacio), y, r);
    }
}

void dibuixarSortides(Window & w, int p1x, int p1y, int p2x, int p2y){
/*
    Pre: --
    Post: dibuixa les sortides de imatge de la targeta.
    Param w: finestra on es dibuixen les sortides.
    Param p1x: coordenada x de la cantonada superior esquerra de la placa lateral de sortides.
    Param p1y: coordenada y de la cantonada superior esquerra de la placa lateral de sortides.
    Param p2x: coordenada x de la cantonada inferior dreta de la placa lateral de sortides.
    Param p2y: coordenada y de la cantonada inferior dreta de la placa lateral de sortides.
*/
    w.rectangle(p1x, p1y, p2x, p2y); //placa metalica principal.

    w.rectangle(p1x-5, p1y-25, p1x, p1y-75); //port de sortida de video visible de perfil.
}

void dibuixarTarjetaGrafica(Window & w){
/*
    Pre: --
    Post: dibuixa una targeta grafica ficticia (qualsevol semblanca amb la realitat es pura coincidencia) a la finestra w.
    Param w: finestra on es dibuixara la targeta.
*/
    int cx = AMPLE_FINESTRA/2, cy = ALT_FINESTRA/2;           //coordenades del centre de la pantalla, punt de referencia des del que pintarem el nostre dibuix.

    int p1x = cx - AMPLE_TARGETA/2, p1y = cy + ALT_TARGETA/2; //cantonada superior esquerra de la targeta.
    int p2x = cx + AMPLE_TARGETA/2, p2y = cy - ALT_TARGETA/2; //cantonada inferior dreta de la targeta.

    int radi_vent = 60, n_vent = 3, separacio = 10;

    dibuixarPlaca(w, p1x, p1y, p2x, p2y); //dibuixem la placa principal.

    dibuixarVentiladors(w, (AMPLE_FINESTRA)/2 - 2*radi_vent-separacio, ALT_FINESTRA/2, radi_vent, n_vent, separacio);
    //explicacio de la crida:
    //  - segon parametre: si sabem que cada ventilador fa 100 unitats de diametre, i que n'hem de colocar 3 separats entre ells per 10 unitats,
    //                     sabem que el primer ventilador ha de tenir el seu centre a centreGpu-diametre-separacio.
    //  - tercer parametre: la altura dels ventiladors sera per a tots la mateixa, centrats sobre la mateixa linia.

    dibuixarSortides(w, p1x-3, p1y+5, p1x, p2y-15);
}

int main()
{
    Window finestra(AMPLE_FINESTRA, ALT_FINESTRA);

    dibuixarTarjetaGrafica(finestra);

    finestra.waitWindowCloseButton();

    return 0;
}
