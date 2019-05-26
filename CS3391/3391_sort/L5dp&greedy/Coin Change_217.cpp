#include<stdio.h>
#include<string.h>
using namespace std;
const int MAX = 7500;
int coins[5] = {1,5,10,25,50};
int dp[MAX];

int main(){
    int n;
    dp[0] = 1;

    for(int i = 0;i<5;i++){
        for(int j = coins[i];j<MAX;j++){
            dp[j] += dp[j-coins[i]];
        }
    }
    while(scanf("%d",&n)!=EOF){
        printf("%d\n",dp[n]);
    }  
}