#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

struct vertex{
    double x,y;
}node[105];

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

double graham_scan(int n)
{
    double s1 = 0.0;
    for(int i=1;i<n-1;i++)
        s1 += 0.5*cross_product(node[0],node[i],node[i+1]);

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

    double s2 = 0;
    //printf("top: %d\n",ch.size());
    for(int i=1;i<ch.size()-1;i++){
        s2 += 0.5*cross_product(ch[0],ch[i],ch[i+1]);
    }
    //printf("s1: %lf, s2: %lf\n",s1,s2);
    double res = 100*(fabs(s2)-fabs(s1))/fabs(s2);
	return res;
}

//#define _DEBUG
int main(){
#ifdef _DEBUG
    freopen("/Users/kyrie/Desktop/input.txt","r",stdin);
#endif

    int idx=1;
    int n;  // the number of corner points of the tile

    while (~scanf("%d",&n))
    {
        if(n==0) break;
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&node[i].x,&node[i].y);
        }
        
        printf("Tile #%d\n",idx++);
        printf("Wasted Space = %.2lf %%\n\n",graham_scan(n));
    }
    
    return 0;
}