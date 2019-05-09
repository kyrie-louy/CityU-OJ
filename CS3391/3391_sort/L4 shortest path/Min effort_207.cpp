#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 0x3f3f3f

char build[200][20];
int graph[200][200];

//#define _DEBUG
int main(){
    // #ifdef _DEBUG
 	//   freopen("/Users/kyrie/Desktop/input.txt", "r", stdin);
    // #endif
    int N;
    while(scanf("%d",&N)!=EOF){
        memset(graph,MAX,sizeof(graph));

        getchar();
        for(int i = 0; i<N;i++){
            gets(build[i]);
        }

        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            char c1;
            char place1[20];
            int p1;
            int p2;
            char place2[20];
            int d1 = -1;
            int d2 = -1;
            int idx = 0;
            if(i==0) getchar();
            //place1
            while((c1=getchar()) && c1!=':'){
                place1[idx++] = c1;
            }
            place1[idx] = '\0';
            for(int j=0;j<N;j++){
                if(strcmp(place1,build[j])==0){
                    p1 = j;
                } 
            }

            //place2
            idx=0;
            bool ifexit = 0;
            while((c1 = getchar())){
                if(c1 == ' '){
                    place2[idx] = '\0';
                    for(int j=0;j<N;j++){
                        if(strcmp(place2,build[j])==0){
                            ifexit =1;
                            p2 = j;
                            break;
                        }
                    }
                    if(ifexit)break;
                }
                place2[idx++] = c1;
            }

            //d1,d2
            scanf("%d",&d1);
            c1 = getchar();
            if(c1!='\n'){
                scanf("%d",&d2);
                getchar();
            }
            if(d2==-1){
                graph[p1][p2] = d1;
            }
            else{
                graph[p1][p2] = d1;
                graph[p2][p1] = d2;
            }
            //printf("place1:%s place2:%s d1:%d d2:%d p1:%d p2:%d\n",place1,place2,d1,d2,p1,p2);
        }


        // from office to hall
        int cost1,cost2;
        int prev1[200];
        int prev2[200];
        int d[200];
        bool used[200];
        int oidx,hidx;
        memset(d,MAX,sizeof(d));
        memset(used,0,sizeof(used));
        fill(prev1,prev1+N,-1);
        fill(prev2,prev2+N,-1);
        for(int i=0;i<N;i++){
            if(strcmp(build[i],"office")==0)oidx=i;
            if(strcmp(build[i],"hall")==0)hidx = i;
        }

        d[oidx] = 0;
        while(true){
            int v =-1;
            for(int u=0;u<N;u++){
                if(!used[u] && (v ==-1||d[u]<d[v]))v=u;
            }
            if(v==-1)break;
            used[v] = 1;
            for(int u=0;u<N;u++){
                if(d[u]>d[v] + graph[v][u]){
                    d[u] = d[v] + graph[v][u];
                    prev1[u] = v;
                }
            }
        }
        cost1 = d[hidx];

        //from hall to office
        memset(d,MAX,sizeof(d));
        memset(used,0,sizeof(used));
        d[hidx] = 0;
        while(true){
            int v =-1;
            for(int u=0;u<N;u++){
                if(!used[u] && (v ==-1||d[u]<d[v]))v=u;
            }
            if(v==-1)break;
            used[v] = 1;
            for(int u=0;u<N;u++){
                if(d[u]>d[v] + graph[v][u]){
                    d[u] = d[v] + graph[v][u];
                    prev2[u] = v;
                }
            }
        }
        cost2 = d[oidx];
        printf("%d\n",cost1+cost2);

        // output the road
        vector<int> path1;
        for(int t = hidx;t!=-1;t=prev1[t])path1.push_back(t);
        reverse(path1.begin(),path1.end());
        for(int i=0;i<path1.size();i++){
            printf("%s -> ",build[path1[i]]);
        }

        vector<int> path2;
        for(int t = oidx;t!=-1;t=prev2[t])path2.push_back(t);
        reverse(path2.begin(),path2.end());
        for(int i=1;i<path2.size();i++){
            if(i==(path2.size()-1))
                printf("%s\n",build[path2[i]]);
            else
                printf("%s -> ",build[path2[i]]);
        }
        // for(int i=0;i<N;i++){
        //     for(int j=0;j<N;j++){
        //         printf("%d ",graph[i][j]);
        //     }
        //     printf("\n");
        // }
        printf("\n");
    }
    
    return 0;
}