#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;

/*
经典的分而治之题目
题目：寻找最近点对（数据量很大）
分析：分治法。首先，将所有点按很坐标排序；然后，利用分治求解。
    1.将问题转化为两个相同大小的子区间分别求解；
    2.中位点为中心，当前最小距离为半径的区间直接枚举求解；
    3.求出上两中情况的最小值返回。
*/

struct point
{
    double x, y;
};

point plist[100005];

bool cmp(const point &a, const point &b){
    return a.x < b.x;
}

double calDist(point a, point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double findMin(int b, int u){
    if(b>u) return 10010;
    int l=(b+u)/2, r=(b+u)/2, mid=(b+u)/2;
    double d = min(findMin(b,mid-1),findMin(mid+1,u));
    while (l>b && d>plist[mid].x-plist[l].x)
    {
        l--;
    }
    while (r<u && d>plist[r].x-plist[mid].x)
    {
        r++;
    }

    for(int i=l+1;i<r-1;i++){
        for(int j=i+1;j<r;j++){
            d = min(d,calDist(plist[i],plist[j]));
        }
    }
    return d;
}

//#define _DEBUG
int main(){
#ifdef _DEBUG
    freopen("/Users/kyrie/Desktop/input.txt","r",stdin);
#endif

    int n;

    while (~scanf("%d",&n))
    {
        if(n==0) break;

        for(int i=0;i<n;i++){
            scanf("%lf%lf",&plist[i].x,&plist[i].y);
        }

        sort(plist,plist+n,cmp);
        double res = findMin(0,n-1);
        //printf("%.4lf\n",res);
        
        if(res>=10000) printf("INFINITY\n");
        else printf("%.4lf\n",res);
    }
    
    return 0;
}