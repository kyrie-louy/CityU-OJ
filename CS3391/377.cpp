#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX_N=5005;       
#define ll long long 
int s, t;

struct edge{int to; ll cap; int rev;};

vector<edge> G[MAX_N];
int level[MAX_N];   // 拓扑图排序


void add_edge(int from,int to,int cap)
{
    G[from].push_back((edge){to,cap,G[to].size()});
    G[to].push_back((edge){from,0,G[from].size()-1});
}

void bfs()
{
    queue<int>Q;
    Q.push(s);
    level[s]=0;
    while(!Q.empty())
    {
        int x=Q.front();Q.pop();
        for(int i=0;i<G[x].size();i++)
        {
            edge& e=G[x][i];
            if(level[e.to]<0 && e.cap>0)
            {
                level[e.to]=level[x]+1;
                Q.push(e.to);
            }
        }
    }
}

int dfs(int cn, int dest, ll f){
    if(cn == dest) return f;

    for(int i=0; i<G[cn].size(); i++){
        edge &eg = G[cn][i];

        if(level[eg.to]>level[cn] && eg.cap>0){
            int d = dfs(eg.to,dest,min(f,eg.cap));
            if(d>0){
                eg.cap -=d;
                G[eg.to][eg.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

ll max_flow()
{
    ll flow=0;
    while(1){
        memset(level, -1, sizeof(level));

        bfs(); 
        if(level[t]<0)return flow;  // 如果已经没有路能到t,就结束
        ll f;
        f=dfs(s,t,INF);
        while(f>0){
            flow += f;
            f=dfs(s,t,INF);
        }
    }
    return flow;
}

bool rec[MAX_N];
int cnt=0;

void calNum(int v){
    rec[v]=1;
    cnt++;

    for(int i=0;i<G[v].size();i++){
        if(!rec[G[v][i].to] && G[v][i].cap>0){
            calNum(G[v][i].to);
        }
            
    }
}

//#define _DEBUG
int main(){
#ifdef _DEBUG
    freopen("/Users/kyrie/Desktop/input.txt","r",stdin);
#endif

    int n,m;
    ll sum = 0;
    scanf("%d%d\n",&n,&m);
    s = 0;    // start
    t = n+1;    // end
    for(int i=1;i<=n;i++){
        int index, weight;
        scanf("%d\n",&weight);
        if(weight>0) add_edge(s,i,weight), sum+=weight;
        else if(weight<0) add_edge(i,t,-weight);
    }

    for(int i=1;i<=m;i++){
        int e1, e2;
        scanf("%d%d",&e1,&e2);
        add_edge(e1,e2,INF);
    }

    ll res = sum-max_flow();
    calNum(s);
    printf("%d %lld\n",cnt-1,res);
    return 0;
}