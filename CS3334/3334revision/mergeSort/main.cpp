#include <iostream>

void merge(int x[], int lower_bound, int mid, int upper_bound){
    int m = mid-lower_bound + 1;
    int n = upper_bound - mid;
    
    int L[m];
    int R[n];
    
    for (int i = 0; i < m; i++) {
        L[i] = x[lower_bound+i];
    }
    
    for (int j = 0; j < n; j++) {
        R[j] = x[mid + 1 + j];
    }
    
    int i = 0;
    int j = 0;
    int k = lower_bound;
    while(i < m && j < n){
        if (L[i] <= R[j]) {
            x[k] = L[i];
            i++;
        }
        else
        {
            x[k] = R[j];
            j++;
        }
        k++;
    }
    
    while(i < m){
        x[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n) {
        x[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r){
    if (l < r) {
        int m = l + (r-l)/2;
        
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        
        merge(arr, l, m, r);
    }
}

void printArr(int arr[], int size){
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(int argc, const char * argv[]) {
    int arr[] = {7,6,4,5,2,3,2,1};
    
    mergeSort(arr, 0, 7);
    printArr(arr, 8);
    return 0;
}

