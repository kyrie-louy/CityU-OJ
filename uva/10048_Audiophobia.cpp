#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_V 105
#define INF 0x3f3f3f3f

/*
经典的最大最小问题
问题：求得所有从起点到终点的路的最大边的最小值
方法：对Floyd的稍微修改
*/
int c, s, q;
int d[MAX_V][MAX_V];

void floyd(){
    for(int k=1;k<=c;k++){
        for(int i=1;i<=c;i++){
            for(int j=1;j<=c;j++)
                d[i][j] = min(d[i][j],max(d[i][k],d[k][j]));
        }
    }
}

void init_d(){
    for(int i=0;i<MAX_V;i++){
        for(int j=0;j<MAX_V;j++){
            d[i][j] = INF;
        }
    }
}
void zdh(){
    cout << c << endl;
    for(int i=1;i<=c;i++){
        for(int j=1;j<=c;j++){
            printf("%d ",d[i][j]);
        }
        printf("\n");
    }
}
//#define _DEBUG
int main(){
#ifdef _DEBUG
    freopen("/Users/kyrie/Desktop/input.txt","r",stdin);
#endif
    int idx = 1;
    bool first = 1;
    while (~scanf("%d%d%d",&c,&s,&q))
    {
        if(c==0&&s==0&&q==0) break;
        
        if(first==1)first=0;
        else printf("\n");

        init_d();
        int c1,c2,lev;
        for(int i=1;i<=s;i++){
            scanf("%d%d%d",&c1,&c2,&lev);
            d[c1][c2] = lev;
            d[c2][c1] = lev;
        }
        floyd();
        printf("Case #%d\n",idx++);
        for(int i=1;i<=q;i++){
            int q1,q2;
            scanf("%d%d",&q1,&q2);
            int res = d[q1][q2];
            if(res == INF)  printf("no path\n");
            else printf("%d\n",res);
        }
    }
    
    return 0;
}