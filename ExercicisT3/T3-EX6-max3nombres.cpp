// Entrada: llegeix tres nombre enters (a,b,c)
// Sortida: escriu màxim(a,b,c)
#include <iostream>
using namespace std;
int main(){
    int a, b, c;
    cout<<"Primer nombre enter: "; cin>>a;
    cout<<"Segon nombre enter: "; cin>>b;
    cout<<"Tercer nombre enter: "; cin>>c;
    int max;
    if (a>=b and a>=c)
        max=a;
    else
        if (b>=c)
            max=b;
        else
            max=c;
    cout<<"Màxim de "<<a<<", "<<b<<", "<<c<<" és "<<max<<endl;
    return 0;
}
