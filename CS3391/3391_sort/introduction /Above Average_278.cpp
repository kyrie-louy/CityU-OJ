#include<stdio.h>
using namespace std;

int main(){
    int grade[1005];
    int n, count, num;
    double sum, avg;
    scanf("%d",&n);
    for(int i = 0; i< n;i++){
        sum = 0;
        count = 0;
        scanf("%d",&num);

        for(int j = 0;j < num;j++){
            scanf("%d", &grade[j]);
            sum += grade[j];
        }

        avg = sum/num;

        for(int j = 0; j< num; j++){
            if(grade[j] > avg)
                count++;
        }

        printf("%.3f%%\n",(double)100*count/num);
    }
    return 0;
}