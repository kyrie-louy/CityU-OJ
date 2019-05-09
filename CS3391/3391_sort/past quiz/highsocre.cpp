#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char s[1005];
int main(){
    int n;
    scanf("%d",&n);
    getchar();

    while(n--){
        scanf("%s",s);
        getchar();

        int len = strlen(s);
        //printf("%s %d\n",s,len);

        int sum = 0;
        for(int i=0;i<len;i++){
            sum += (min(s[i]-'A','Z'-s[i]+1));
        }
        int total = sum+len-1;

        //printf("%d\n",total);
        for(int i = 1; i < len; i++)
        {
            int j;
            if(s[i]=='A'){
                for(j=i+1;j<len&&s[j]=='A';j++);

                total = min(total,sum+min(2*(i-1)+(len-j),2*(len-j)+(i-1)));
            }
        }

        printf("%d\n",total);
    }
    
    return 0;
}