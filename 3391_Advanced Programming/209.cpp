#include <stdio.h>
#include <iostream>
using namespace std;

struct Point{
    int x,y;
};
Point startP[105];
Point endP[105];

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
    int h = n;

    while (n--)
    {
        //cout<<"case "<<h-n<<endl;
        int m;
        scanf("%d",&m);
        int v1,v2,v3,v4;
        for(int i=0;i<m;i++){
            scanf("%d%d%d%d",&v1,&v2,&v3,&v4);
            startP[i] = (Point){v1,v2};
			endP[i] = (Point){v3,v4};
            //cout<<lineList[m].start.x<<" "<<lineList[m].start.y<<endl;
        }
        //cout<<"idx: "<<<<endl;
        int cnt=0;
        for(int i=0;i<m;i++){
            //cout<<"line "<<i<<": ";
            bool is_Intersect = 0;
            for(int j=0;j<m;j++){
                if(j!=i){
                    if(intersect(startP[i],endP[i],startP[j],endP[j])){
                        is_Intersect=1;
                        //cout<<i<<" "<<j<<endl;
                        break;
                    }
                }
            }
            if(!is_Intersect) cnt++;
        }
        printf("%d\n",cnt);
    }


    
    return 0;
}