#include <iostream>
using namespace std;

struct node{
    int index;
    int discount;
    int originalPrice;
    int discountPrice;
};

node* discountRank = new node[105];

int main() {
    int n;
    int totalConsume;
    int result;
    while (~scanf("%d", &n)) {
        totalConsume = 0;
        result = 0;
        for (int i = 0; i < n; i++) {
            int op, dp;
            scanf("%d %d", &op, &dp);
            discountRank[i] = {i, op-dp, op, dp};
            totalConsume += op;
        }
        
        if (totalConsume < 100) {
            printf("%d\n", totalConsume);
            continue;
        }
        
        
        for (int i = 0; i < n; i++) {
            for (int j = i -1; j >= 0 ; j--) {
                if (discountRank[j].discount < discountRank[j+1].discount) {
                    swap(discountRank[j], discountRank[j+1]);
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (i < n/2) {
                result += discountRank[i].discountPrice;
            }
            else{
                result += discountRank[i].originalPrice;
            }
        }
        
        printf("%d\n", result);
    }
    return 0;
}
