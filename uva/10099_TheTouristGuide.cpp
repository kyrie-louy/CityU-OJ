#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
/*
最小最大问题（最大生成树）
问题：导游最少需要几次能将所有旅客从起点带到终点
注意：每次运送必须把导游算上
*/

#define MAX_V 105
#define INF 0x3f3f3f3f
int d[MAX_V][MAX_V];
int n, r;   // city number, segement number
int s, dest, t;    // start, dest, number of tourists

void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                d[i][j] = max(d[i][j],min(d[i][k],d[k][j]));
        }
    }
}

void init_d(){
    for(int i=0;i<MAX_V;i++){
        for(int j=0;j<MAX_V;j++){
            d[i][j] = 0;
        }
    }
}

//#define _DEBUG
int main(){
#ifdef _DEBUG
    freopen("/Users/kyrie/Desktop/input.txt","r",stdin);
#endif

    int idx=1;
    while(~scanf("%d%d",&n,&r)){
        if(n==0&&r==0) break;
        
        init_d();
        int c1,c2,p;
        for(int i=0;i<r;i++){
            scanf("%d%d%d",&c1,&c2,&p);
            d[c1][c2] = p;
            d[c2][c1] = p;
        }
        scanf("%d%d%d",&s,&dest,&t);
        floyd();
        int res = d[s][dest];
      
        printf("Scenario #%d\n",idx++);
        printf("Minimum Number of Trips = ");
        int cnt=0;
        while (t>0)
        {
            t -= (res-1);
            cnt++;
        }
        printf("%d\n\n",cnt);
    }
    return 0;
}