#include<stdio.h>
#include<string.h>
using namespace std;

bool flag[1299711];
int prime[1299711];

int count;

void getprime(int l){
    int i, j;
    memset(flag,1,sizeof(flag));
    count = 0;
    for(i=2;i<=l;i++){
        if(flag[i]==true)
            prime[++count]=i;
        for(j=1;j<=count&&i*prime[j]<=l;j++){
            flag[i*prime[j]]=false;
            if(i%prime[j]==0)break;
        }
    }
}

int calPrimeGap(int n){
    if(flag[n]==1)
        return 0;
    else
    {
        int t = n+1;
        int b = n-1;
        while(flag[t]==0){
            t++;
        }
        while(flag[b]==0){
            b--;
        }
        return t-b;   
    }
    
}

//#define _DEBUG
int main(){
// #ifdef _DEBUG
// 	freopen("/Users/kyrie/Desktop/input.txt", "r", stdin);
// #endif
    int n;
    getprime(1299709);
    //printf("hh:%d\n",flag[492170]);
    // for(int i=0;i<100000;i++){
    //     printf("%d ",flag[i]);
    // }
    // printf("\n");
    while(scanf("%d",&n)){
        if(n==0)break;
        
        int res = calPrimeGap(n);
        printf("%d\n",res);
        
    }
    return 0;
}