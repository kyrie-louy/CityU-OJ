#include<stdio.h>
using namespace std;

int addDigit(int num){
    int sum = 0;
    int temp;
    for(int i = 1; i<= 4;i++){
        if(i%2 == 1){
            sum += (num%10);
            num /= 10;
        }
        else
        {
            temp = (num%10)*2;
            if(temp >= 10)
                sum += ((temp%10)+1);
            else
                sum += temp;

            num /= 10;
        }
    }

    return sum;
}

int main(){
    int n;
    scanf("%d",&n);

    for(int i = 0; i< n; i++){
        int fis,sec,thi,fou;
        scanf("%d%d%d%d",&fis,&sec,&thi,&fou);

        int total = addDigit(fis)+addDigit(sec)+addDigit(thi)+addDigit(fou);
        if(total%10 == 0)
            printf("%s\n","Valid");
        else
            printf("%s\n","Invalid");

    }
    return 0;
}