#include<stdio.h>
#include<algorithm>
using namespace std;

#define INF 0x3f3f3f3f
int eNum[15];
int dp[15][1005];     // store the min cost
int main(){
    int N;  // month of project

    while(scanf("%d",&N) && N!=0){
        int hc, sc, fc;
        scanf("%d%d%d",&hc,&sc,&fc);

        for(int i=0;i<N;i++){
            scanf("%d",&eNum[i]);
        }

        memset(dp,INF,sizeof(dp));
        dp[0][eNum[0]]= hc*eNum[0]+sc*eNum[0];
        // dp
        for(int i=1;i<N;i++){
            for(int j=eNum[i];j<1001;j++){
                int minNum = INF;
                for(int k=eNum[i-1];k<1001;k++){
                    if(j > k){
                        minNum = min(minNum,dp[i-1][k]+j*sc+(j-k)*hc);
                    }
                    else
                    {
                        minNum = min(minNum, dp[i-1][k]+j*sc+(k-j)*fc);
                    }
                }
                dp[i][j] = minNum;   
            }
        }

        int res = INF;
        for(int i=eNum[N-1];i<1001;i++){
            if(dp[N-1][i] < res)
                res = dp[N-1][i];
        }
        printf("%d\n",res);
        // for(int i =0;i<N;i++){
        //     printf("%d\n",res);
        // }

    }
    


}