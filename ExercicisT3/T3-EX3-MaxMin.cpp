// Entrada: llegeix dos nombres enters (nombre1,nombre2)
// Sortida: escriu màxim(nombre1,nombre2) i mínim(nombre1,nombre2)

#include <iostream>
using namespace std;

int main(){
    int nombre1, nombre2;
    cout<<"Primer nombre enter: ";
    cin>>nombre1;
    cout<<"Segon nombre enter: ";
    cin>>nombre2;
    int max=nombre1, min=nombre2;
    if (nombre1<nombre2) {
        min=nombre1;
        max=nombre2;
    }
    cout<<"Màxim de "<<nombre1<<" i "<<nombre2<<" és "<<max<<endl;
    cout<<"Mínim de "<<nombre1<<" i "<<nombre2<<" és "<<min<<endl;
    return 0;
}
