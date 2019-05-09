#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int dp[51][51][51][51];
char str[51][51];

bool isMatch(int hh, int ww,int a, int b){
    for(int i = a;i<a+hh;i++){
        if(str[i][b]!='0' || str[i][b+ww-1]!='0')
            return 0;
    }
    for(int i =b;i<b+ww;i++){
        if(str[a][i]!='0' || str[a+hh-1][i]!='0')
            return 0;
    }
    return 1;
}

int main(){
    int n,r,len;
    char s[51];
    scanf("%d",&n);

    for(int k =1;k<=n;k++){
        memset(dp,0,sizeof(dp));
        scanf("%d",&r);
        getchar();

        for(int i = 0; i < r; i++)
        {
            scanf("%s",s);
            getchar();

            len = strlen(s);
            for(int j=0;j<len;j++){
                str[i][j] = s[j];
            }
        }

        //dp
        for(int h = 3; h <= r; h++)
        {
            for(int w =3; w <= len;w++){
                for(int i = 0; i<= r-h;i++){
                    for(int j = 0; j <= len-w;j++){
                        int m = i+h-1;
                        int n = j+w-1;

                        if(isMatch(h,w,i,j)){
                            dp[i][j][m][n] = max(dp[i][j][m][n],dp[i+1][j+1][m-1][n-1]+1);
                        }
                        else
                        {
                            dp[i][j][m][n] = max(dp[i][j][m][n],dp[i+1][j][m][n]);
                            dp[i][j][m][n] = max(dp[i][j][m][n],dp[i][j+1][m][n]);
                            dp[i][j][m][n] = max(dp[i][j][m][n],dp[i][j][m-1][n]);
                            dp[i][j][m][n] = max(dp[i][j][m][n],dp[i][j][m][n-1]);
                        }
                        
                    }
                }
            }
        }
    
        printf("Case #%d: %d\n",k,dp[0][0][r-1][len-1]);
    }
    return 0;
}