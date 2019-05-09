#include<stdio.h>
#include<cmath>
using namespace std;
int instr[35];

int binToDec(int b){
    int res = 0, j = 0, reminder;
    while(b != 0){
        reminder = b%10;
        b /= 10;
        res += reminder*(1<<j);
        j++;
    }
    return res;
}

int decToBin(int dec){
    int result = 0,temp = dec,j = 1;
	while(temp){
		result += j*(temp%2);
		temp = temp/2;
		j *= 10;
	}
	return result;
}

int coStart(){
    unsigned char ac = 0, pc = 0;
    while((instr[pc]>>5)!= 7){
        int ins = instr[pc];
        int op = ins>>5;
        int x = ins&31;
        pc = (pc+1)%32;
        switch(op){
            case 0:instr[x] = ac;break;
            case 1:ac = instr[x];break;
            case 2:if(ac == 0) pc = x;break;
            case 3: break;
            case 4: ac = ac-1u;break;
            case 5: ac = ac+1u;break;
            case 6: pc = x;break;  
        }
    }
    return ac;
}

int main(){
    int n;
    int idx = 0;
    while(scanf("%d",&n)!= EOF){
        instr[idx++] = binToDec(n);
        if(idx%32 == 0 && idx!= 0){
            printf("%08d\n",decToBin(coStart()));
            idx = 0;
        }
    }    
    return 0;
}