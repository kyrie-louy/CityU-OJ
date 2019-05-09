#include<stdio.h>
#include<string>
#include<iostream>
#include<sstream>
using namespace std;

#define MAX 0x3f3f3f3f

int dist[1005][1005];
int next_c[1005][1005];
int cost[1005];
bool isfirst = 1;

void output(int s, int e){
    printf("From %d to %d :\n",s,e);
    printf("Path: %d",s);
    int c1 =s, c2 = e;
    while(c1 != c2){
        printf("-->%d",next_c[c1][c2]);
        c1 = next_c[c1][c2];
    }
    printf("\n");
    printf("Total cost : %d\n",dist[s][e]);
}

void solve(){
    int len, tmp, idx = 1;
    string line;
    stringstream ss;
    
    // read first line and record len
    getline(cin,line);
    ss.clear();
	ss.str(line);
	while(1){
		ss>>tmp;
		if(ss.fail()) break;
		if(tmp == -1)
			dist[1][idx++] = MAX;
		else
		{
			dist[1][idx++] = tmp;
		}		
	}
	len = idx-1;	


    for(int i = 2; i <= len; i++){
        getline(cin,line);
        idx = 1;
        ss.clear();
        ss.str(line);
        while(1){
            ss>>tmp;
            if(ss.fail()) break;
            if(tmp == -1)
                dist[i][idx++] = MAX;
            else
                dist[i][idx++] = tmp;	
	    }
    }

    // read b
    getline(cin,line);
    idx = 1;
    ss.clear();
    ss.str(line);
    while(1){
        ss>>tmp;
        if(ss.fail()) break;
        cost[idx++] = tmp;	
    }
    //only for test
    // for(int i = 1;i<=len;i++){
    //     for(int j = 1;j<=len;j++){
    //         cout<<dist[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    // for(int i = 1;i <= len;i++)
    //     cout<<cost[i]<<" ";   
    // cout<<endl;

    for (int i = 1 ;i <= len; i++) {
        for (int j = 1; j <= len; j++) {
            next_c[i][j] = j;
        }
	}

    // floyd
    for(int k = 1;k<=len;k++){
        for(int i = 1; i<= len;i++){
            for(int j = 1; j<=len;j++){
                if(dist[i][j] > dist[i][k]+dist[k][j]+cost[k]){
                    dist[i][j] = dist[i][k]+dist[k][j]+cost[k];
                    next_c[i][j] = next_c[i][k];
                }
            }
        }
    }

    // only for test
    // cout<<endl;
    // for(int i = 1;i<=len;i++){
    //     for(int j = 1; j <= len;j++)
    //         cout<<next_c[i][j]<<" ";
    //     cout<<endl;
    // }
    

    //read city
    int c1, c2;
    while(getline(cin,line) && line!=""){
        if(isfirst==0){
            printf("\n");
        }
        if(isfirst==1)
            isfirst=0;
        int s = (line[0]-'0');
        int e = (line[2]-'0');
        output(s,e);
    }
    //printf("\n");
}
//#define _DEBUG
int main(){
    // #ifdef _DEBUG
 	//  freopen("/Users/kyrie/Desktop/input.txt", "r", stdin);
    // #endif
    int n;
    scanf("%d",&n);
    getchar();
    getchar();

    while(n--){
        solve();
    }
    
    return 0;
}