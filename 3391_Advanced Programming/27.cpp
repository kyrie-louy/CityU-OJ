#include<iostream>
#include<string.h>
using namespace std;

bool vis[305];
int num,a,b,c,n;
int cal(int i){
    return (a*i*i+b*i+c)%n;
}

int gemNumber(){
    int max = -1;
    for(int i = 0; i<n;i++){
        int step = i;
        int count = 0;

        while(vis[step] != 1){
            count++;
            vis[step] = 1;
            step = cal(step);
        }
        if(count > max)
            max = count;
        
        memset(vis,0,sizeof(vis));
    }

    return max;
}

int main(){
    ios::sync_with_stdio(false);
    cin>>num;

    while(num--){
       cin>>a>>b>>c>>n;
       cout<<gemNumber()<<endl;
    }

    return 0;
}