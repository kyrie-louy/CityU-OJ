#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;

const int MAX_N = 505;
const int INF = 0x3f3f3f3f;
int dist[MAX_N][2];
int n,r;

struct junction{
    // 0: walk, 1:ride
    int v, state, dist; // state when arrive at the point
    bool operator < (const junction &other) const
    {
        return dist > other.dist;
    }
};

struct edge{
    int to, cost;
};

vector<edge> graph[MAX_N];

int dijkstra(){
    dist[0][1] = 0;
    priority_queue<junction> q;
    q.push((junction){0,1,0});

    while(!q.empty()){
        junction tp = q.top();
        q.pop();

        int v = tp.v;int state = tp.state;int d = tp.dist;
        if(dist[v][state] < d)continue;

        int edgeNum = graph[v].size();
        for(int i = 0; i<edgeNum;i++){
            int to = graph[v][i].to;
            if(d+graph[v][i].cost < dist[to][1-state]){
                dist[to][1-state] = d + graph[v][i].cost;
                q.push((junction){to,1-state,dist[to][1-state]});
            }
        }
    }

    return dist[n-1][1];
}

//#define _DEBUG
int main(){ 
    // #ifdef _DEBUG
 	//   freopen("/Users/kyrie/Desktop/input.txt", "r", stdin);
    // #endif
    int idx = 1;
    while(scanf("%d%d",&n,&r)!=EOF){
        // init
        memset(dist,INF,sizeof(dist));
        for(int i = 0;i<MAX_N;i++){
            graph[i].clear();
        }

        int to, from, w;
        for(int i = 0;i<r;i++){
            scanf("%d%d%d",&from,&to,&w);
            graph[from].push_back((edge){to,w});
            graph[to].push_back((edge){from,w});
        }

        printf("Set #%d\n",idx++);
        if(dijkstra()==INF)
            printf("?\n");
        else
        {
            printf("%d\n",dijkstra());
        }
    }
    return 0;
}