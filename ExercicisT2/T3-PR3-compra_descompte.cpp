// Entrada: llegeix (preu_inicial i diners) dos nombres reals i descompte un nombre natural
// Sortida: mostra el preu final un cop aplicat el descompte a preu_inicial i el canvi que cal tornar d'acord amb el preu final i els diners lliurats

int main() {
    cout<<"Preu: ";
    double preu_inicial;
    cin>>preu_inicial;

    cout<<"Descompte: ";
    unsigned descompte;
    cin>>descompte;

    double a_pagar=preu_inicial-preu_inicial*descompte/100;
    a_pagar=int(a_pagar*100+0.5)/100.0; 
    cout.setf(ios::fixed); //fixem que mostri dos decimals
    cout.precision(2);
    cout<<"Total: "<<a_pagar<<endl;

    cout<<"Quantitat lliurada: ";
    double diners;
    cin>>diners;

    double canvi=diners-a_pagar;
    cout<<"Canvi: "<<canvi<<endl; //ja tenim fixats els dos decimals, no cal tornar-hi
    return 0;
}
