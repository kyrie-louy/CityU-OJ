#include <iostream>
#include <vector>
using namespace std;

void bucketSort(vector<int> &vec)
{
    int length = vec.size();
    vector<int> buckets(length,0);
    
    for(int i = 0; i < length;i++){
        buckets[vec[i]]++;
    }
    
    int index = 0;
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j<buckets[i]; j++) {
            vec[index++] = i;
        }
    }
}
int main(int argc, const char * argv[]) {
    int a[10] = {0,2,5,6,3,2,5,9,5,2};
    vector<int> vec(a,a+10);
    
    bucketSort(vec);
    for (int i = 0; i < vec.size(); ++i) {
        printf("%d ",vec[i]);
    }
    printf("\n");
    return 0;
}
