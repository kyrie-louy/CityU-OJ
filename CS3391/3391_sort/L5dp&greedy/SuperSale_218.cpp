#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int price[1005];
int weight[1005];

int dp[35];
int main(){
    int t;
    scanf("%d",&t);

    while(t--){
        int n;
        scanf("%d",&n);
        int p, w;
        for(int i = 0; i < n;i++){
            scanf("%d%d",&p,&w);
            price[i] = p;
            weight[i] = w;
        }

        // dp
        memset(dp,0,sizeof(dp));
        for(int i = 0;i < n;i++){
            for(int j = 30; j >= weight[i];j--){
                dp[j] = max(dp[j],dp[j-weight[i]]+price[i]);
            }
        }

        // add each one
        int g,s, mw;
        scanf("%d",&g);
        s = 0;
        for(int i = 0; i < g; i++)
        {
            scanf("%d",&mw);
            s += dp[mw];
        }
        printf("%d\n",s);
    }
    
    return 0;
}