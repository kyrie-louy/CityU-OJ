#include <iostream>
int count = 0;
void partition(int x[], int idLeftMost, int idRightMost, int *pj){
    int down, up,a,temp;
    a = x[idLeftMost];
    down = idLeftMost;
    up = idRightMost;
    
    // 左右位置不对的，不断进行交换
    while (down < up) {
        while ((x[down] <= a) && (down < idRightMost)) {
            down++;
        }
        
        while (x[up] > a) {
            up--;
        }
//        if(down >= up){
//            up++;
//        }
        if (up > down) {
            temp = x[down];
            x[down] = x[up];
            x[up] = temp;
            count++;
            printf("%d %d\n",down,up);
        }
    
    }
    
    // 换到隔的位置来
    x[idLeftMost] = x[up];
    x[up] = a;
    *pj = up;
    count++;
    printf("%d %d\n",idLeftMost,up);
}

void quick_sort(int x[], int idLeftmost, int idRightmost){
    int j;
    
    if(idLeftmost >= idRightmost)
        return;
    
    partition(x, idLeftmost, idRightmost, &j);
    
    quick_sort(x, idLeftmost, j-1);
    quick_sort(x, j+1, idRightmost);
}

void printArr(int x[], int size){
    for (int i = 0; i < size; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {2,1,4,3,5,6};
    
    quick_sort(arr, 0, 5);
    printArr(arr, 6);
    std::cout<<count<<std::endl;
    return 0;
}
