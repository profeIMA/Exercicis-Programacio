/* Donat un caràcter, escriure un comentari que digui si és un dígit, una lletra minúscula, una lletra majúscula o un altre tipus de caràcter */
// Entrada: llegeix un caràcter (caracter)
// Sortida: escriu un comentari que indica si és un dígit, una lletra minúscula, una lletra majúscula o un altre tipus de caràcter

#include <iostream>
using namespace std;

int main(){
    char c;
    cout<<"Caràcter: ";
    cin>>c;
    cout<<c<<" és ";
    if (c>='0' and c<='9') cout << "un dígit" << endl;
    else if (c>='a' and c<='z') cout << "una lletra minúscula" << endl;
    else if (c>='A' and c<='Z') cout << "una lletra majúscula" << endl;
    else cout << "un altre caràcter" << endl;

    return 0;
}
