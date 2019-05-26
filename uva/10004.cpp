#include <stdio.h>
#include <queue>
#include <string.h>
#include <vector>
using namespace std;
#define MAX_V 205

/*
一开始理解成环图才是not bicolorable
后来发现这是不对的
只要环图中相同层次不连接也是可以的
只要用bfs
比较邻居有没有和自己color相同的就好了
当然dfs也可以做，具体参考：https://blog.csdn.net/shuangde800/article/details/7727197
*/

int n, l;
bool flag = true;
vector<int> G[MAX_V];
int color[MAX_V];

void bfs(){
    queue<int> q;
    q.push(0);
    color[0] = 1;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(int i=0;i<G[cur].size();i++){
            if(color[G[cur][i]]==0){
                q.push(G[cur][i]);
                color[G[cur][i]] = 1+color[cur];
            }
            else if(color[G[cur][i]] == color[cur]){
                flag = false;
                return;
            }
        }
    }
    
}

//#define _DEBUG
int main(){
#ifdef _DEBUG
    freopen("/Users/kyrie/Desktop/input.txt","r",stdin);
#endif

    while(~scanf("%d",&n)){
        if(n==0)break;

        scanf("%d",&l);
        int s, e;
        for(int i = 0;i <l;i++){
            scanf("%d%d",&s,&e);
            G[s].push_back(e);
            G[e].push_back(s);
        }
        
        flag = true;
        bfs();
        if(flag) printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");
        for(int i=0;i<n;i++){
            G[i].clear();
            color[i]=0;
        }
    }
    return 0;
}