#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

#define MinN -2147483648
int n,m;
struct edge{int u,v,cost;};
bool comp(const edge& e1,const edge& e2){
    return e1.cost < e2.cost;
}
edge es[1000005];
int A[505];
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
    memset(A,-1,sizeof(A));   
}


//#define _DEBUG
int main(){
// #ifdef _DEBUG
// 	freopen("/Users/kyrie/Desktop/input.txt", "r", stdin);
// #endif

    while(scanf("%d%d",&n,&m)){
        if(n==0&&m==0) break;

        int maxN = MinN;
        int count=0;
        for(int i=0;i<m;i++){
            int from,to,cost;
            scanf("%d%d%d",&from,&to,&cost);
            es[i] = (edge){from,to,cost};
            if(cost>maxN)maxN = cost;
        }

        init_union_find();
        for(int i=0;i<m;i++){
            edge e = es[i];

            if(!same(e.u,e.v)&&(e.cost==maxN)){
                Union(e.u,e.v);
            }
        }

        for(int i=1;i<=n;i++){
            if(count < -A[i])
                count = -A[i];
            //printf("%d %d\n",A[i],count);
        }
        printf("%d\n",count);

    }
    return 0;
}