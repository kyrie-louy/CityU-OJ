#include<stdio.h>
#include<string.h>
using namespace std;

char word[105];
int count;
int longest = -1;
char lg[105];

bool isLower(char c){
    if(c>='a' && c<='z')
        return true;
    
    return false;
}

bool isUpper(char c){
    if(c>='A' && c<='Z')
        return true;
    
    return false;
}

bool isValid(char c){
    if(isUpper(c) || isLower(c) || c=='-')
        return true;
    
    return false;
}

int main(){
    
    while(scanf("%s",word)!=EOF && strcmp(word,"E-N-D")){
        count = 0;
        int len = strlen(word);

        for(int i = 0;i<len;i++){
            if(isValid(word[i])){
                count++;
            }
        }

        if(count > longest){
            longest = count;
            strcpy(lg,word);
        }
    }

    for(int i = 0;i<strlen(lg);i++){
        if(!isValid(lg[i]))
            continue;

        if(isUpper(lg[i])){
            lg[i] = (char)(lg[i]+32);
        }
        printf("%c",lg[i]);
    }
    printf("\n");
    return 0;
}