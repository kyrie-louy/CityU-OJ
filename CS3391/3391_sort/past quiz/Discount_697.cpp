#include<stdio.h>
#include<algorithm>
using namespace std;

struct item
{
    int p, dp, d;
    bool operator < (const struct item &a) const{
    return d > a.d;
}
}ilist[105];

//#define _DEBUG
int main(){
    // #ifdef _DEBUG
 	//   freopen("/Users/kyrie/Desktop/input.txt", "r", stdin);
    // #endif
    int n;
    while(scanf("%d",&n)!=EOF){
        int totalp = 0;
        for(int i=0;i<n;i++){
            int price, dprice, discount;
            scanf("%d%d",&price,&dprice);
            discount = price- dprice;
            totalp += price;
            ilist[i] = (item){price,dprice,discount};
        }
        if(totalp < 100){
            printf("%d\n",totalp);
        }
        else
        {
            sort(ilist,ilist+n);

            int totalSum = 0;
            for(int i=0;i<n;i++){
                if(i<n/2){
                    totalSum += ilist[i].dp;
                }
                else
                {
                    totalSum += ilist[i].p;
                }
            }

            printf("%d\n",totalSum);
        }

    }
    return 0;
}