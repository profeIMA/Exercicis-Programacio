#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    
    srand((unsigned int)time(0));
    
    for (unsigned i=1; i<=10; i++) {
        int dau1=rand()%6+1;
        int dau2=rand()%6+1;
        cout<<dau1<<" "<<dau2<<endl;
    }
    
    return 0;
}
