#include <iostream>
#include <stdio.h>
#define MAXN 200
#define INF 10000000
using namespace std;
int f[MAXN][MAXN]={0},a,b,z; //f[x][y]=达到A桶内水量为x,B桶内水量为y的状态所需步骤数
void dfs(int x,int y,int step) //x=A桶内水量，y=B桶内水量，step=当前步骤数
{
    if(f[x][y]!=0&&step+1>=f[x][y]) return; //当前状态已经有解且现在的解一定比过去的解更差时，退出
    f[x][y]=step+1; //更新当前状态所需最少步骤数
    dfs(x,0,step+1); //1、清空B桶
    dfs(0,y,step+1); //2、清空A桶
    dfs(x,b,step+1); //3、装满B桶
    dfs(a,y,step+1); //4、装满A桶
    //5、将B桶倒入A桶
    if(x+y<=a)
        dfs(x+y,0,step+1);//(i)B桶倒空后A桶不会溢出
    else
        dfs(a,x+y-a,step+1); //(ii)B桶倒空后A桶会溢出,故B桶中有残留
    //6、将A桶倒入B桶
    if(x+y<=b)
        dfs(0,x+y,step+1);//(i)A桶倒空后B桶不会溢出
    else
        dfs(x+y-b,b,step+1); //(ii)A桶倒空后B桶会溢出,故A桶中有残留
}
int main()
{
    
    cin>>a>>b>>z;
    int minn=INF,i;
    dfs(0,0,0);
    for(i=0;i<=a;i++)
        if(f[i][z]!=0)
            if(f[i][z]<minn)
                minn=f[i][z]; //遍历所有B桶中达到水量z的情况，获得最优解
    for(i=0;i<=b;i++)
        if(f[z][i]!=0)
            if(f[z][i]<minn)
                minn=f[z][i];
    if(minn==INF)cout<<"impossible"<<endl;
    else cout<<minn-1<<endl;
    return 0;
}
