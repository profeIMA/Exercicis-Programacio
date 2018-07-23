#include <iostream>
using namespace std;

int main() {
    double sum = 0;
    int count = 0;
    double salary = 0;
    
    // get all the inputs
    cout << "Enter salaries, -1 to finish: ";
    while (salary != -1) {
        cin >> salary;
        if (salary != -1) {
            sum = sum + salary;
            count++;
        }
    }
    
    // process and display the average
    if (count > 0) {
        double average = sum / count;
        cout << "Average salary: " << average << endl;
    }
    else cout << "No data" << endl;
    
    return 0;
}

