#include<stdio.h>
#include<algorithm>
using namespace std;

struct edge{int u,v,cost;};
bool comp(const edge& e1,const edge& e2){
    return e1.cost < e2.cost;
}

edge es[125255];
int keys[505];
int A[505];
int T,N;
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
    for(int i=0;i < N;i++){
        A[i] = -1;
    }    
}

int getDiff(int a, int b){
    int num;
    if(a>=b) num = a-b;
    else num = b-a;

    if(num > 5) return 10-num;
    else return num;
}

int calRoll(int m, int n){

    return getDiff(m/1000%10,n/1000%10)+getDiff(m/100%10,n/100%10)+getDiff(m/10%10,n/10%10)+getDiff(m%10,n%10);
}

int kruskal(int edgeNum){
    sort(es,es+edgeNum,comp);

    init_union_find();
    int res = 0;

    //printf("he8hie\n");
    for(int i=0;i<edgeNum;i++){
        edge e = es[i];
        //printf("%d\n",e.cost);
        if(!same(e.u,e.v)){
            Union(e.u,e.v);
            res += e.cost;
        }
    }
    return res;
}

//#define _DEBUG
int main(){
// #ifdef _DEBUG
// 	freopen("/Users/kyrie/Desktop/input.txt", "r", stdin);
// #endif

    scanf("%d",&T);

    while(T--){
        scanf("%d",&N);

        for(int i=0;i<N;i++){
            int num;
            scanf("%d",&num);
            //printf("%d\n",num);
            keys[i]= num;
        }
        int index = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<i;j++){
                //printf("res :%d\n",calRoll(keys[i],keys[j]));
                es[index] = (edge){i,j,calRoll(keys[i],keys[j])};
                index++;
            }
        }
        //printf("hh%d %d %d\n",keys[1],keys[2],calRoll(keys[1],keys[2]));
        int maxStep = 9999;
        for(int i=0;i<N;i++){
            //printf("i: %d %d %d\n",i,maxStep,calRoll(0,keys[i]));
            if(maxStep > calRoll(0,keys[i])){
                maxStep = calRoll(0,keys[i]);
            }
        }
        //printf("maxstep: %d, %d\n",maxStep, kruskal(index));
        printf("%d\n",maxStep+kruskal(index));

    }
    
    return 0;
}