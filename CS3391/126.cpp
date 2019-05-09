#include<iostream>
#include<string.h>
#include<queue>
using namespace std;

bool gameBoard[20][20];
bool vis[20];

struct node{
    int cNo;
    int deep;
};

void init(){
    for(int i = 0;i<20;i++){
        for(int j = 0;j<20;j++)
            gameBoard[i][j] = 0;
    }
}

void resetVis(){
    for(int i = 0; i < 20;i++)
        vis[i] = 0;
}

int bfs(int s, int e){
    queue<node> q;
    node a = {s,0};
    q.push(a);
    vis[s] = 1;

    while(!q.empty()){
        int cur = q.front().cNo;     
        int cDeep = q.front().deep;
        q.pop();

        for(int i = 0;i<20;i++){
            if(gameBoard[cur][i] == 1 && vis[i] == 0){
                vis[i] = 1;
                if(i == e)
                    return cDeep+1;
                
                node b = {i,cDeep+1};
                q.push(b);          
            }   
        }
    }

    return -1;
}
//#define _DEBUG
int main(){
// #ifdef _DEBUG
// 	freopen("/Users/kyrie/Desktop/input.txt", "r", stdin);
// #endif

    ios::sync_with_stdio(false);

    int idx = 1;
    int num, n, start, dest;

    while(cin>>num){
        // init
        init();
        int t;
        for(int j = 0;j < num;j++){
                cin>>t;
                gameBoard[0][t-1] = 1;
                gameBoard[t-1][0] = 1;
        }

        // fullfill
        for(int i = 1;i<19;i++){
            cin>>num;
            for(int j = 0;j < num;j++){
                cin>>t;
                gameBoard[i][t-1] = 1;
                gameBoard[t-1][i] = 1;
            }
        }

        // get input
        cin>>n;
        cout<<"Test Set #"<<idx<<endl;
        idx++;
        while(n--){
            cin>>start>>dest;
            resetVis();
            if(start<10)
                cout<<" "<<start<<" to ";
            else
                cout<<start<<" to ";
            
            if(dest < 10)
                cout<<" "<<dest<<": "<<bfs(start-1,dest-1)<<endl;
            else
                cout<<dest<<": "<<bfs(start-1,dest-1)<<endl;           
        }
        cout<<endl;
    }
    return 0;
}