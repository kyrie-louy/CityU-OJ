#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stack>
using namespace std;

//#define _DEBUG
int main(){
    // #ifdef _DEBUG
 	//   freopen("/Users/kyrie/Desktop/input.txt", "r", stdin);
    // #endif
    int n;
    char s[130];
    scanf("%d",&n);
    getchar();


    while(n--){
        stack<char> stk;
        gets(s);
        //printf("!!!%s\n",s);
        int len = strlen(s);
        if(len == 0){
            printf("Yes\n");
            continue;
        }

        bool is_wrong = 1;
        for(int i =0;i<len;i++){
            if(s[i] == '(' || s[i] == '[')
                    stk.push(s[i]);
            else{
                if(!stk.empty()){
                    if(s[i]==')'){
                        if(stk.top() !='('){
                            is_wrong = 0;
                            break;
                        }
                        stk.pop();
                    }
                    else if(s[i]==']'){
                        if(stk.top()!='['){
                            is_wrong = 0;
                            break;
                        }
                        stk.pop();
                    }
                }
                else{
                    is_wrong = 0;
                    break;
                }
            }
        }

        if(!is_wrong)
            printf("No\n");
        else
        {
            if(stk.empty())
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    
    return 0;
}