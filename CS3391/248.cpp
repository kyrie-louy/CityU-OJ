#include <stdio.h>
#include <algorithm>
using namespace std;

struct Point
{
    double x,y;
};

Point ls;
Point le;
Point lt,rb;

bool isYBetween(double n){
    if(n<=lt.y&&n>=rb.y) return 1;
    return 0;
}
bool isXBetween(double n){
    if(n>=lt.x&&n<=rb.x) return 1;
    return 0;
}
bool in(){
    if(isXBetween(ls.x)&&isYBetween(ls.y)) return 1;
    if(isXBetween(le.x)&&isYBetween(le.y)) return 1;
    return 0;
}

double mult(Point a, Point b, Point c)
{
	return (a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y);
}

//aa, bb为一条线段两端点 cc, dd为另一条线段的两端点 相交返回true, 不相交返回false
bool intersect(Point aa, Point bb, Point cc, Point dd)
{
	if ( max(aa.x, bb.x)<min(cc.x, dd.x) )
	{
		return false;
	}
	if ( max(aa.y, bb.y)<min(cc.y, dd.y) )
	{
		return false;
	}
	if ( max(cc.x, dd.x)<min(aa.x, bb.x) )
	{
		return false;
	}
	if ( max(cc.y, dd.y)<min(aa.y, bb.y) )
	{
		return false;
	}
	if ( mult(cc, bb, aa)*mult(bb, dd, aa)<0 )
	{
		return false;
	}
	if ( mult(aa, dd, cc)*mult(dd, bb, cc)<0 )
	{
		return false;
	}
	return true;
}

//#define _DEBUG
int main(){
#ifdef _DEBUG
    freopen("/Users/kyrie/Desktop/input.txt","r",stdin);
#endif
    int n;
    scanf("%d",&n);
    while (n--)
    {
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&ls.x,&ls.y,&le.x,&le.y,&lt.x,&lt.y,&rb.x,&rb.y);
        
        if(lt.x>rb.x) swap(lt.x,rb.x);
        if(lt.y<rb.y) swap(lt.y,rb.y);

        if(in()){
            printf("T\n");
        }
        else
        {
            Point lb = (Point){lt.x,rb.y};
            Point rt = (Point){rb.x,lt.y};
            if(intersect(ls,le,lt,lb) ||intersect(ls,le,lt,rt) || intersect(ls,le,rt,rb) || intersect(ls,le,lb,rb)){
                printf("T\n");
            }
            else
                printf("F\n");
        }
        
    }
    
    return 0;
}