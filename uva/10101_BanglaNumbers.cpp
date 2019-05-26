#include <stdio.h>
using namespace std;

int idx = 1;
void output(long long n){
    long long tmp = n;
    if(tmp/10000000 >0){
        output(tmp/10000000);
        printf(" kuti");
        output(tmp%10000000);
    }
    else{
        if(tmp/100000 >0){
            printf(" %lld lakh",tmp/100000);
            tmp %= 100000;
        }
        if(tmp/1000 >0){
            printf(" %lld hajar",tmp/1000);
            tmp %= 1000;
        }
        if(tmp/100>0){
            printf(" %lld shata",tmp/100);
            tmp %= 100;
        }
        if(tmp!=0) printf(" %lld",tmp);
    }
}
#define _DEBUG
int main(){
#ifdef _DEBUG
    freopen("/Users/kyrie/Desktop/input.txt","r",stdin);
#endif

    long long num;

    while (~scanf("%lld",&num))
    {
        printf("%4d.",idx++);
        output(num);
        if(num==0LL) printf(" 0");
        printf("\n");
    }
    
    return 0;
}