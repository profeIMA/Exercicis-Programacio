#include <iostream>
#include "Figura_Geometrica.h"
#include "Cercle.h"
#include "Ellipse.h"
#include "Poligon.h"
#include "Quadrilater.h"
#include "Triangle.h"


using namespace std;

static const unsigned MAX=200;

Figura_Geometrica* crearFigura(){
    cout<<"Tipus figura: cercle (c), elipse (e), triangle (t), quadrilater (q), poligon (p)"<<endl;
    char tipus;
    cin>>tipus;
    Figura_Geometrica *nou;
    switch(tipus){
      case 'c': nou = new Cercle(); break;
      case 'e': nou = new Ellipse(); break;
      case 't': nou = new Triangle(); break;
      case 'q': nou = new Quadrilater(); break;
      case 'p':
          unsigned n;
          cout<<"N vertexs: "; cin>>n;
          nou = new Poligon(n); break;
    }
    nou->llegir();
    return nou;

}

void mostra(Figura_Geometrica *figures[], unsigned n_figures){
     cout<<" Figures entrades: "<<endl;
     for(unsigned i=0 ;i<n_figures; i++)
        figures[i]->mostra();
}

unsigned posicio_minim(Figura_Geometrica * figures[], unsigned inici, unsigned n){
    unsigned pos=inici;
    for(unsigned i=inici+1; i<n;i++)
        if(figures[i]->te_menor_area(figures[pos])) pos=i;
    return pos;
}

void ordenar_per_area_creixent(Figura_Geometrica *figures[], unsigned n_figures){
    for(unsigned i=0; i<n_figures-1; i++){
       unsigned pos_min = posicio_minim(figures,i,n_figures);
       Figura_Geometrica *aux=figures[pos_min];
       figures[pos_min]=figures[i];
       figures[i]=aux;
    }
}

void alliberar_memoria(Figura_Geometrica* figures[], unsigned n_figures){
    cout<<"alliberar vector inicial"<<endl;
    for(unsigned i=0; i< n_figures;i++)
        delete figures[i];
}


void comprovacions_funcionament_memoria_dinamica(){
    //comprovacions de funcionament
    cout<<endl<<"Comprovem que funciona el constructor de copia dels Poligons"<<endl;
    Quadrilater q1,q2;
    q1.llegir();
    cout<<"Fem una assignacio: ";
    q2=q1;
    q2.mostra();

    Triangle t; t.llegir();
    cout<<"Fem una copia: ";
    Triangle t1(t);
    cout<<"Triangle copia: ";t1.mostra();
    cout<<"Triangle original: ";t.mostra();
}

int main()
{
    Figura_Geometrica *figures[MAX];
    unsigned n_figures;
    cout<<"Nombre de figures (< "<<MAX<<"): "<<endl; cin>>n_figures;
    for(unsigned i=0; i<n_figures;i++)
        figures[i]=crearFigura();

    cout<<"Vols ordenar per area? S/N"<<endl;
    char ordenar;
    cin>>ordenar;
    if(ordenar=='S') ordenar_per_area_creixent(figures, n_figures);

    cout<<"Les figures son: "<<endl;
    mostra(figures,n_figures);

    alliberar_memoria(figures,n_figures);

    comprovacions_funcionament_memoria_dinamica();
    return 0;
}
