#include<stdio.h>
#include<bitset>
#include<string>
using namespace std;

int main(){
    long long a, b;
    while(scanf("%lld%lld",&a,&b)!=EOF){
        if(a==b){
            printf("%lld\n",b);
            continue;
        }

        string as = bitset<60>(a).to_string();
        string bs = bitset<60>(b).to_string();
        
        int diff=0;
        for(int i=0;i<60;i++){
            if(as[i]!=bs[i]){
                diff=i;
                break;
            }
        }
        
        //printf("%c\n",as[59]);
        //printf("%d\n",diff);
        for(int i=diff;i<60;i++){
            bs[i] = '1';
        }

        //printf("%s\n",bs.c_str());
        long long res = bitset<60>(bs).to_ullong();
        printf("%lld\n",res);
    }

    return 0;
}