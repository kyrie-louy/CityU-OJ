#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char s[1005];
char t[1005];
int dp[1005][1005];
int n,m;

int main(){
    int num;
    scanf("%d",&num);

    while(num--){
        scanf("%s",s);
        scanf("%s",t);
        n = strlen(s);
        m = strlen(t);
        memset(dp,0,sizeof(dp));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(s[i] == t[j])
                    dp[i+1][j+1] = dp[i][j]+1;
                else
                    dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
            }  
        }
        printf("%d\n",n+m-dp[n][m]);
    }
    return 0;
}
