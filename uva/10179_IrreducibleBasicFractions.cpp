#include <stdio.h>
#include <string.h>
using namespace std;
#define MAX_V 50001
/*
题目：计算一个给定数的欧拉定理（1~n-1中和n互质的数的个数）
欧拉定理：【小于n的正整数中与n互质的数】的个数，需要素数表从旁辅助
*/

bool flag[MAX_V];
int prime[MAX_V];
int count;
int fac[30];

void getprime(int l){
    int i, j;
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

//#define _DEBUG
int main(){
#ifdef _DEBUG
    freopen("/Users/kyrie/Desktop/input.txt","r",stdin);
#endif
    
    int n;

    getprime(50000);
    while (~scanf("%d",&n))
    {
        if(n==0) break;
        int idx=0,s=1,m=n;

        while (s<count && m>1)
        {
            if(m%prime[s]==0){
                fac[idx++] = prime[s];
                while (m%prime[s]==0)
                {
                    m /= prime[s];
                }          
            }
            s++;
        }      
        if(m>1) fac[idx++]=m;
        int res = n;
        for(int i=0;i<idx;i++){
            res = res*(1.0-(double)(1.0/(double)fac[i]));
        }
        printf("%d\n",res);
    } 
    return 0;
}