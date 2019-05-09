#include<stdio.h>
#include<string.h>
#include<cmath>
#include<algorithm>
using namespace std;
struct stone{
    int x,y;
};
stone road[205];
float d[205]; // 0:freddy 1:fiona
bool used[205];

float cost(int from, int to){
    return sqrt(pow((road[to].x-road[from].x),2)+pow((road[to].y-road[from].y),2));
}

float dijkstra(int V){
    fill(d,d+V,1005);
    fill(used,used+V,0);
    d[0] = 0;

    while(true){
        int v = -1;
        for(int u = 0;u<V;u++){
            if(!used[u] && (v==-1 || d[u]<d[v])) v = u;
        }
        
        if(v == -1) break;
        used[v] = 1;

        for(int u = 0; u < V;u++){
            d[u] = min(d[u],max(d[v],cost(v,u)));
        }
    }
    return d[1];
}

//#define _DEBUG
int main(){
    // #ifdef _DEBUG
 	// freopen("/Users/kyrie/Desktop/input.txt", "r", stdin);
    // #endif
    int n;
    int idx = 1;
    while(scanf("%d",&n) && n!=0){
        // stone data
        for(int i = 0; i < n; i++)
        {
            int tmp_x,tmp_y;
            scanf("%d%d",&tmp_x,&tmp_y);
            stone tmp = {tmp_x,tmp_y};
            road[i] = tmp;
        }
        
        printf("Scenario #%d\n",idx++);
        printf("Frog Distance = %.3f\n\n",dijkstra(n));
    }
    
    return 0;
}