#include <iostream>
#include <string>
using namespace std;

int main() {
    const int FREEZE_C = 0;
    const int BOIL_C = 100;
    const int FREEZE_F = 32;
    const int BOIL_F = 212;
    
    cout << "Enter the temperature in degrees: ";
    int temp;
    cin >> temp;
    cout << "Enter C for Celsius or F for Fahrenheit: ";
    string scale;
    cin >> scale;
    
    if (scale == "C") {
        if (temp <= FREEZE_C)
            cout << "Solid" << endl;
        else if (temp >= BOIL_C)
            cout << "Gas" << endl;
        else
            cout << "Liquid" << endl;
    }
    else {
        if (temp <= FREEZE_F)
            cout << "Solid" << endl;
        else if (temp >= BOIL_F)
            cout << "Gas" << endl;
        else
            cout << "Liquid" << endl;
    }
    return 0;
}
