#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

string line;

int len;
bool check(int pos){
    if(pos>=len) return 1;
    
    return ((line[pos]=='1'&&check(pos+1)) || (line[pos]=='1'&&line[pos+1]=='4'&&check(pos+2)) || (line[pos]=='1'&&line[pos+1]=='4'&&line[pos+2]=='4'&&check(pos+3)));
}

#define _DEBUG
int main(){
#ifdef _DEBUG
    freopen("/Users/kyrie/Desktop/input.txt","r",stdin);
#endif
    while (getline(cin,line))
    {
        int len = line.size();

        if(check(0)) printf("YES\n");
        else printf("NO\n");
    }
    
    return 0;
}