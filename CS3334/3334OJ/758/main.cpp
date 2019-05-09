#include <iostream>
using namespace std;


int bucket[1024];

int maxbit(int arr[], int n) {
    int d = 0;
    int max = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    
    while (max >= 1) {
        d++;
        max /= 1024;
    }
    
    return d;
}

void radixSort(int arr[], int n) {
    int *tmp = new int[n];
    int d = maxbit(arr, n);
    int r = 1;
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < 1024; j++)
            bucket[j] = 0;
        
        /*cout << "bucket:" << endl;
         for (int j = 0; j < 10; j++) {
         cout << bucket[j] << " ";
         }
         cout << endl;*/
        
        for (int j = 0; j < n; j++) {
            int k = arr[j] / r;
            int q = k % 1024;
            bucket[q]++;
        }
        
        for (int j = 1; j < 1024; j++)
            bucket[j] += bucket[j - 1];
        
        for (int j = n - 1; j >= 0; j--) {
            int p = arr[j] / r;
            int s = p % 1024;
            bucket[s]--;
            tmp[bucket[s]] = arr[j];
        }
        
        for (int j = 0; j < n; j++) {
            arr[j] = tmp[j];
        }
        
        r *= 1024;
    }
    delete[] tmp;
}
int main() {
    int* arr = new int[5000000];
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        
        arr[0] = 1;
        arr[1] = 1;
        
        for (int i = 2; i < n; i++) {
            arr[i] = (arr[i - 1] + arr[i - 2]) % m;
        }
        
        /*for (int i = 0; i < n; i++) {
         cout << arr[i] << " ";
         }
         cout << endl;*/
        radixSort(arr, n);
        /*for (int i = 0; i < n; i++) {
         cout << arr[i] << " ";
         }
         cout << endl;*/
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum = (sum + ((i + 1)*(long long)arr[i]) % m) % m;
        }
        cout << sum << endl;
    }
    delete[] arr;
    
    return 0;
}
