#include <stdio.h>
#include <algorithm>
using namespace std;

struct edge{int u,v,cost;};

bool comp(const edge& e1, const edge& e2){
    return e1.cost > e2.cost;
}

edge es[10005];
int A[105];
int n,m;

int find(int e){
    if(A[e]<0) return e;
    else return A[e] =find(A[e]);
}

void UnionSet(int s1,int s2){
    A[s1] += A[s2];
    A[s2] = s1;
}

void Union(int e1,int e2){
    int r1 = find(e1);
    int r2 = find(e2);
    if(A[r1]<A[r2]) UnionSet(r1,r2);
    else UnionSet(r2,r1);
}

bool same(int a,int b){
    return find(a)==find(b);
}

void init_union_find(){
    for(int i=0;i<105;i++)
        A[i] = -1;
}
int kruskal(){
    sort(es,es+m,comp);
    init_union_find();
    int recent = 0;

    for(int i=0;i<m;i++){
        edge e = es[i];
        if(!same(e.u,e.v)){
            Union(e.u,e.v);
            recent= e.cost;
        }
    }
    return recent;
}

#define _DEBUG
int main(){
#ifdef _DEBUG
	freopen("/Users/kyrie/Desktop/input.txt", "r", stdin);
#endif

    int r, idx=1;
    scanf("%d",&r);

    while(r--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            int from, to, weight;
            scanf("%d%d%d",&from,&to,&weight);
            es[i] = (edge){from,to,weight};
        }
        printf("Case #%d: %d\n",idx,kruskal());
        idx++;
    }
    
    return 0;
}            