#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
#define MAX_V 105
#define INF 0x3f3f3f3f

struct edge {int to, cap, rev;};
vector<edge> G[MAX_V];
bool used[MAX_V];
void add_edge(int from, int to, int cap){
    G[from].push_back((edge){to, cap, G[to].size()});
    G[to].push_back((edge){from, cap, G[from].size()-1});
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

#define _DEBUG
int main(){
    int n;
    int step = 1;
    while(~scanf("%d\n",&n)){
        if(n==0)break;

        for(int i=0;i<MAX_V;i++){
            G[i].clear();
        }
        int src, dest, c;
        scanf("%d%d%d\n",&src,&dest,&c);
        
        for(int i=0;i<c;i++){
            int f, t, cost;
            scanf("%d%d%d\n",&f,&t,&cost);
            add_edge(f,t,cost);
        }

        printf("Network %d\n",step);
        step++;
        printf("The bandwidth is %d.\n",max_flow(src,dest));
        printf("\n");
    }
    return 0;
}