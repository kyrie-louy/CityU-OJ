#include<stdio.h>
#include<string.h>
#include<algorithm>
#include <iostream>
using namespace std;
char brackets[105];
int dp[105][105];

#define _DEBUG
int main(){
    #ifdef _DEBUG
 	  freopen("/Users/kyrie/Desktop/input.txt", "r", stdin);
    #endif
    int n;
    scanf("%d",&n);
    getchar();
    getchar();

    for(int r = 0;r<n;r++){
        gets(brackets);
        getchar();
        int len = strlen(brackets);

        int j;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<len;i++) dp[i][i] = 1;
        //for(int i=1;i<len;i++) dp[i][i-1]=0;
        for(int l=1;l<len;l++){
            for(int i=0;i+l<len;i++){
                j = i+l;
                dp[i][j] = 10000;
                if((brackets[i]=='(' && brackets[j]==')') || (brackets[i]=='['&& brackets[j]==']')){
                    dp[i][j] = dp[i+1][j-1];
                } 
                //dp[i][j] = min(dp[i][j],min(dp[i+1][j]+1,dp[i][j-1]+1));
                
                for(int m = i; m<j; m++){
                    if(dp[i][j] > dp[i][m]+dp[m+1][j])
                        dp[i][j] = dp[i][m]+dp[m+1][j];
                }
            }
        }

        if(r==n-1)
             printf("%d\n",dp[0][len-1]+len);
        else
            printf("%d\n\n",dp[0][len-1]+len);
    }
    return 0;
}