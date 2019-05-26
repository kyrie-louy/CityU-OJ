#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

char grid[105][105];
bool vis[105][105];
struct node{
    int r, c, s;
};

int n;
int kr,kc,wr,wc,er,ec;
int cost1, cost2;

int bfs(int sr,int sc, int endr, int endc){
    queue<node> q;
    node a = {sr,sc,0};
    q.push(a);
    vis[sr][sc] = 1;

    while(!q.empty()){
        node cur = q.front();
        q.pop();
        int cur_r = cur.r;
        int cur_c = cur.c;
        int cur_s = cur.s;

        if(cur.r == endr && cur.c == endc){
            return cur.s;
        }

        for(int i=0;i<4;i++){
            if(i==0){   // go up
                if(cur_r == 0 || grid[cur_r-1][cur_c]=='#')
                    continue;
                if(vis[cur_r-1][cur_c]==0){
                    node tmp = {cur_r-1,cur_c,cur_s+1};
                    q.push(tmp);
                    vis[cur_r-1][cur_c]=1;
                }
            }
            else if(i==1)   //go down
            {
                if(cur_r==n-1 || grid[cur_r+1][cur_c]=='#')
                    continue;
                if(vis[cur_r+1][cur_c]==0){
                    node tmp = {cur_r+1,cur_c,cur_s+1};
                    q.push(tmp); 
                    vis[cur_r+1][cur_c]=1; 
                }

            }
            else if(i==2)   //go left
            {
                if(cur_c==0 || grid[cur_r][cur_c-1]=='#')
                    continue;
                
                if(vis[cur_r][cur_c-1]==0){
                    node tmp = {cur_r,cur_c-1,cur_s+1};
                    q.push(tmp);
                    vis[cur_r][cur_c-1]=1;
                }
            }
            else if(i==3)   //go right
            {
                if(cur_c==n-1 || grid[cur_r][cur_c+1]=='#')
                    continue;

                if(vis[cur_r][cur_c+1]==0){
                    node tmp = {cur_r,cur_c+1,cur_s+1};
                    q.push(tmp);
                    vis[cur_r][cur_c+1]=1;
                }
            }
            
        }
    }
    return -1;
}

//#define _DEBUG
int main(){
    // #ifdef _DEBUG
 	//   freopen("/Users/kyrie/Desktop/input.txt", "r", stdin);
    // #endif
    int T;
    scanf("%d",&T);

    while(T--){
        kr=-1;kc=-1;wr=-1;wc=-1;er=-1;ec=-1;
        scanf("%d",&n);
        getchar();
        getchar();
        char s[105];
        for(int i=0;i<n;i++){
            gets(s);
            for(int j=0;j<n;j++){
                grid[i][j] = s[j];
                if(s[j] == 'K'){
                    kr =i; kc = j;
                }
                if(s[j] == 'W'){
                    wr =i; wc= j;
                }
                if(i==0 || i==n-1 || j==0||j==n-1){
                    if(grid[i][j]=='.'){
                        er =i; ec=j;
                    }
                }
            }
        }

        memset(vis,0,sizeof(vis));
        cost1 = bfs(kr,kc,wr,wc);
        memset(vis,0,sizeof(vis));
        cost2 = bfs(wr,wc,er,ec);
        printf("%d\n",cost1+cost2);
    }
    return 0;
    
}