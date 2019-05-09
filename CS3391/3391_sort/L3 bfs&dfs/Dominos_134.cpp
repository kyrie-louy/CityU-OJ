#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

struct node{
    vector<int> v;
};

int cot;
node dominos[10000];
bool vis[10000];

void bfs(int b){
    queue<int> q;
    q.push(b);
    vis[b-1] = 1;
    cot++;

    while(!q.empty()){
        int d_no = q.front();
        q.pop();
        
        node tmp = dominos[d_no-1];
        for(int i = 0;i<tmp.v.size();i++){
            if(vis[tmp.v[i]-1]==0){
                q.push(tmp.v[i]);
                vis[tmp.v[i]-1] = 1;
                cot++;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    int num, n, m, l;
    int s,e,b;
    cin>>num;

    while(num--){
        //init
        memset(vis,0,sizeof(vis));

        for(int i = 0;i<10000;i++){
            while(!dominos[i].v.empty()){
                dominos[i].v.pop_back();
            }
        }
        // input
        cin>>n>>m>>l;

        // fullfill
        for(int i = 0;i<m;i++){
            cin>>s>>e;
            dominos[s-1].v.push_back(e);
        }

        // push
        cot = 0;
        for(int i = 0;i<l;i++){
            cin>>b;

            if(vis[b-1] == 1)
                continue;
            bfs(b);
        }
        cout<<cot<<endl;
    }
}