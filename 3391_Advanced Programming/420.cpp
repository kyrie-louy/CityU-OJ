#include <stdio.h>
#include <cmath>
using namespace std;
#define precision 1.0e-4

struct point{
    double x, y;
};

double cross_product(point a, point b){
    return a.x*b.y-a.y*b.x;
}

double dot_product(point a, point b){
    return a.x*b.x+a.y*b.y;
}

//#define _DEBUG
int main(){
#ifdef _DEBUG
	freopen("/Users/kyrie/Desktop/input.txt", "r", stdin);
#endif
    double d;
    double px, py, vx, vy;
    while (~scanf("%lf",&d))
    {
        if(d==0) break;
        scanf("%lf%lf%lf%lf",&px,&py,&vx,&vy);
        //printf("%lf%lf%lf%lf\n",px,py,vx,vy);
        point p = (point){px,py};
        point v = (point){vx,vy};

        if(abs(cross_product(p,v)) <= precision){
            //printf("%lf%lf%lf%lf\n",px,py,vx,vy);
            double distp = sqrt(p.x*p.x+p.y*p.y);
            double distv = sqrt(v.x*v.x+v.y*v.y);

            double multi = dot_product(p,v);
            double dis = d+5.0;
            if(multi>0)
                dis = 2.0 - distp;
            else if(multi < 0)
            {
                dis = distp;
            }

            if(abs(dis-d)<precision || dis<d)
                printf("possible\n");
            else
            {
                printf("impossible\n");
            } 
        }
        else printf("impossible\n");
    }
    
    return 0;
}