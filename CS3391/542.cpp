#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

//#define _DEBUG
int main(){
#ifdef _DEBUG
    freopen("/Users/kyrie/Desktop/input.txt","r",stdin);
#endif

    int lights[105];
    int n;
    while (1)
    {
        n = 0;
        int currentt[105];

        while(1){
            scanf("%d",&lights[n]);
            //cout<<lights[n]<<" ";
            if(lights[n]==0) break;
            n++;
        }
        for(int i=0;i<n;i++){
            currentt[i]=0;
        }
        //cout<<endl;
        if(lights[0]==0)break;

        // find the smallest interval
        int mint = 91;
        for(int i=0;i<n;i++){
            if(lights[i]<mint) mint=lights[i];
        }

        // for(int i=0;i<n;i++){
        //     cout<<currentt[i]<<" ";
        // }
        // cout<<endl;
        //cout<<"min: "<<mint<<endl;
        int totalt = mint;
        for(;totalt<=(5*60*60);totalt++){
            bool isGreen = 1;
            for(int i=0;i<n;i++){
                while (lights[i]+currentt[i]-5<=totalt)
                {
                    //cout<<lights[i]<<" ";
                    currentt[i] += 2*lights[i];
                }
                //cout<<endl;
                //cout<<currentt[i]<<endl;
                if(!(currentt[i]<=totalt && currentt[i]+lights[i]-5>totalt)){
                    isGreen = 0;
                    totalt = currentt[i]-1;
                    break;
                }            
            }
            if(isGreen) break;
        }

        // for(int i=0;i<n;i++){
        //     cout<<currentt[i]<<" ";
        // }
        // cout<<endl;

        if(totalt > 18000) printf("Signals fail to synchronise in 5 hours\n");
        else{
            int h, m, s;
            h = totalt/3600;
            m = (totalt-h*3600)/60;
            s = totalt - 3600*h - 60*m;
            cout<<setfill('0')<<setw(2)<<h<<":";
            cout<<setfill('0')<<setw(2)<<m<<":";
            cout<<setfill('0')<<setw(2)<<s<<endl;
        }
    }
    
    return 0;
}