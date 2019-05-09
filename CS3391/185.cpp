#include <stdio.h>
#include <iostream>
#include <sstream>
#include <set>
#include <string>
using namespace std;

//#define _DEBUG
int main(){
#ifdef  _DEBUG
    freopen("/Users/kyrie/Desktop/input.txt","r",stdin);
#endif
    set<string> s;
    stringstream ss;
    string line, tmp;
    while (getline(cin,line))
    {
        for(int i=0;i<line.size();i++){
            if(isalpha(line[i])){
                if(!islower(line[i]))
                    line[i] += 32;
            }
            else
                line[i] = ' ';
        }
        ss.clear();
        ss.str(line);
        while (1)
        {
            ss>>tmp;
            s.insert(tmp);
            if(ss.fail()) break;
        }     
    }
    set<string>::iterator it;
    for(it = s.begin();it!=s.end();it++){
        cout<<*it<<endl;
    }
    return 0;
}