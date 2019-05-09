#include <iostream>
using namespace std;

void Towers(int n, int source, int target, int interm){
    if(n == 1)
        cout<<"From"<<source<<"to"<<target<<endl;
    else
    {
        Towers(n-1, source, interm, target);
        Towers(1, source, target, interm);
        Towers(n-1, interm, target, source);
    }
}
int main(int argc, const char * argv[]) {
    Towers(3, 111, 333, 222);
    return 0;
}
