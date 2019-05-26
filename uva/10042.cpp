#include <stdio.h>
#include <string.h>
using namespace std;

/*
这是一道常规素数判定的题目
题目：一个数如果位和（所有位上的数字之和）与这个数的分解出的素数的位和之和相等，就叫做smith数。
    给你一个数，求出超过他的最近的smith数。

补充关于素数判定：
如果需判定的数最大为n，只需得到“前根号n”个素数即可判断
（flag数组开到"根号n", prime数组可以通过count直接试出来）
*/

bool flag[32000];
int prime[3500];
int count;

void getprime(int l){
    int i, j;
    memset(flag,1,sizeof(flag));
    count = 0;
    for(i=2;i<=l;i++){
        if(flag[i]==true)
            prime[++count]=i;
        for(j=1;j<=count&&i*prime[j]<l;j++){
            flag[i*prime[j]]=false;
            if(i%prime[j]==0)break;
        }
    }
}

int digit_sum(int num){
    int sum = 0;
    while (num>=1)
    {
        sum += num%10;
        num /= 10;
    }
    return sum;
}

int prime_sum(int num){
    int i = 1, sum=0;
    while (i<count && prime[i]<=num)
    {
        while (num%prime[i]==0)
        {
            sum += digit_sum(prime[i]);
            num /= prime[i];
        }
        i++;
    }
    if(num!=1){
        sum += digit_sum(num);
    }
    return sum;
}

bool is_prime(int num){
    int i = 1;

    while (i<count && prime[i] < num)   // ！！！这个地方不能用小于等于（素数可以被自己除）
    {
        if(num % prime[i]==0)
            return 0;
        i++;
    }
    return true;
}

bool is_smith(int num){
    if(digit_sum(num) == prime_sum(num))
        return true;
    else return false;
}

int next_smith(int s){
    for(int i=s+1;i<2e9;i++){
        if(is_prime(i)) continue;
        else
        {
            if(is_smith(i)) return i;
        }
        
    }
    return -1;
}

//#define _DEBUG
int main(){
#ifdef _DEBUG
    freopen("/Users/kyrie/Desktop/input.txt","r",stdin);
#endif

    getprime(32000);
    //printf("%d\n",prime[1]);
    int n;
    scanf("%d",&n);

    while (n--)
    {
        int num;
        scanf("%d",&num);
        printf("%d\n",next_smith(num));
    }
    return 0;
}