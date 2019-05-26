#include <stdio.h>
#include <string.h>
using namespace std;
#define MAX_V 50001
#define INF 2147483647
#define ll long long

/*
依旧是简单的打素数表问题，当需要打的值过大时，可以打到根号n，再用is_prime判断
一开始一直TLE，后来不再用两个for loop而是记住上一个素数，然后ac了
*/

bool flag[MAX_V];
ll prime[MAX_V];
ll count;

void getprime(ll l){
    ll i, j;
    memset(flag,1,sizeof(flag));
    count = 0;
    for(i=2;i<=l;i++){
        if(flag[i]==true)
            prime[++count]=i;
        for(j=1;j<=count&&i*prime[j]<l;j++){
            flag[i*prime[j]]=false;
            if(i%prime[j]==0)break;
        }
    }
}

bool is_prime(ll num){
    if(num<MAX_V) return flag[num];
    ll i = 1;
    while (i<count && prime[i] < num)   // ！！！这个地方不能用小于等于（素数可以被自己除）
    {
        if(num % prime[i]==0)
            return false;
        i++;
    }
    return true;
}

//#define _DEBUG
int main(){
#ifdef _DEBUG
    freopen("/Users/kyrie/Desktop/input.txt","r",stdin);
#endif

    getprime(MAX_V);
    //prllf("%d\n",is_prime(1));
    ll l, u;
    ll dist, close;
    ll maxl, maxu, minl, minu, last=-1;

    while(scanf("%lld%lld",&l,&u)==2){
        ll dist = -INF, close=INF;
        ll maxl, maxu, minl, minu, last=-1;
        for(ll i=l;i<=u;i++){
            if(i==1) continue;
            if(is_prime(i)){
                if(last==-1) last = i;
                else
                {
                    if(i-last < close){
                        close = i-last;
                        minl=last, minu=i;
                    }
                    if(i-last>dist){
                        dist=i-last;
                        maxl=last,maxu=i;
                    }
                    last = i;
                }
                
            }
        }
        if(dist==-INF&&close==INF) printf("There are no adjacent primes.\n");
        else
        {
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n",minl,minu,maxl,maxu);
        }
        
    }
    return 0;
}