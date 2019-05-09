#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
int a,b,c,d,T;
bool vis[30][30][30][30];
int vol[4];
struct node{
    int val[4];
    int step;
};

queue<node> q;
void full_Empty(node newNode, int pos, int targetVol){
    newNode.val[pos] = targetVol;
    newNode.step++;

    if(vis[newNode.val[0]][newNode.val[1]][newNode.val[2]][newNode.val[3]] == 0){
        vis[newNode.val[0]][newNode.val[1]][newNode.val[2]][newNode.val[3]] = 1;
        q.push(newNode);
    }
}

void pourOneToOther(node newNode, int posTo, int posFrom){
    if(newNode.val[posFrom]+newNode.val[posTo] <= vol[posTo]){
        newNode.val[posTo] = newNode.val[posFrom]+newNode.val[posTo];
        newNode.val[posFrom] = 0;
    }
    else
    {
        int diff = newNode.val[posFrom]+newNode.val[posTo]-vol[posTo];
        newNode.val[posFrom] = diff;
        newNode.val[posTo] = vol[posTo];
    }

    newNode.step++;
    if(vis[newNode.val[0]][newNode.val[1]][newNode.val[2]][newNode.val[3]] == 0){
        vis[newNode.val[0]][newNode.val[1]][newNode.val[2]][newNode.val[3]] = 1;
        q.push(newNode);
    }
    
}

int bfs(){
    node tmp = {{0,0,0,0},0};
    q.push(tmp);
    vis[0][0][0][0] = 1;

    while(!q.empty()){
        node cur = q.front();
        q.pop();

        if(cur.val[0] == T || cur.val[1] == T || cur.val[2] == T || cur.val[3] == T)
            return cur.step;

        // empty or fullfill one cup
        for(int i = 0; i< 4;i++){
            full_Empty(cur,i,0);
            full_Empty(cur,i,vol[i]);
        }

        // pour one to another
        for(int i = 0;i<4;i++){
            for(int j = 0;j<4;j++){
                if(i != j){
                    pourOneToOther(cur,i,j);
                    pourOneToOther(cur,j,i);
                }
            }
        }

    }
    return -1;
}

int main(){
    while(scanf("%d%d%d%d%d",&a,&b,&c,&d,&T)!=EOF){
        vol[0] = a;vol[1] = b;vol[2] = c;vol[3] = d;
        while(!q.empty()) q.pop();

        for(int i = 0;i<30;i++){
            for(int j = 0;j<30;j++){
                for(int n = 0;n<30;n++){
                    for(int m = 0;m<30;m++){
                        vis[i][j][n][m] = 0;
                    }
                }
            }
        }

        if(a<T && b<T && c<T && d<T)
            printf("%d\n",-1);
        else
        {
            printf("%d\n",bfs());
        }
        
    }
    return 0;
}
