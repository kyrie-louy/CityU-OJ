#include<stdio.h>
#include<string.h>
#include<stack>
#include<iostream>
using namespace std;
// string hexArr[] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
string resHex = "";
int i = 0;
int hexToDec(char c){
    if(c >= '0' && c <= '9')
        return c-'0';
    else
        return (c-'A'+10);
}

void decToHex(int d){
    if(d < 16){
        if(d <10)
            resHex += (d+'0');
        else
            resHex += (d + 'A'-10);
    }
    else{
        decToHex(d/16);

        i++;
        d %= 16;
        if(d <10)
            resHex += (d+'0');
        else
            resHex += (d + 'A'-10);
    }
}

int getPriority(char c){
    if(c == '*')
        return 2;
    else if(c == '+')
        return 1;
    
    return -1;
}

int computer(char oprator, int operand1, int operand2){
    switch(oprator){
        case '+':   return (operand1+operand2);
        case '*':   return (operand1*operand2);
    }
    return -1;
}

// check
bool isHex(char c){
    if((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F'))
        return true;
    
    return false;
}

bool isOp(char c){
    if(c == '+' || c == '*')
        return true;
    
    return false;
} 

int main(){
    char s[105];
    while(scanf("%s",s)!=EOF){
        resHex = "";
        i = 0;
        int res = 0;
        stack<char> optor;
        stack<int> oprad;
        for(int i = 0; i< strlen(s);i++){
            char c = s[i];
            if(c == '(')
               optor.push('(');
            else if(c == ')')
            {
                while(!optor.empty() && optor.top() != '('){
                    int op1 = oprad.top();
                    oprad.pop();
                    int op2 = oprad.top();
                    oprad.pop();

                    char op = optor.top();
                    optor.pop();
                    oprad.push(computer(op,op1,op2));                   
                }
                optor.pop();
            }
            else if(isHex(c))
                oprad.push(hexToDec(c));
            else if(isOp(c)){
                if(optor.empty())
                    optor.push(c);
                else if(getPriority(c) > getPriority(optor.top()))
                    optor.push(c);
                else if(getPriority(c) <= getPriority(optor.top())){
                    while(!optor.empty() && getPriority(c) < getPriority(optor.top())){
                        int op1 = oprad.top();
                        oprad.pop();
                        int op2 = oprad.top();
                        oprad.pop();

                        char op = optor.top();
                        optor.pop();
                        oprad.push(computer(op,op1,op2));
                    }
                    optor.push(c);
                }
            }
        }
        while(!optor.empty() && !oprad.empty()){
            int op1 = oprad.top();
            oprad.pop();
            int op2 = oprad.top();
            oprad.pop();

            char op = optor.top();
            optor.pop();
            oprad.push(computer(op,op1,op2));
        }
        decToHex(oprad.top());
        cout<<resHex<<endl;

    }
}