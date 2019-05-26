#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cmath>
using namespace std;

/*
题目：判断两个二进制字符串是否互质
分析：字符串长度最大30，直接转换成int再用gcd判断就好了
*/
char L1[31];
char L2[31];

int binToDec(char* a){
    int len = strlen(a);

    int exp = 0, sum = 0;
    for(int i=len-1;i>=0;i--){
        sum += ((int)(a[i]-'0')*pow(2,exp));
        exp++;
    }
    return sum;
}

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

//#define _DEBUG
int main(){
#ifdef _DEBUG
    freopen("/Users/kyrie/Desktop/input.txt","r",stdin);
#endif

    int n;
    scanf("%d\n",&n);
    for(int i=1;i<=n;i++){
        printf("Pair #%d: ",i);
        scanf("%s\n",L1);
        scanf("%s\n",L2);

        int num1 = binToDec(L1);
        int num2 = binToDec(L2);
        //printf("%d\n",gcd(23,27));
        if(gcd(num1,num2)==1) printf("Love is not all you need!\n");
        else printf("All you need is love!\n");
    }
    return 0;
}