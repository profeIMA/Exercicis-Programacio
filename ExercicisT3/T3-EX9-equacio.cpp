/* Resolució d'una equació de segon grau ax^2+bx+c=0. S'introdueixen els coeficients reals i s'obté la solució (amb els missatges adients depenent dels valors d'a, b i c). A part del cas en què a és diferent de 0 (equació de segon grau), estudiem el cas a igual a 0 (equació lineal), obtenint una solució per la x. Però també acceptem que a i b puguin ser 0, en aquest cas distingim entre el cas que és una tautologia i el que és una contradicció.
 */
// Entrada: llegeix 3 nombres reals (a, b, c)
// Sortida: escriu les solucions (segons expressa l'enunciat) de l'equació introduïda

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    double discriminant, x, x1, x2;
    cout << "Entra a b c : ";
    cin>>a>>b>>c;
    if (a!=0){
        discriminant=b*b-4*a*c;
        if (discriminant<0)
            cout<<"Aquesta equació no té solució en el camp dels reals"<<endl;
        else {
            x1=(-b+sqrt(discriminant))/(2*a); x2=(-b-sqrt(discriminant))/(2*a);
            cout<<"Solució eq. de segon grau: x1 = "<<x1<<", "<<"x2 = "<<x2<<endl;
        }
    }
    else {
        if (b==0) {
            if (c==0) cout<<"Tautologia"; else cout<<"Contradicció";
        }
        else {
            x=-c/b; cout<<"Solució eq. de primer grau: x = "<<x<<endl;
        }
    }
    return 0;
}