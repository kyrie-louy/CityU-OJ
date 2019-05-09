#include<stdio.h>
#include <iostream>
#include<cstring>
#include<limits.h>
#define MAXN 1000 
using namespace std;

int dp[MAXN];
int w[MAXN] = {0,2,1,3,2};
int v[MAXN] = {0,3,2,4,2};
int W = 5, n = 4;

int max(int a, int b){
    if(a>b)
        return a;
    else
        return b;
}

int solve(int n, int W){
    // memset(dp,0,sizeof(dp));
    dp[0] = 0;
    for(int i = 1;i < sizeof(dp);i++){
        dp[i] = INT_MIN;
    }
    
    for(int i = 1; i <= n; i++)
    {
        
        for(int j = W; j >= 0; j--)
        {
            
            if (j < w[i]) {
                dp[j] = dp[j]; 
            }
            else{
                dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
            }
        }
        
    }
    return dp[W];
}

int main()
{
    cout<<solve(n, W)<<endl;
    return 0;
}

