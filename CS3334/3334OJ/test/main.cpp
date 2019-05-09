#include<stdio.h>
#include <iostream>
#include<cstring>
#define MAXN 1000
using namespace std;

int dp[MAXN][MAXN];
int w[MAXN] = {0,2,1,3,2};
int v[MAXN] = {0,3,2,4,2};
int W = 8, n = 7;

int max(int a, int b){
    if(a>b)
        return a;
    else
        return b;
}

int solve(int n, int W){
    memset(dp,0,sizeof(dp));
    
    for(int i = 1; i <= n; i++)
    {
        
        for(int j = 0; j <= W; j++)
        {
            
            if (j < w[i]) {
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
            }
        }
        
    }
    return dp[n][W];
}

int main()
{
    cout<<solve(n, W)<<endl;
    return 0;
}

