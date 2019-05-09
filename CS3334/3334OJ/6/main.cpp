#include<stdio.h>
#include <cstring>
using namespace std;

const int max = 100000 + 10;

int arr[max], mod[max];
int c, n, sum;

int main(){
    while (~scanf("%d%d", &c, &n)) {
        if (c == 0 && n == 0) {
            return 0;
        }
        
        sum = 0;
        
        for (int i = 1; i <= n; i++) {
            scanf("%d", &arr[i]);
        }
        
        for (int i = 0; i < c; i++) {
            mod[i] = -1;
        }
    
        for (int i = 1; i <= n; i++) {
            sum = (sum + arr[i]) % c;
            
            if (sum == 0) {
                for (int j = 1; j < i;  j++) {
                    printf("%d ", j);
                }
                printf("%d\n", i);
                break;
            }
            
            if (mod[sum] != -1) {
                for (int j = mod[sum] + 1; j < i; j++) {
                    printf("%d ", j);
                }
                printf("%d\n", i);
                break;
            }
            
            mod[sum] = i;
        }
    }
    return 0;
}
