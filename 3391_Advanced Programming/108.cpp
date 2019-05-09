#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int main(){
   // ios::sync_with_stdio(false);

    int n;
    
    string name, p_yg, p_od;
    int temp_birth, birth_yg, birth_od;
    int d,m,y;
    birth_od = 0x3f3f3f3f;
    birth_yg = 0xc0c0c0c0;

    for(int i = 0;i<n;i++){
        cin>>name>>d>>m>>y;

        temp_birth = y*10000+m*100+d;
        
        if(temp_birth>birth_yg){
            birth_yg = temp_birth;
            p_yg = name;
        }

        if(temp_birth < birth_od){
            birth_od = temp_birth;
            p_od = name;
        }
    }

        cout<<p_yg<<endl;
        cout<<p_od<<endl;
    return 0;
}