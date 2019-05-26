#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
#define MAX_V 105

/*
一道非常经典的最长公共子序列问题
用dp即可解决
*/
int dp[MAX_V][MAX_V];

//#define _DEBUG
int main(){
#ifdef _DEBUG
    freopen("/Users/kyrie/Desktop/input.txt","r",stdin);
#endif

    string mom;
    string dad;
    int idx=1;
    while (getline(cin,mom))
    {
        if(mom =="#") break;
        
        getline(cin,dad);

        int mlen = mom.length();
        int dlen = dad.length();

        for(int i=0;i<mlen;i++){
            for(int j=0;j<dlen;j++){
                if(mom[i]==dad[j])
                    dp[i+1][j+1] = dp[i][j]+1;
                else
                {
                    dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
                }
                
            }
        }

        printf("Case #%d: you can visit at most %d cities.\n",idx++,dp[mlen][dlen]);
        for(int i=0;i<mlen;i++){
            for(int j=0;j<dlen;j++)
                dp[i][j]=0;
        }
    }
    
    return 0;
}