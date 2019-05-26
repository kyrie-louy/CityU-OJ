#include<stdio.h>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;
const int MAX_N = 105;
const int MAX = 0x3f3f3f3f;

struct monster
{
    int i, cost,maxlev, minlev;
    bool operator < (const monster &other) const{
        return cost > other.cost;
    }
};

struct transE
{
    int to, tsCost;
};

// init
priority_queue<monster> que;
vector<transE> graph[MAX_N];
int price[MAX_N];
int level[MAX_N];
int M, N;

#define _DEBUG
int main(){
    #ifdef _DEBUG
 	  freopen("/Users/kyrie/Desktop/input.txt", "r", stdin);
    #endif

    // M: number of monsterter
    // N: number of group
    while(scanf("%d%d",&M,&N)!=EOF){
        // init
        while(!que.empty()){
            que.pop();
        }
        for(int i =0;i<MAX_N;i++){
            graph[i].clear();
        }
        memset(price,MAX,sizeof(price));
        memset(level,0,sizeof(level));
        for(int i = 1; i <= N; i++)
        {
            // P: cost of monsterter i
            // L: level of monsterter i
            // X: number of transform
            int P, L, X;
            scanf("%d%d%d",&P,&L,&X);
            que.push((monster){i,P,L,L});
            price[i] = P;
            level[i] = L;

            // T: transform monsterter
            // V: transform cost
            for(int j = 1;j<=X;j++){
                int T, V;
                scanf("%d%d",&T,&V);
                graph[T].push_back((transE){i,V});
            }
        }

        while(!que.empty()){
            monster m = que.top(); que.pop();
            int idx = m.i;

            // printf("i: %d, cost: %d\n",idx,m.cost);
            if(idx == 1){
                printf("%d\n",m.cost);
                break;
            }
            
            for(int i = 1; i <= graph[idx].size(); i++)
            {
                int t = graph[idx][i-1].to;
                int c = graph[idx][i-1].tsCost;
                int maxl = max(m.maxlev,level[t]);
                int minl = min(m.minlev,level[t]);

                if((maxl-minl)<=M && (price[t] > m.cost+c)){
                    //price[t] = m.cost+c;
                    que.push((monster){t,m.cost+c,maxl,minl});
                    //printf("push: %d %d\n",t,m.cost+c);
                }
            }          
        }
    }
    
    return 0;
}