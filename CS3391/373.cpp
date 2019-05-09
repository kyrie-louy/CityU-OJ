#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

struct edge{int u,v; long long cost;};
bool comp(const edge& e1,const edge& e2){
    return e1.cost < e2.cost;
}
edge es[25005];
int A[1005];
bool used[25005];
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
    for(int i=0;i < n;i++){
        A[i] = -1;
    }    
}

int kruskal(){
    sort(es,es+m,comp);
    memset(used,0,sizeof(used));

    init_union_find();
    long long result = 0;
    int count = 0;

    for(int i=0;i<m;i++){
        edge e = es[i];

        if(!same(e.u,e.v)){
            Union(e.u,e.v);
            result += e.cost;
            used[i]=1;
            count++;
        }
    }
    //printf("count: %d\n",count);
    if(count!=n-1) return -1;
    return result;
}

//#define _DEBUG
int main(){
// #ifdef _DEBUG
// 	freopen("/Users/kyrie/Desktop/input.txt", "r", stdin);
// #endif
    while(scanf("%d%d",&n,&m)){
        if(n==0 && m==0) break;

        if(m < (n-1)){
            printf("\\(^o^)/ pray to god\n");
            int n1,n2,n3;
            for(int i=0;i<m;i++){
                scanf("%d%d%d",&n1,&n2,&n3);
            }
            continue;
        }
            
        
        for(int i=0; i<m; i++){
            int from, to;
            long long cost;
            scanf("%d%d%lld",&from,&to,&cost);
            es[i] = (edge){from,to,cost};
        }

        long long res = kruskal();
        if(res==-1)
            printf("\\(^o^)/ pray to god\n");
        else
        {
            printf("Min cost: %lld\n",res);
            bool isprint=0;
            for(int i=0;i<m;i++){
                if(!used[i]){
                    isprint=1;
                    if(i==m-1)
                        printf("%lld\n",es[i].cost);
                    else
                        printf("%lld ",es[i].cost);
                }
                    
            }
            if(!isprint) printf("\n");
        }
        
    }
    return 0;
}