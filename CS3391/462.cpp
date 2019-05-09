#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;
#define top 1229000
#define MAX 10000001
bool flag[MAX];
int prime[top+5];
int cnt;

void getprime(int l){
    int i, j;
    memset(flag,0,sizeof(flag));
    cnt = 0;
    for(i=2;i<=l;i++){
        if(flag[i]==0)
            prime[cnt++]=i;
        
        for(j=0;j<cnt&&i*prime[j]<l;j++){
            flag[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}

bool judge(int num){
    if(num<=MAX) return !flag[num];
    else{
        for(int i=0;i<cnt&&prime[i]<=sqrt(num);i++){
            if(num%prime[i]==0) return 0;
        }
    }
    return 1;
}

// 1 is not a prime number
int main(){
    getprime(MAX);
    // for(int i=0;i<100;i++){
    //     printf("%d ",prime[i]);
    // }
    
    int n;
    while(~scanf("%d",&n)){
        if(n<5)
            printf("%d is not the sum of two primes!\n",n);
        else if(n&1){    // odd 
            int choice = 0;
            if(judge(n-2))printf("%d is the sum of 2 and %d.\n",n,n-2);
            else printf("%d is not the sum of two primes!\n",n);            
        }         
        else        // even
        {
            bool rec = 0;
        
            for(int i = n/2;i>=2;i--){
                if(i!=(n-i)&&judge(i)&&judge(n-i)){
                    rec = 1;
                    printf("%d is the sum of %d and %d.\n",n,i,n-i);
                    break;
                }
            }
            if(!rec){
                printf("%d is not the sum of two primes!\n",n);
            }
            
        }
        
    }
    return 0;
}