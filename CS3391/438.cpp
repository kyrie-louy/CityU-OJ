#include<stdio.h>
using namespace std;

int main(){
    int T; 
    scanf("%d",&T);

    for(int i = 0; i < T;i++){
        int N;
        scanf("%d",&N);
        if(N <= 2)
            printf("%d\n", 0);
        else
            printf("%d\n",N-2);
    }
    return 0;
}
