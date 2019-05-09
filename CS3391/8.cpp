#include<stdio.h>
#include<cstring>
using namespace std;

int main()
{
    // ini
    int n, m, k;
    int dp[2][10005];

    while(scanf("%d%d%d",&n,&m,&k)!=EOF && (n||m||k)){
        
        // situation with only one dice
        memset(dp,0,sizeof(dp));
        for(int i = 1; i <= m; i++){
            dp[1][i] = 1;
        }

        // situation with more than one dice
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j <= i*m; j++){
                for(int r = 1; r <= m; r++){
                    dp[(i+1)&1][j+r] += dp[i&1][j];
                }
            }
            memset(dp[i&1],0,sizeof(dp[1]));
        }
        
        int res=0;
        int i,j;
        for(i=1; i<=k+1; i++)
            res+=dp[n&1][i];
        for(j=2;i<=n*m; i++,j++)
            res+=dp[n&1][i]*j;
        int count=1;
        for(int i=1;i<=n;i++)
            count*=m;
    printf("%.8lf\n",res*1.0/count);
    }
    return 0;
}
