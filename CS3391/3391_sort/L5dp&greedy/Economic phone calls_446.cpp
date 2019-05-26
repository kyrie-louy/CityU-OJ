#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

int dp[1005];
int mm,dd,HH,MM;
char sign[1005];
int t[1005];
int y[1005];

//#define _DEBUG
int main(){
    // #ifdef _DEBUG
 	//  freopen("/Users/kyrie/Desktop/input.txt", "r", stdin);
    // #endif
    int n,st,ed,res;

    while(scanf("%d",&n) && n){
        memset(dp,0,sizeof(dp));
        bool sig = 1;
        st = -1, res = 0;

        for(int i = 0;i<n;i++){
            scanf("%d:%d:%d:%d %*s %c",&mm,&dd,&HH,&MM,&sign[i]);
            int sum = (((mm*31)+dd)*24+HH)*60+MM;
            t[i] = sum;
        }
        
        if(sign[0] == '+')st=0;
        else st = -1;

        for(int i =1;i<n;i++){
            if(st == -1 && sign[i] == '+') st = i;
            if(sign[i] == '+') ed = i;

            if(t[i]<t[i-1]) y[i] = y[i-1]+1;
            else y[i] = y[i-1];
        }

        if(st==-1){
            printf("0\n");
        }
        else
        {
            dp[st] = 1;
            for(int i = st+1; i < n;i++){
                dp[i] = dp[i-1]+1;
                for(int j = i-1; j>=0; j--){
                    if(y[i] == y[j] || (y[i]==y[j]+1&&t[i]<t[j]))
                        dp[i] = min(dp[i],dp[j]+1);
                    else break;

                    if(sign[j]=='+')break;
                }
            }
            res = dp[n-1];

            for(int i= n-1;y[i]==y[n-1]&&i>=ed;i--){
                res = min(res,dp[i]);
            }
            printf("%d\n", res);
        }
    } 
    return 0;
}