#include <bits/stdc++.h>
using namespace std;
#define MAX_V 310
#define INF 0x3f3f3f3f
struct edge {int to, cap, rev;};

int xArr[MAX_V];
int yArr[MAX_V];
double colors[MAX_V];
int radius[MAX_V];
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

//#define _DEBUG
int main(){
#ifdef _DEBUG
    freopen("/Users/kyrie/Desktop/input.txt","r",stdin);
#endif

    int k;
    scanf("%d",&k);

    while(k--){
        int n;
        int s, t;
        scanf("%d",&n);

        for(int i=0;i<MAX_V;i++) G[i].clear();
        for(int i=1;i<=n;i++){
            scanf("%lf%d%d%d",&colors[i],&xArr[i],&yArr[i],&radius[i]);
            if(colors[i]==400.0) s=i;
            if(colors[i]==789.0) t=i;
        }

        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(calDist(xArr[i],yArr[i],xArr[j],yArr[j])<=(radius[i]+radius[j])){
                    if(colors[i]<colors[j]) add_edge(i,j,1);
                    else if(colors[i]>colors[j]) add_edge(j,i,1);
                }
            }
        }

        int res1=max_flow(s,t);
        int res2=max_flow(s,t);
        if((res1+res2)>=2)
            printf("Game is VALID\n");
        else
            printf("Game is NOT VALID\n");
    }
    return 0;
}