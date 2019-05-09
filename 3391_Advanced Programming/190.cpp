#include<stdio.h>
#include<stack>
#include<string>
#include<iostream>
using namespace std;

int priority(char c){
    if (c == '(')
        return 1;
    else if(c == '+' || c == '-')
        return 2;
    else if(c == '*' || c == '/')
        return 3;

    return -1;
}
bool isOperator(char c){
    if(c =='+' || c=='-'||c=='*'||c=='/')
        return true;
    
    return false;
}

bool isDigit(char c){
    if(c >= '0' && c<='9')
        return true;
    
    return false;
}

int main(){
    stack<char> stk;
    int n;
    scanf("%d",&n);
    getchar();
    getchar();
    for(int i = 0; i < n;i++){
        //count++;
        //if(count > 1) printf("\n");
        //if(i) printf("\n");
        stk.push('#');
        char c;
        int idx = 0;
        while(scanf("%c",&c)!=EOF && c != '\n'){
            getchar();

            if(isDigit(c))
                printf("%c",c);
            else if(c == '(')
                stk.push(c);
            else if(c == ')'){
                while(stk.top() != '#' && stk.top()!='('){
                    printf("%c",stk.top());
                    stk.pop();
                }
                stk.pop();
            }
            else if(isOperator(c)){
                if(stk.top()=='#' || priority(stk.top())< priority(c)){
                    stk.push(c);
                } 
                else
                {
                    while(stk.top() != '#' && priority(stk.top()) >= priority(c)){
                        printf("%c",stk.top());
                        stk.pop();
                    }
                    stk.push(c);
                }
            }
        }

        while(stk.top() != '#'){
            printf("%c",stk.top());
            stk.pop();
        }
        printf("\n");
        if(i != (n-1))
            printf("\n");
    }
    return 0;
}