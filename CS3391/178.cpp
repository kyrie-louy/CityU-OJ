#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
#define MAX_V 1050
#define INF 0x3f3f3f3f

struct edge {int to, cap, rev;};
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

#define _DEBUG
int main(){
// #ifdef _DEBUG
//     freopen("/Users/kyrie/Desktop/input.txt", "r", stdin);
// #endif
    int nk, np;
    while(~scanf("%d%d\n",&nk,&np)){
        if(nk==0 && np==0) break;

        for(int i=0;i<MAX_V;i++){
            G[i].clear();
        }
        int s = nk + np, t = s+1;
        int sum = 0;
        for(int i=0;i<np;i++){
            add_edge(s,i,1);
        }
        for(int i=0;i<nk;i++){
            int l;
            scanf("%d",&l);
            sum += l;
            add_edge(np+i,t,l);
        }
        for(int i=0;i<np;i++){
            int num;
            scanf("%d",&num);

            for(int j=0;j<num;j++){
                int neighbor;
                scanf("%d",&neighbor);
                add_edge(i,neighbor+np-1,1);
            }
        }

        if(max_flow(s,t)==sum){
            printf("%d\n",1);
        }
        else
            printf("%d\n",0);
    }
    return 0;
}