#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct vertex{
    int x,y;
}u,node[520];

//计算叉积，小于0说明p1在p2的逆时针方向(右边)，即p0p1的极角大于p0p2的极角
double cross_product(const vertex &p0, const vertex &p1, const vertex &p2)
{
	return (p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y - p0.y);
}

//计算距离
double dis(const vertex &p1, const vertex &p2)
{
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

bool com(const vertex &p1, const vertex &p2)
{
	double temp = cross_product(node[0], p1, p2);
	if (fabs(temp) < 1e-6)//极角相等按照距离从小到大排序
    {
        return dis(node[0], p1) < dis(node[0], p2);
    }
	else
    {
        return temp > 0;
    }
}
bool com2(const vertex& v1, const vertex& v2){
    return v1.idx < v2.idx;
}
vector<vertex> graham_scan(int n)
{
	vector<vertex> ch;
	int top = 2;
	int index = 0;
	for (int i = 1; i < n; ++i)//选出Y坐标最小的点，若Y坐标相等，选择X坐标小的点
	{
		if (node[i].y < node[index].y || (node[i].y == node[index].y && node[i].x < node[index].x))
		{
			index = i;
		}
	}
	swap(node[0], node[index]);
	ch.push_back(node[0]);

	//按极角排序
	sort(node + 1, node + n, com);
	ch.push_back(node[1]);
	ch.push_back(node[2]);
	for (int i = 3; i < n; ++i)
	{
		while (top > 0 && cross_product(ch[top - 1], node[i], ch[top]) >= 0)
		{
			--top;
			ch.pop_back();
		}
		ch.push_back(node[i]);
		++top;
	}
	return ch;
}

//#define _DEBUG
int main(){
#ifdef _DEBUG
    freopen("/Users/kyrie/Desktop/input.txt","r",stdin);
#endif
    int k;
    scanf("%d",&k);
    printf("%d\n",k);
    while (k--)
    {
        int n;
        int cnt=0;
        int tmp, x,y;
        scanf("%d",&n);

        for(int i=0;i<n;i++){
            scanf("%d%d",&node[i].x,&node[i].y);
            node[i].idx=i;
        }
        vector<vertex> res = graham_scan(n-1);
        //sort(res.begin(),res.end(),com2);
        printf("%lu\n",res.size()+1);
        for(int i=0;i<res.size();i++){
            printf("%d %d\n",res[i].x,res[i].y);
        }
        printf("%d %d\n",res[0].x,res[0].y);

        scanf("%d",&tmp);
        if(k)printf("-1\n");
    }
    return 0;
}