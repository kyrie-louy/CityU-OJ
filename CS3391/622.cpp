#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
/*
对 ss 进行后缀排序，重复出现的最长子串一定出现在后缀数组中相邻的两项中,
进一步发现答案就是 heightheight 数组中的最大值.
构造后缀数组和height数组，求出max{height}记为max，
最小的符合要求的子串就是最小的满足 height_i=ans的i对应的sa_i开始的ans个字符。
*/
#define MAX_N 1005

// suffix array
int n, k;
int rak[MAX_N+1];
int tmp[MAX_N+1];

// compare
bool compare_sa(int i, int j){
    if(rak[i] != rak[j]) return rak[i]<rak[j];
    else{
        int ri = i+k <= n ? rak[i+k]:-1;
        int rj = j+k <= n ? rak[j+k]:-1;
        return ri<rj;
    }
}

void construct_sa(string S, int *sa){
    n = S.length();

    for(int i=0;i<=n;i++){
        sa[i] = i;
        rak[i] = i<n?S[i]:-1;
    }

    for (k=1; k<=n; k*=2)
    {
        sort(sa,sa+n+1,compare_sa);

        tmp[sa[0]]=0;
        for(int i=1;i<=n;i++){
            tmp[sa[i]]=tmp[sa[i-1]]+(compare_sa(sa[i-1],sa[i])?1:0);
        }
        for(int i=0; i<=n;i++){
            rak[i] = tmp[i];
        }
    }
    
}

void construct_lcp(string S, int *sa, int *lcp){
    int n = S.length();
    for(int i=0;i<=n;i++) rak[sa[i]]=i;

    int h=0;
    lcp[0]=0;
    for(int i=0;i<n;i++){
        int j=sa[rak[i]-1];

        if(h>0)h--;
        for(;j+h<n && i+h<n;h++){
            if(S[j+h]!=S[i+h]) break;
        }

        lcp[rak[i]-1]=h;
    }
}

void clean(){
    n=0;k=0;
    for(int i=0;i<MAX_N+1;i++){
        rak[i]=0;
        tmp[i]=0;
    }
}
//#define _DEBUG
int main(){
#ifdef  _DEBUG
    freopen("/Users/kyrie/Desktop/input.txt","r",stdin);
#endif

    int t;
    scanf("%d\n",&t);
    while (t--)
    {
        clean();
        string s;
        getline(cin,s);
        int len = s.length();
        
        int *sa = new int[len+1];
        int *lcp = new int[len+1];
        construct_sa(s,sa);
        construct_lcp(s,sa,lcp);
        
        int max=-1;
        for(int i=0;i<len;i++){
            if(lcp[i]>max) max = lcp[i];
        }
        
        if(max==0) printf("No repetitions found!\n");
        else
        {
            int cnt=0;
            int i;
            for(i=0;i<len;i++){
                if(lcp[i]==max){
                    for(int j=0;j<max;j++)
                        printf("%c",s[sa[i]+j]);
                    printf(" ");
                    break;
                }
            }
            for(i;i<=len;i++)if(lcp[i]==max)cnt++; else break;
            printf("%d\n",cnt+1);
        }
        delete[] sa;
        delete[] lcp;
    }  
    return 0;
}