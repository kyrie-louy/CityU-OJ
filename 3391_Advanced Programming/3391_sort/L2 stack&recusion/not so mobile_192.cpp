#include<stdio.h>
using namespace std;
int flag;

int rec(){
    int wl,dl,wr,dr;
    scanf("%d%d%d%d",&wl,&dl,&wr,&dr);
    if(wl == 0) wl = rec();
    if(wr == 0) wr = rec();
    //printf("l: %d, r: %d\n",wl*dl,wr*dr);
    if(wl*dl != wr*dr) flag = 0;
    
    return wl+wr;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = n;i>0;i--){
        flag = 1;
        rec();
        if(flag == 0)
            printf("NO\n");
        else
            printf("YES\n");
        
        if(i != 1)
            printf("\n");
    }
    return 0;
}