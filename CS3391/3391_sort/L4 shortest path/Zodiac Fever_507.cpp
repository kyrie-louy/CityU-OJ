#include<stdio.h>
#include<vector>
#include<queue>
#include<map>
#include<string.h>
#include<iostream>
using namespace std;

struct room
{
    int i, cost;
    bool operator < (const room &r)const{
		if (i != r.i) return i<r.i;
		return cost<r.cost;
	}
};

struct trap
{
    char type;
    int move;
};

struct step
{
    int i, cost, pos;
    bool operator < (const step &other) const{
        return cost > other.cost;
    }
};

#define _DEBUG
int main(){
    #ifdef _DEBUG
 	 freopen("/Users/kyrie/Desktop/input.txt", "r", stdin);
    #endif
    int n_rooms, n_corridors, n_traps;
    int entrance, treasure,open_pos,init_pos;

    while(scanf("%d%d%d%d%d%d%d",&n_rooms,&n_corridors,&n_traps,&entrance,&init_pos,&treasure,&open_pos)!=EOF){
        vector<vector<room> > rooms(1005);
        vector<vector<trap> > traps(1005);
        bool isSol = 0;
        // cin edge
        int from,to,d;
        for(int i = 1;i<=n_corridors;i++){
            scanf("%d%d%d",&from,&to,&d);
            rooms[from].push_back((room){to,d});
            rooms[to].push_back((room){from,d});
        }

        // cin traps
        int c,m;
        char typ;
        for(int i = 1;i<=n_traps;i++){
            cin>>c>>typ>>m;
            traps[c].push_back((trap){typ,m});
        }

        priority_queue<step> q;
        map<room, int> vis;
        q.push((step){entrance, 0, init_pos});

        while(!q.empty()){
            step s = q.top();
            q.pop();

            int ci = s.i;
            int cp = s.pos;

            if(ci == treasure && cp == open_pos){
                printf("%d\n", s.cost);
                isSol = 1;
                break;
            }

            for(int i = 0; i<rooms[ci].size();i++){
                room r = rooms[ci][i];
                int ri = r.i;
                int rc = r.cost;
                int posi = cp;

                if(traps[ri].size() != 0){
                    trap t = traps[ri][0];
                    char c = t.type;

                    if(c == '+'){
                        posi = (posi+t.move)%12;
                    }
                    else if(c == '-'){
                        posi = (posi-t.move)%12;
                    }
                    else if(c == '*'){
                        posi = (posi*t.move)%12;
                    }
                    else if(c == '='){
                        posi = t.move%12;
                    }

                    if(posi <= 0)
                        posi += 12;
                }

                room n = (room){ri, posi};
                if(vis.find(n) == vis.end()){
                    q.push((step){ri, s.cost+rc, posi});
                    vis[n] = s.cost+rc;
                }
                else if(s.cost+rc < vis[n]){
                    q.push((step){ri, s.cost+rc, posi});
                    vis[r] = s.cost+rc;
                }
            }
        }
        if(!isSol)
            printf("Pray!\n");
        
    }
    return 0;
}