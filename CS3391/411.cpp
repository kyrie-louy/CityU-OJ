#include<stdio.h>
#include<set>
#include<vector>
using namespace std;

//#define _DEBUG
int main(){
// #ifdef _DEBUG
// 	freopen("/Users/kyrie/Desktop/input.txt", "r", stdin);
// #endif

    int A;
    scanf("%d",&A);

    long long n, m, c;
    int idx = 1;
    while(A--){
        scanf("%lld%lld%lld",&n,&m,&c);
        vector<int> row;
        vector<int> seat;
        int r,s;
        int count = 0;

        for(int i=0;i<c;i++){
            scanf("%d",&r);
            row.push_back(r);
        }

        for(int i=0;i<c;i++){
            scanf("%d",&s);
            seat.push_back(s);
        }

        set<pair<int,int> > res;
        for(int i=0;i<c;i++){
            // (row[i],seat[i]) can't be the left seat
            // (row[i],seat[i]) can't be the right seat
            
            if(seat[i]>1)res.insert(make_pair(row[i],seat[i]));
            if(seat[i]<m)res.insert(make_pair(row[i],seat[i]+1));
        }
        printf("Case #%d: %lld\n",idx,n*(m-1)-(long long)res.size());
        idx++;
    }

    
    return 0;

}