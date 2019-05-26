#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm> 
#include <set>
#include <cassert>
using namespace std;

bool flag[70];
int prime[70];

int cnt;
void getprime(int l){
    int i, j;
    memset(flag,1,sizeof(flag));
    cnt = 0;
    for(i=2;i<=l;i++){
        if(flag[i]==1)
            prime[cnt++]=i;
        
        for(j=0;j<cnt&&i*prime[j]<l;j++){
            flag[i*prime[j]]=0;
            if(i%prime[j]==0)break;
        }
    }
}

int main(){
    getprime(70);

    set<unsigned long long> spower;
    spower.insert(1);

    for (int i = 2; i < 65536; i++)
    {
        for(int j=4; j<(int)ceil(64.0 * log(2.0) / log(i));j++){
            unsigned long long res = 1LL;
            if(flag[j]==0){
                int index = j;
                unsigned long long base = i;
                while(index){
                    if(index&1) res *= base;
                    base *= base;
                    index >>= 1;
                }
                if(!spower.count(res)) spower.insert(res);
            }
        }
    }

    for(set<unsigned long long>::iterator it=spower.begin(); it!=spower.end();it++){
        printf("%llu\n",*it);
    }

    return 0;
}