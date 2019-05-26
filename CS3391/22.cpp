#include<stdio.h>
#include<queue>
#include<cstring>
using namespace std;
int prime_base[25];
int cr_bit[4];
int res = -1;
bool vis[10000];

struct node
{
    int data, step;
};

bool isPrime(int value){
    bool isPrime = true;
    for(int j = 0;j < 25; j++){
        if(value % prime_base[j] == 0){
            isPrime = false;
            break;
        }
    }
    return isPrime;
}

void solve(int bottom, int up){
    queue<node> q;
    node st = {bottom,0};
    res=-1;
    memset(vis,0,sizeof(vis));
    q.push(st);
    vis[bottom]=1;
    while(!q.empty()){
        node cr = q.front();
        q.pop();

        if(cr.data == up){
            res = cr.step;
            return;
        }

        // divide int into array
        int temp_data = cr.data;
        for(int i = 1;i<=4;i++){
            cr_bit[4-i] = temp_data%10;
            temp_data /= 10;
        }

        for(int i = 0;i<4;i++){
            for(int j = 0; j<=9;j++){
                int value;
                if(i==0)
                    if(j==0)continue;else
                    value = 1000*j+100*cr_bit[1]+10*cr_bit[2]+cr_bit[3];
                else if(i==1)
                    value = 1000*cr_bit[0]+100*j+10*cr_bit[2]+cr_bit[3];
                else if(i==2)
                    value = 1000*cr_bit[0]+100*cr_bit[1]+10*j+cr_bit[3];
                else if(i==3)
                    value = 1000*cr_bit[0]+100*cr_bit[1]+10*cr_bit[2]+j;
                if(!vis[value]&&isPrime(value)){
                    vis[value]=1;
                    node newnode = {value, cr.step+1};
                    q.push(newnode);
                }
            }
        }
    }
}

int main( )
{
    // calculate all prime numbers
    prime_base[0] = 2;
    prime_base[1] = 3;
    prime_base[2] = 5;
    prime_base[3] = 7;
    int index = 4;
    for(int i = 8;i<=100;i++){
        bool isPrime = true;
        for(int j = 0;j<=3;j++){
            if(i%prime_base[j]==0){
                isPrime = false;
                break;
            }
        }

        if(isPrime)
            prime_base[index++] = i;
    }


    int n;
    scanf("%d",&n);

    while(n--){
        int bottom, up;
        scanf("%d%d",&bottom,&up);
        solve(bottom,up);

        if(res == -1)
            printf("Impossible\n");
        else
            printf("%d\n", res);
    }
    return 0;
}
