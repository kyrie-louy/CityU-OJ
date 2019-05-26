#include<stdio.h>
#include<algorithm>
using namespace std;

#define MAX_E 5000
#define INF 0x3f3f3f3f
struct edge
{
    int u,v,cost;
};

bool comp(const edge & e1, const edge& e2){
    return e1.cost<e2.cost;
}

int n,m;    //n: number of vertices, m: number of edges
edge es[MAX_E];
int A[105];

int find(int e){
    if(A[e]<0)
        return e;
    else
        return A[e] =find(A[e]);
}

void UnionSet(int s1,int s2){
    A[s1] += A[s2];
    A[s2] = s1;
}

void Union(int e1,int e2){
    int r1 = find(e1);
    int r2 = find(e2);
    if(A[r1]<A[r2])
        UnionSet(r1,r2);
    else
        UnionSet(r2,r1);
}

bool same(int a,int b){
    return find(a)==find(b);
}

int kruskal(){
    int res = -1;
    sort(es,es+m,comp);

    for(int i=0;i<m;i++){
        int num = 0;
        for(int i=1;i<=n;i++){
            A[i]=-1;
        }

        for(int j=i;j<m;j++){
            edge e = es[j];

            if(!same(e.u,e.v)){
                num++;
                Union(e.u,e.v);

                if(num==n-1){
                    if(res==-1)
                        res = es[j].cost-es[i].cost;
                    else
                        res = min(es[j].cost-es[i].cost,res);
                }
            }
        }
    }
    return res;
}

//#define _DEBUG
int main(){
// #ifdef _DEBUG
// 	freopen("/Users/kyrie/Desktop/input.txt", "r", stdin);
// #endif

    while(scanf("%d%d",&n,&m) && (n||m)){
        int a,b,w;

        for(int i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&w);
            es[i] = (edge){a,b,w};
        }
        printf("%d\n",kruskal());
    }
    
    return 0;
}