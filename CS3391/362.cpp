#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string.h>
using namespace std;
#define MAX_V 210
#define INF 0x3f3f3f3f

struct edge {int to, cap, rev;};
int xArr[110];
int yArr[110];
vector<edge> G[MAX_V];
bool used[MAX_V];
void add_edge(int from, int to, int cap){
    G[from].push_back((edge){to, cap, G[to].size()});
    G[to].push_back((edge){from, 0, G[from].size()-1});
}

int dfs(int v, int t, int f){
    if(v==t) return f;

    used[v] = 1;
    for(int i=0;i<G[v].size();i++){
        edge &e = G[v][i];
        if(!used[e.to] && e.cap > 0){
            int d = dfs(e.to, t, min(f, e.cap));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t){
    int flow = 0;
    for(;;){
        memset(used, 0, sizeof(used));
        int f = dfs(s,t,INF);
        if (f==0) return flow;
        flow += f;
    }
}

double calDist(int x1, int y1, int x2, int y2){
    int x = x1 - x2;
    int y = y1 - y2;
    return sqrt(x*x+y*y);
}

#define _DEBUG
int main(){
// #ifdef _DEBUG
//     freopen("/Users/kyrie/Desktop/input.txt", "r", stdin);
// #endif

    int l, w, n, d, index=1;
    while(~scanf("%d%d%d%d\n",&l,&w,&n,&d)){
        if(l==0&&w==0&&n==0&&d==0) break;

        for(int i=0;i<MAX_V;i++) G[i].clear();
        
        for(int i=1; i<=n; i++)
            scanf("%d%d",&xArr[i],&yArr[i]);
        
        int num = 2*n+2;
        for(int i=1;i<=n;i++){
            add_edge(i,n+i,1); // connect in-vertice and out-vertice

            if(yArr[i]-d<=0)
                add_edge(0,i,INF);
            if(w-yArr[i]<=d)
                add_edge(i+n, num-1,INF);
            
            for(int j=i+1;j<=n;j++){
                if(calDist(xArr[i],yArr[i],xArr[j],yArr[j])<=2*d){
                    add_edge(i+n,j,INF);
                    add_edge(j+n,i,INF);
                }
            }                
        }
        printf("Case %d: %d\n",index++,max_flow(0,num-1));

    }
    return 0;
}