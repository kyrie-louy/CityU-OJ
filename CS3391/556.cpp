#include <stdio.h>
#include <iostream>
#include <stack>
#include <string.h>

using namespace std;
#define MAX 101
char postfix[MAX];
string input;

int getWeight(char c){
    if(c=='!') return 3;
    else if(c=='&') return 2;
    else if(c=='+') return 1;
    else if(c=='(') return 0;
}

bool isOperand(char c){
    if(c>='a' && c<='z') return 1;
    return 0;
}

int intopost(char postfix[MAX],int len){
    //cout<<"len: "<<len<<endl;
    //cout<<postfix<<endl;
    int idx = 0;
    int calLen = 0;
    stack<char> s;
    while (!s.empty())
    {
        s.pop();
    }
    
    for(int i=0;i<len;i++){
        char c = input[i];
        //cout<<c<<" ";
        if(c ==' ') continue;
        else if(isOperand(c)) postfix[idx++] =c,calLen++;
        else if (c =='(') s.push('(');
        else if (c==')'){
            while (!s.empty() && s.top() != '(')
            {
                char tmp = s.top();
                s.pop();
                postfix[idx++]=tmp;
            }
            if(s.top()=='(') s.pop();
            
        }
        else if(c=='!' || c=='&' || c=='+'){
            while (!s.empty() && getWeight(s.top())>=getWeight(c))
            {
                char tmp = s.top();
                s.pop();
                postfix[idx++] = tmp;
            }
            s.push(c);
            calLen++;
        }
    }
    //cout<<endl;

    while (!s.empty())
    {
        char tmp = s.top();
        //cout<<tmp<<" ";
        s.pop();
        postfix[idx++] = tmp;
    }
    //cout<<endl;
    //cout<<postfix<<endl;
    return calLen;
}

void compute(int len){
    stack<char> res;
    for(int i=0;i<len;i++){
        //printf("%c",postfix[i]);
        char c = postfix[i];

        if(isOperand(c)) res.push('T');
        else
        {
            if(c=='!'){
                char t = res.top();
                res.pop();
                if(t=='T') res.push('F');
                else res.push('T');
            }
            else if(c=='&'){
                char t1 =res.top();
                res.pop();
                char t2 = res.top();
                res.pop();
                if(t1=='T' && t2=='T'){
                    res.push('T');
                }
                else res.push('F');
            }
            else if(c=='+'){
                char t1 =res.top();
                res.pop();
                char t2 = res.top();
                res.pop();
                if(t1=='T' || t2=='T') res.push('T');
                else res.push('F');
            }
        }
        
    }
    if(res.top()=='T')
        printf("YES\n");
    else printf("NO\n");
    //printf("\n");
}
//#define _DEBUG
int main(){
#ifdef _DEBUG
	freopen("/Users/kyrie/Desktop/input.txt", "r", stdin);
#endif

    while (getline(cin,input))
    {
        //cout<<"input: "<<input<<endl;
        int len1 = input.size();
        int len2 = intopost(postfix,len1);
        compute(len2);
    }
    

    return 0;
}