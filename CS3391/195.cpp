#include<iostream>
#include<string>
using namespace std;
string str;
int flag;
bool dfs(int s, int e){
    if(e == s && str[s] == 'A') return true;
    else if(str[e-1]=='A' && str[e]=='B') return dfs(s,e-2);
    else if(str[s] == 'B' && str[e]=='A') return dfs(s+1,e-1);
    else return false;
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;

    while(n--){
        flag = 0;
        cin>>str;
        if(str == "A"){
            cout<<"SIMPLE"<<endl;
            flag = 1;
        }
        else{
            if(str[str.length()-1] == 'B' && str[str.length()-2] == 'A'){
                if(dfs(0,str.length()-3)){
                    cout<<"FULLY-GROWN"<<endl;
                    flag = 1;
                }
            }
            else if(str[0] == 'B' && str[str.length()-1] == 'A'){
                if(dfs(1,str.length()-2)){
                    cout<<"MUTAGENIC"<<endl;
                    flag = 1;
                }
            }
        }

        if(!flag)
            cout<<"MUTANT"<<endl;
    }
    return 0;
}
