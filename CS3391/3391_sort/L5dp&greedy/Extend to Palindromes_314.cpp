#include<stdio.h>
#include<string.h>
using namespace std;

char s1[100005];
char s2[100005];
int next[100005];

void getNextVal(char *p){
    int pLen = strlen(p);
	next[0] = -1;
	int k = -1;
	int j = 0;
	while (j < pLen - 1)
	{
		if (k == -1 || p[j] == p[k])
		{
			++j;
			++k;
			if (p[j] != p[k])
				next[j] = k; 
			else
				next[j] = next[k];
		}
		else
		{
			k = next[k];
		}
	}
}

void KmpSearch(char* s, char* p)
{
	int i = 0;
	int j = 0;
	int sLen = strlen(s);
	int pLen = strlen(p);
	while (i < sLen && j < pLen)
	{  
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{   
			j = next[j];
		}
	}
	printf("%s%s\n",s1,&s2[j]);
}

int main(){
    while(gets(s1)){
        int len = strlen(s1);
        for(int i= 0;i<len;i++){
            s2[i] = s1[len-1-i];
        }
        s2[len] = '\0';
        getNextVal(s2);
        KmpSearch(s1,s2);
    }

    return 0;
}