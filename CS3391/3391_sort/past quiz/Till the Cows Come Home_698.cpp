#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define MAXN 1005
#define INF 0x3f3f3f3f

int graph[MAXN][MAXN];
int d[MAXN];
bool used[MAXN];

void dijkstra(int s,int N){
    memset(d,INF,sizeof(d));
    memset(used,0,sizeof(used));
    d[s] = 0;

    while(1){
        int v = -1;
        for(int u=0;u<N;u++){
            if(!used[u] && (v==-1 || d[u]<d[v]))v=u;
        }

        if(v == -1) break;
        used[v] = 1;

        for(int u = 0;u<N;u++){
            if(graph[v][u]&&!used[u])
                d[u] = min(d[u], d[v]+graph[v][u]);
        }

    }
    
}

int main(){
    int N,T;
    while(scanf("%d%d",&N,&T)!=EOF){

        memset(graph,0,sizeof(graph));

        for(int i=0;i<T;i++){
            int lm1, lm2, cost;
            scanf("%d%d%d",&lm1,&lm2,&cost);

            graph[lm1-1][lm2-1] = cost;
            graph[lm2-1][lm1-1] = cost;
        }

        dijkstra(N-1,N);
        printf("%d\n",d[0]);
    }
    return 0;
}