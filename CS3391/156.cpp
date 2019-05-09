#include<stdio.h>
#include<string.h>
using namespace std;
bool flag[1005];
int prime[175];
int count;

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

int calKey(int n){
    int sum = 0 , mx = 0;
    for(int i=1;i<=count;i++){
        if(n%prime[i]==0){
            sum+=prime[i];
            mx = prime[i];
        }
        while(n%prime[i]==0)n/=prime[i];
        if(n==1)break;
    }
    if(n!=1)mx = n,sum+=n;
    return -sum+2*mx;
}
int main(){
    int a,b;
    getprime(1005);
    while(scanf("%d%d",&a,&b)){
        if(a==0&&b==0) break;

        if (calKey(a)>calKey(b)) {
            printf("a\n");
        }
        else
        {
            printf("b\n");
        }
    }
    return 0;
}
